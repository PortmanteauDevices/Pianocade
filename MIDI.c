#include "MIDI.h"

USB_ClassInfo_MIDI_Device_t Keyboard_MIDI_Interface =
    {
        .Config =
            {
                .StreamingInterfaceNumber = 1,

                .DataINEndpointNumber      = MIDI_STREAM_IN_EPNUM,
                .DataINEndpointSize        = MIDI_STREAM_EPSIZE,
                .DataINEndpointDoubleBank  = false,

                .DataOUTEndpointNumber     = MIDI_STREAM_OUT_EPNUM,
                .DataOUTEndpointSize       = MIDI_STREAM_EPSIZE,
                .DataOUTEndpointDoubleBank = false,
            },
    };

uint16_t midi_notes[10] = {0,0,0,0,0,0,0,0,0,0};
uint8_t midi_changed = 0;
uint8_t midi_new = 0;
uint8_t midi_hasnotes = 0;
int8_t midi_bend_step = 0;
uint8_t midi_arp_output = 1; // Whether or not to output arpeggiated notes
uint8_t midi_local_control = 1;

static uint8_t _cached_arp_output = 1;
static uint8_t _omni = 1;
static unsigned char _runningStatus = 0;

static inline void _tx(uint8_t MIDICommand, uint8_t MIDIPitch, uint8_t velocity){
    SerialPrint(MIDICommand);
    SerialPrint(MIDIPitch);
    SerialPrint(velocity);

    MIDI_EventPacket_t MIDIEvent = (MIDI_EventPacket_t){
        .CableNumber = 0,
        .Command     = (MIDICommand >> 4),

        .Data1       = MIDICommand | MIDICHANNEL,
        .Data2       = MIDIPitch,
        .Data3       = velocity,
    };

    MIDI_Device_SendEventPacket(&Keyboard_MIDI_Interface, &MIDIEvent);
    MIDI_Device_Flush(&Keyboard_MIDI_Interface);
}

void MIDI_tx_noteOn(unsigned char note){
    _tx(MIDI_STATUS_NOTEON | MIDICHANNEL, note, MIDI_DEFAULT_VELOCITY);
}

void MIDI_tx_noteOff(unsigned char note){
    _tx(MIDI_STATUS_NOTEOFF | MIDICHANNEL, note, MIDI_DEFAULT_VELOCITY);
}

static inline void _rx_USB(void){
    MIDI_Device_USBTask(&Keyboard_MIDI_Interface);
    USB_USBTask();

    MIDI_EventPacket_t ReceivedMIDIEvent;
    while (MIDI_Device_ReceiveEventPacket(&Keyboard_MIDI_Interface, &ReceivedMIDIEvent)){
        unsigned char midiCommand = (ReceivedMIDIEvent.Command << 4);
        // For anything other than SysEx messages, the following statement should be true
        if(midiCommand != (ReceivedMIDIEvent.Data1 & MIDI_COMMAND_MASK)) continue;
        unsigned char channel = (ReceivedMIDIEvent.Data1 & MIDI_CHANNEL_MASK);
        if(ReceivedMIDIEvent.CableNumber == MIDICABLE){
            _rx_processMIDIpacket(midiCommand, channel, ReceivedMIDIEvent.Data2, ReceivedMIDIEvent.Data3);
        }
    }
}

static inline void _rx_Serial(void){
    if(SerialAvailable()){
        // Check if the received byte is a valid MIDI status message
        // i.e. the MSB is set
        if(SerialPeek() >> 7){
            // If it is a valid status message, read the byte and set the running status
            // NOTE: for commands that clear the running status, it is up to that command's
            // method to set _runningStatus to 0
            _runningStatus = SerialRead();
        }

        unsigned char midiCommand = (_runningStatus & MIDI_COMMAND_MASK);
        unsigned char channel = (_runningStatus & MIDI_CHANNEL_MASK);
        if(midiCommand == MIDI_STATUS_NOTEON){
            while(!SerialAvailable()) {};
            unsigned char note = SerialRead();
            while(!SerialAvailable()) {};
            unsigned char velocity = SerialRead();
            if(velocity){
                _rx_noteOn(channel, note);
            } else {
                _rx_noteOff(channel, note);
            }
        } else if(midiCommand == MIDI_STATUS_NOTEOFF){
            while(!SerialAvailable()) {};
            unsigned char note = SerialRead();
            while(!SerialAvailable()) {};
            unsigned char velocity = SerialRead();
            _rx_noteOff(channel, note);
        } else if(midiCommand == MIDI_STATUS_PITCHWHEEL){
            while(!SerialAvailable()) {};
            unsigned char lsb = SerialRead();
            while(!SerialAvailable()) {};
            unsigned char msb = SerialRead();
            _rx_pitchWheel(channel, lsb, msb);
        } else if(midiCommand == MIDI_STATUS_CONTROLCHANGE){
            while(!SerialAvailable()) {};
            unsigned char number = SerialRead();
            while(!SerialAvailable()) {};
            unsigned char value = SerialRead();
            _rx_controlChange(channel, number, value);
        } else if(midiCommand == 0xF0) {
            // This is a system common message, so the running status is cleared
            _runningStatus = 0;
        } else if(midiCommand == 0) {
            // The only way this can happen is if an invalid data byte has been
            // sent, so the byte is discarded
            SerialRead();
        } else {
            // Unsupported command
            SerialRead();
        }
    }
}

void MIDI_rx(void){
    _rx_USB();
    _rx_Serial();
}

static inline void _rx_noteOn(unsigned char channel, unsigned char note){
    if(_omni || channel == MIDICHANNEL){
        midi_notes[note/12] |= (1 << (note % 12));
        midi_changed = 1;
        midi_new = !midi_hasnotes;
        midi_hasnotes = 1;
    }
}

static inline void _rx_noteOff(unsigned char channel, unsigned char note){
    if(_omni || channel == MIDICHANNEL){
        midi_notes[note/12] &= ~(1 << (note % 12));
        midi_changed = 1;
        midi_hasnotes = 0;
        midi_new = 0;
        for(int octave_count = 0; octave_count < 10; ++octave_count){
            if(midi_notes[octave_count]){
                midi_hasnotes = 1;
                break;
            }
        }
    }
}

static inline void _rx_pitchWheel(unsigned char channel, unsigned char lsb, unsigned char msb){
    if(_omni || channel == MIDICHANNEL){
        midi_bend_step = 0x40 - msb;
    }
}

static inline void _rx_controlChange(unsigned char channel, unsigned char data1, unsigned char data2){
    if(channel == MIDICHANNEL && data1 > 119){
        // Turn off all notes
        memset(midi_notes, 0, 20);
        midi_changed = 1;
        midi_hasnotes = 0;
        midi_new = 0;
        if(data1 == 121){
            // Reset all controllers
            midi_bend_step = 0;
        } else if (data1 == 122){
            // Local control
            if(data2 > 63){
                midi_local_control = 1;
                midi_arp_output = _cached_arp_output;
            } else {
                midi_local_control = 0;
                _cached_arp_output = midi_arp_output;
                midi_arp_output = 0;
            }
        } else if (data1 == 124){
            // Omni mode off
            _omni = 0;
        } else if (data1 == 125){
            // Omni mode on
            _omni = 1;
        } else if (data1 == 126){
            // Mono operation
            midi_arp_output = 1;
            _cached_arp_output = 1;
        } else if (data1 == 127){
            // Poly operation
            midi_arp_output = 0;
            _cached_arp_output = 0;
        }
    }
}

static inline void _rx_processMIDIpacket(unsigned char midiCommand, 
                               unsigned char channel,
                               unsigned char data1,
                               unsigned char data2){
    if(midiCommand == MIDI_STATUS_NOTEON){
        if(data2){
            _rx_noteOn(channel, data1);
        } else {
            _rx_noteOff(channel, data1);
        }
    } else if(midiCommand == MIDI_STATUS_NOTEOFF){
        _rx_noteOff(channel, data1);
    } else if(midiCommand == MIDI_STATUS_PITCHWHEEL){
        _rx_pitchWheel(channel, data1, data2);
    } else if(midiCommand == MIDI_STATUS_CONTROLCHANGE){
        _rx_controlChange(channel, data1, data2);
    }

}

void USBSetupHardware(void)
{
    /* Disable watchdog if enabled by bootloader/fuses */
    MCUSR &= ~(1 << WDRF);
    // wdt_disable();

    /* Disable clock division */
    //clock_prescale_set(clock_div_1);

    /* Hardware Initialization */
    USB_Init();
}

/** Event handler for the library USB Connection event. */
void EVENT_USB_Device_Connect(void)
{
}

/** Event handler for the library USB Disconnection event. */
void EVENT_USB_Device_Disconnect(void)
{
}

/** Event handler for the library USB Configuration Changed event. */
void EVENT_USB_Device_ConfigurationChanged(void)
{
    bool ConfigSuccess = true;

    ConfigSuccess &= MIDI_Device_ConfigureEndpoints(&Keyboard_MIDI_Interface);
}

/** Event handler for the library USB Control Request reception event. */
void EVENT_USB_Device_ControlRequest(void)
{
    MIDI_Device_ProcessControlRequest(&Keyboard_MIDI_Interface);
}

void MIDI_init(void){
    USBSetupHardware();
    SerialBegin();
}