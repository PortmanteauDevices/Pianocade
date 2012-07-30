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
    #include <avr/eeprom.h>

    extern USB_ClassInfo_MIDI_Device_t Keyboard_MIDI_Interface;

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
    
    // Set max to 8 for 24 keys, 9 for 12 keys
    #define OCTAVE_MAX 8
    #define OCTAVE_MIN 0
    #define OCTAVE_TOTAL 11

    /* Macros */
    #define HINIBBLE(b) (((b) >> 4) & 0x0F)
    #define LONIBBLE(b) ((b) & 0x0F)
    #define TOTAL_NOTES 128
    #define TOTAL_KEYS 12
    #define MAXCHORD 36
    #define CURRENT_PITCH (current_note + shift)
    #define BEND_SPEED 20
    #define BEND_MAX 8
    #define DEBOUNCE 50
    #define NOTES_DEBOUNCE DEBOUNCE
    #define CONTROL_DEBOUNCE DEBOUNCE
    #define HELD_DEBOUNCE DEBOUNCE
    #define ARPMODES 5
    #define TABLE_SPEED 24
    #define TABLE_SIZE 32
    #define BANK_SIZE 15
    #define MAX_ARP_SPEED 22
    
    /* External variables */
    extern uint16_t midi_notes[OCTAVE_TOTAL];
    extern uint8_t midi_changed;
    extern uint8_t midi_new;
    extern uint8_t midi_hasnotes;
    extern int8_t midi_bend_step;
    extern uint8_t midi_arp_output;
    extern uint8_t midi_local_control;
    extern uint8_t midi_velocity;

    extern uint8_t midi_clock_flag;
    extern uint8_t midi_tick;
    extern uint8_t midi_tempo;

    /* Function prototypes */

    /*
    * NOTE GENERATION
    */
    static inline void square_a(void);
    static inline void square_b(void);
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
    void pingpong(void);
    void random_arp(void);
    void order_pressed(void);
    
    static inline void arp_speed_increase(void);
    static inline void arp_speed_decrease(void);
    static inline void arp_speed_double(void);
    static inline void arp_speed_half(void);
    
    /*
    * TABLE METHODS
    */
    void pause(uint8_t waittime);
    void volumeup(uint8_t increment);
    void volumedown(uint8_t increment);
    void setvolume(uint8_t level);
    void setdutycycle(uint8_t level);
    void shiftnote(uint8_t interval);
    void shiftnoteup(uint8_t interval);
    void shiftnotedown(uint8_t interval);
    void setnote(uint8_t interval);
    void shiftoctave(uint8_t interval);
    void jumpto(uint8_t landing_index);
    void shiftbend(uint8_t increment);
    void setbend(uint8_t increment);
    void setvolumevelocity(uint8_t unused);

    /*
    * MISCELLANEOUS METHODS
    */
    void load_settings(uint8_t bank);
    void load_settings_ifPlaying(void);
    void new_note(void);
    
    /*
    * LIST METHODS
    */
    static inline void list_initialize(void);
    int8_t list_add(uint8_t data);
    void list_remove(int8_t node);
    void list_find_and_remove(uint8_t data);
    
    static inline void pianocadeSetup(void);
    static inline void initializeTranspose(void);
    static inline void readPins(void);
    static inline void debouncePins(void);
    static inline void processHold(void);
    static inline void clearHold(void);
    static inline void processControls(void);
    static inline void processCoins(void);
    static inline void processNotes(void);
    static inline void onOctaveChange(void);
    
    static inline void loadPressedNotes(uint16_t noteStore[]);

#endif /* end of include guard: PIANOCADE_H */