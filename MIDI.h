#ifndef MIDI_PIANOCADE_H
#define MIDI_PIANOCADE_H value
    #include "Descriptors.h"
    #include "Serial.h"
    #include "Pianocade.h"
    #include <LUFA/Version.h>
    #include <LUFA/Drivers/USB/USB.h>
    #include <string.h>

    #define MIDI_COMMAND_MASK 0xF0
    #define MIDI_CHANNEL_MASK 0x0F
    #define MIDI_STATUS_NOTEON 0x90
    #define MIDI_STATUS_NOTEOFF 0x80
    #define MIDI_STATUS_PITCHWHEEL 0xE0
    #define MIDI_STATUS_CONTROLCHANGE 0xB0
    #define MIDI_SYSEX_START_OR_CONTINUE 0x40
    
    #define MIDI_SYSEX_BUFFER_SIZE 76 // THIS IS A POINT OF FAILURE IF NOT KEPT ACCURATE AND UP TO DATE
    #define MIDI_MANUFACTURER_ID0 0x00
    #define MIDI_MANUFACTURER_ID1 0x01
    #define MIDI_MANUFACTURER_ID2 0x72
    #define MIDI_SYSEX_VERSION 0x00
    

    #define MIDICHANNEL 0
    #define MIDICABLE 0
    // Default velocity as per MIDI 1.0 specs, p10
    #define MIDI_DEFAULT_VELOCITY 0x40

    extern USB_ClassInfo_MIDI_Device_t Keyboard_MIDI_Interface;

    static inline void _tx(uint8_t MIDICommand, uint8_t MIDIPitch, uint8_t velocity);
    void MIDI_tx_noteOn(unsigned char note);
    void MIDI_tx_noteOff(unsigned char note);
    static inline void _rx_USB(void);
    static inline void _rx_Serial(void);
    void inline MIDI_rx(void);
    
    static inline void _rx_noteOn(unsigned char channel, unsigned char note, unsigned char velocity);
    static inline void _rx_noteOff(unsigned char channel, unsigned char note);
    static inline void _rx_pitchWheel(unsigned char channel, unsigned char lsb, unsigned char msb);
    static inline void _rx_controlChange(unsigned char channel, unsigned char data1, unsigned char data2);
    static inline void _rx_sysEx(unsigned char byte1, unsigned char byte2, unsigned char byte3);
    static inline void _process_sysEx_byte(unsigned char data);
    static inline void _complete_sysEx(void);
    
    static inline void _rx_processMIDIpacket(unsigned char midiCommand,
                                   unsigned char channel,
                                   unsigned char data1,
                                   unsigned char data2);

    void USBSetupHardware(void);

    void EVENT_USB_Device_Connect(void);
    void EVENT_USB_Device_Disconnect(void);
    void EVENT_USB_Device_ConfigurationChanged(void);
    void EVENT_USB_Device_ControlRequest(void);

    void MIDI_init(void);
    
    // Externs for sysEx patch loading
    extern uint8_t start_volume;
    extern uint8_t start_duty_cycle;
    extern uint8_t table[32]; //TODO Fix constant
    extern uint8_t jump_on_release;
    extern uint8_t jump_flag;
    extern uint8_t retrigger_flag;
    extern uint8_t arp_mode;
    extern volatile uint8_t arp_speed;
    
#endif