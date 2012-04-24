#ifndef MIDI_PIANOCADE_H
#define MIDI_PIANOCADE_H value
    #include "Descriptors.h"
    #include "Serial.h"
    #include <LUFA/Version.h>
    #include <LUFA/Drivers/USB/USB.h>
    #include <string.h>

    #define MIDI_NOTE (chord[arp_pos])

    #define MIDI_COMMAND_MASK 0xF0
    #define MIDI_CHANNEL_MASK 0x0F
    #define MIDI_STATUS_NOTEON 0x90
    #define MIDI_STATUS_NOTEOFF 0x80
    #define MIDI_STATUS_CONTROLCHANGE 0xB0

    #define MIDICHANNEL 0
    #define MIDICABLE 0
    // Default velocity as per MIDI 1.0 specs, p10
    #define MIDI_DEFAULT_VELOCITY 0x40

    extern USB_ClassInfo_MIDI_Device_t Keyboard_MIDI_Interface;

    static void _MIDI_send(uint8_t MIDICommand, uint8_t MIDIPitch, uint8_t velocity);
    void MIDI_noteOn(unsigned char note);
    void MIDI_noteOff(unsigned char note);
    static void MIDI_processUSB(void);
    static void MIDI_processSerial(void);
    void MIDI_processInput(void);
    
    static void _noteOn(unsigned char channel, unsigned char note);
    static void _noteOff(unsigned char channel, unsigned char note);
    static void _controlChange(unsigned char channel, unsigned char data1, unsigned char data2);
    
    static void _processMIDIpacket(unsigned char midiCommand,
                                   unsigned char channel,
                                   unsigned char data1,
                                   unsigned char data2);

    void USBSetupHardware(void);

    void EVENT_USB_Device_Connect(void);
    void EVENT_USB_Device_Disconnect(void);
    void EVENT_USB_Device_ConfigurationChanged(void);
    void EVENT_USB_Device_ControlRequest(void);

    void MIDI_initialize(void);
#endif