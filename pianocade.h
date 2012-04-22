#ifndef PIANOCADE_H
#define PIANOCADE_H

    #include "Descriptors.h"
    #include "Serial.h"
    #include "MIDI.h"

    #include <LUFA/Version.h>
    #include <LUFA/Drivers/USB/USB.h>
    #include <avr/pgmspace.h>
    #include <avr/interrupt.h>
    #include <stdlib.h>
    #include <string.h>

    extern USB_ClassInfo_MIDI_Device_t Keyboard_MIDI_Interface;

    extern uint16_t midi_notes[10];
    extern uint8_t midi_changed ;
    extern uint8_t midi_new;
    extern uint8_t midi_hasnotes ;

    /* Registers */
    #define PORT_DAC PORTA
    #define DDR_DAC DDRA

    #define PORT_NOTES0 PORTE
    #define DDR_NOTES0 DDRE
    #define PIN_NOTES0 PINE

    #define PORT_NOTES1 PORTC
    #define DDR_NOTES1 DDRC
    #define PIN_NOTES1 PINC

    #define PORT_NOTES2 PORTB
    #define DDR_NOTES2 DDRB
    #define PIN_NOTES2 PINB

    // NOTE: to use PORTF, JTAF interface must be disabled
    #define PORT_CONTROL PORTF
    #define DDR_CONTROL DDRF
    #define PIN_CONTROL PINF

    /* Macros */
    #define HINIBBLE(b) (((b) >> 4) & 0x0F)
    #define LONIBBLE(b) ((b) & 0x0F)
    #define TOTAL_NOTES 128
    #define TOTAL_KEYS 12
    #define MAXCHORD TOTAL_KEYS
    #define CURRENT_NOTE (chord[arp_pos] + shift)
    #define BEND_SPEED 20
    #define BEND_MAX 8
    #define DEBOUNCE 50
    #define NOTES_DEBOUNCE DEBOUNCE
    #define CONTROL_DEBOUNCE DEBOUNCE
    #define HELD_DEBOUNCE DEBOUNCE
    #define ARPMODES 3
    #define TABLE_SPEED 24

    /* Function prototypes */

    /*
    * NOTE GENERATION
    */
    void square_a(void);
    void square_b(void);
    void wave_a(void);
    void wave_b(void);

    /*
    * PITCH BEND METHODS
    */
    void autobend_down(void);
    void autobend_up(void);
    void autobend_return(void);

    /*
    * ENVELOPE METHODS
    */
    void mute(void);

    /*
    * ARPEGGIO METHODS
    */
    void ascending(void);
    void descending(void);
    void random_arp(void);

    /*
    * TABLE METHODS
    */
    void pause(uint8_t waittime);
    void volumeup(uint8_t increment);
    void volumedown(uint8_t increment);
    void setvolume(uint8_t level);
    void setdutycycle(uint8_t level);
    void shiftnote(uint8_t interval);
    void setnote(uint8_t interval);
    void shiftoctave(uint8_t interval);
    void jumpto(uint8_t landing_index);
    void shiftbend(uint8_t increment);
    void setbend(uint8_t increment);

    /*
    * MISCELLANEOUS METHODS
    */
    void load_settings(uint8_t bank);
    void new_note(void);
    
    static inline void pianocadeSetup();
    static inline void readPins();
    static inline void debouncePins();
    static inline void processHold();
    static inline void processControls();
    static inline void processNotes();
    
#endif /* end of include guard: PIANOCADE_H */