#include "MIDI.h"

USB_ClassInfo_MIDI_Device_t Keyboard_MIDI_Interface =
	{
		.Config =
			{
				.StreamingInterfaceNumber = 1,
				.DataINEndpoint           =
					{
						.Address          = MIDI_STREAM_IN_EPADDR,
						.Size             = MIDI_STREAM_EPSIZE,
						.Banks            = 1,
					},
				.DataOUTEndpoint           =
					{
						.Address          = MIDI_STREAM_OUT_EPADDR,
						.Size             = MIDI_STREAM_EPSIZE,
						.Banks            = 1,
					},
			},
	};

uint16_t midi_notes[OCTAVE_TOTAL] = {0};
uint8_t midi_changed = 0;
uint8_t midi_new = 0;
uint8_t midi_hasnotes = 0;
int8_t midi_bend_step = 0;
uint8_t midi_arp_output = 1; // Whether or not to output arpeggiated notes
uint8_t midi_local_control = 1;
uint8_t midi_velocity = MIDI_DEFAULT_VELOCITY;

uint8_t midi_tick = 0;
uint8_t midi_clock_flag = 0;
uint8_t midi_tempo = 6;

uint8_t midi_sysex_buffer[MIDI_SYSEX_BUFFER_SIZE] = {0};
uint8_t midi_sysex_buffer_pointer = 0;
uint8_t midi_sysex_flag = false;

static uint8_t _cached_arp_output = 1;
static uint8_t _omni = 1;
static unsigned char _runningStatus = 0;

static inline void _tx(uint8_t MIDICommand, uint8_t MIDIPitch, uint8_t velocity){
    SerialPrint(MIDICommand);
    SerialPrint(MIDIPitch);
    SerialPrint(velocity);

    MIDI_EventPacket_t MIDIEvent = (MIDI_EventPacket_t){
        .Event       = MIDI_EVENT(MIDICABLE, MIDICommand),

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
        unsigned char midiCommand = (ReceivedMIDIEvent.Event << 4);
        
        // Data bytes should NEVER have bit 7 set
        if(((ReceivedMIDIEvent.Data2 || ReceivedMIDIEvent.Data3) & 0b10000000)
            && !(midiCommand == 0x40 || midiCommand == 0x50 || midiCommand == 0x60 || midiCommand == 0x70)) continue;

        // For anything other than SysEx messages, the following statement should be true
        // so if it's not, do not process the message
       if((midiCommand != (ReceivedMIDIEvent.Data1 & MIDI_COMMAND_MASK)) 
        // and this one covers SysEx messages
            && !(midiCommand == 0x40 || midiCommand == 0x50 || midiCommand == 0x60 || midiCommand == 0x70)) continue;
        // Immediately process MIDI realtime messages
        if((ReceivedMIDIEvent.Data1 >> 3) == 0b11111){
            switch(ReceivedMIDIEvent.Data1 & 0b111){
                case 0:
                // clock tick
                if(midi_clock_flag) midi_tick++;
                break;
                case 2:
                //start
                if(!midi_clock_flag){
                    midi_clock_flag = 1;
                    midi_tick = midi_tempo - 1;
                }
                break;
                case 3:
                //continue
                midi_clock_flag = 1;
                break;
                case 4:
                //stop
                midi_clock_flag = 0;
                break;
                case 5:
                //undefined
                break;
                case 6:
                //active sensing
                break;
                case 7:
                //reset
                break;
            }
            continue; // No further processing needed
        };

        if((ReceivedMIDIEvent.Event >> 4) == MIDICABLE){
            _rx_processMIDIpacket(midiCommand, ReceivedMIDIEvent.Data1, ReceivedMIDIEvent.Data2, ReceivedMIDIEvent.Data3);
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
                _rx_noteOn(channel, note, velocity);
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

static inline void _rx_noteOn(unsigned char channel, unsigned char note, unsigned char velocity){
    if(_omni || channel == MIDICHANNEL){
        midi_notes[note/12] |= (1 << (note % 12));
        midi_changed = 1;
        midi_new = !midi_hasnotes;
        midi_hasnotes = 1;
        midi_velocity = velocity;
    }
}

static inline void _rx_noteOff(unsigned char channel, unsigned char note){
    if(_omni || channel == MIDICHANNEL){
        midi_notes[note/12] &= ~(1 << (note % 12));
        midi_changed = 1;
        midi_hasnotes = 0;
        midi_new = 0;
        for(int octave_count = 0; octave_count < OCTAVE_TOTAL; ++octave_count){
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
        memset(midi_notes, 0, 2*OCTAVE_TOTAL);
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

static inline void _rx_sysEx(unsigned char byte1, unsigned char byte2, unsigned char byte3){
    if(midi_sysex_flag){
        // Message has already started
        _process_sysEx_byte(byte1);
        _process_sysEx_byte(byte2);
        _process_sysEx_byte(byte3);
    } else {
        if(byte1 == 0xF0){
            midi_sysex_flag = true;
            midi_sysex_buffer_pointer = 0;
            _process_sysEx_byte(byte2);
            _process_sysEx_byte(byte3);
        } else {
            // TODO this is an error state; do something intelligent
        }
    }
}

static inline void _process_sysEx_byte(unsigned char data){
    if(midi_sysex_flag){
        if(data == 0xF7){
            // Message complete
            midi_sysex_flag = false;
            _complete_sysEx();
        } else {
            if(midi_sysex_buffer_pointer < MIDI_SYSEX_BUFFER_SIZE) {
                midi_sysex_buffer[midi_sysex_buffer_pointer++] = data;
            } else {
                midi_sysex_flag = false;
            }
        }
    }
}

static inline void _complete_sysEx(void){
    int readIndex = 0;
    if(midi_sysex_buffer_pointer == MIDI_SYSEX_BUFFER_SIZE
        && midi_sysex_buffer[readIndex++] == MIDI_MANUFACTURER_ID0
        && midi_sysex_buffer[readIndex++] == MIDI_MANUFACTURER_ID1
        && midi_sysex_buffer[readIndex++] == MIDI_MANUFACTURER_ID2
        && midi_sysex_buffer[readIndex++] == MIDI_SYSEX_VERSION
        )
    {
        cli();
        mute();
        int bank = midi_sysex_buffer[readIndex++];
        start_volume = midi_sysex_buffer[readIndex++] & 0b1111;
        start_duty_cycle = midi_sysex_buffer[readIndex++] & 0b1111;

        jump_flag = midi_sysex_buffer[readIndex++] & 0b1111;        
        jump_on_release = midi_sysex_buffer[readIndex++] & 0b1111;

        arp_mode = (midi_sysex_buffer[readIndex++] & 0b1111) % ARPMODES;
        arp_speed = midi_sysex_buffer[readIndex++];
        retrigger_flag = midi_sysex_buffer[readIndex++] & 0b1111;
        
        for(int i = 0; i < TABLE_SIZE; ++i){
            uint8_t hinibble = (midi_sysex_buffer[readIndex++] << 4);
            uint8_t lonibble = (midi_sysex_buffer[readIndex++] & 0b1111);
            table[i] = ( hinibble | lonibble );
        }


        sei();
        load_settings_ifPlaying();
        if(bank) save_settings(bank - 1);
    }
}

static inline void _rx_processMIDIpacket(unsigned char midiCommand, 
                               unsigned char data0,
                               unsigned char data1,
                               unsigned char data2){
                                   
    unsigned char channel = (data0 & MIDI_CHANNEL_MASK);
    if(midiCommand == MIDI_STATUS_NOTEON){
        if(data2){
            _rx_noteOn(channel, data1, data2);
        } else {
            _rx_noteOff(channel, data1);
        }
    } else if(midiCommand == MIDI_STATUS_NOTEOFF){
        _rx_noteOff(channel, data1);
    } else if(midiCommand == MIDI_STATUS_PITCHWHEEL){
        _rx_pitchWheel(channel, data1, data2);
    } else if(midiCommand == MIDI_STATUS_CONTROLCHANGE){
        _rx_controlChange(channel, data1, data2);
    } else if(midiCommand == MIDI_SYSEX_START_OR_CONTINUE || midiCommand == 0x50 || midiCommand == 0x60 || midiCommand == 0x70){
        _rx_sysEx(data0, data1, data2);
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