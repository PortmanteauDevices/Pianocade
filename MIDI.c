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
static uint8_t _omni = 1;

static void _MIDI_send(uint8_t MIDICommand, uint8_t MIDIPitch, uint8_t velocity){
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

void MIDI_noteOn(unsigned char note){
    _MIDI_send(MIDI_STATUS_NOTEON | MIDICHANNEL, note, MIDI_DEFAULT_VELOCITY);
}

void MIDI_noteOff(unsigned char note){
    _MIDI_send(MIDI_STATUS_NOTEOFF | MIDICHANNEL, note, MIDI_DEFAULT_VELOCITY);
}

static void MIDI_processUSB(void){
    MIDI_Device_USBTask(&Keyboard_MIDI_Interface);
    USB_USBTask();

    MIDI_EventPacket_t ReceivedMIDIEvent;
    while (MIDI_Device_ReceiveEventPacket(&Keyboard_MIDI_Interface, &ReceivedMIDIEvent)){
        unsigned char midiCommand = (ReceivedMIDIEvent.Command << 4);
        // For anything other than SysEx messages, the following statement should be true
        if(midiCommand != (ReceivedMIDIEvent.Data1 & MIDI_COMMAND_MASK)) continue;
        unsigned char channel = (ReceivedMIDIEvent.Data1 & MIDI_CHANNEL_MASK);
        if(ReceivedMIDIEvent.CableNumber == MIDICABLE){
            if(midiCommand == MIDI_STATUS_NOTEON ||
            midiCommand == MIDI_STATUS_NOTEOFF ||
            midiCommand == MIDI_STATUS_CONTROLCHANGE){
                _processMIDIpacket(midiCommand, channel, ReceivedMIDIEvent.Data2, ReceivedMIDIEvent.Data3);
            }
        }
    }
}

static void MIDI_processSerial(void){
    if(SerialAvailable()){
        unsigned char rawCommand = SerialRead();
        unsigned char midiCommand = (rawCommand & MIDI_COMMAND_MASK);
        unsigned char channel = (rawCommand & MIDI_CHANNEL_MASK);
        if(midiCommand == MIDI_STATUS_NOTEON ||
         midiCommand == MIDI_STATUS_NOTEOFF ||
         midiCommand == MIDI_STATUS_CONTROLCHANGE){
            while(!SerialAvailable()) {};
            unsigned char data1 = SerialRead();
            while(!SerialAvailable()) {};
            unsigned char data2 = SerialRead();

            _processMIDIpacket(midiCommand, channel, data1, data2);
        }
    }
}

void MIDI_processInput(void){
    MIDI_processUSB();
    MIDI_processSerial();
}

static void _noteOn(unsigned char channel, unsigned char note){
    if(_omni || channel == MIDICHANNEL){
        midi_notes[note/12] |= (1 << (note % 12));
        midi_changed = 1;
        midi_new = !midi_hasnotes;
        midi_hasnotes = 1;
    }
}

static void _noteOff(unsigned char channel, unsigned char note){
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

static void _controlChange(unsigned char channel, unsigned char data1, unsigned char data2){
    if(channel == MIDICHANNEL && data1 > 119){
        // Turn off all notes
        memset(midi_notes, 0, 20);
        midi_changed = 1;
        midi_hasnotes = 0;
        midi_new = 0;
    }
}

static void _processMIDIpacket(unsigned char midiCommand, 
                               unsigned char channel,
                               unsigned char data1,
                               unsigned char data2){
    if(midiCommand == MIDI_STATUS_NOTEON){
        if(data2){
            _noteOn(channel, data1);
        } else {
            _noteOff(channel, data1);
        }
    } else if(midiCommand == MIDI_STATUS_NOTEOFF){
        _noteOff(channel, data1);
    } else if(midiCommand == MIDI_STATUS_CONTROLCHANGE){
        _controlChange(channel, data1, data2);
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

void MIDI_initialize(void){
    USBSetupHardware();
    SerialBegin();
}