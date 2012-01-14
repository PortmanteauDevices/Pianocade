#ifndef PIANOCADE_H
#define PIANOCADE_H

    /* Registers */
    #define PORT_DAC PORTF
    #define DDR_DAC DDRF
    
    #define PORT_SPI PORTB
    #define DDR_SPI DDRB
    #define DD_MISO PB3
    #define DD_MOSI PB2
    #define DD_SCK  PB1
    #define DD_SS   PB0

    /* Macros */
    #define HINIBBLE(b) (((b) >> 4) & 0x0F)
    #define LONIBBLE(b) ((b) & 0x0F)
    #define TOTAL_NOTES 128
    #define TOTAL_KEYS 12
    #define MAXCHORD TOTAL_KEYS
    #define CURRENT_NOTE (chord[arp_pos] + shift)
    #define MIDI_NOTE (chord[arp_pos])
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
    * MIDI METHODS
    */
    void noteOn(unsigned char note);
    void noteOff(unsigned char note);
    void MIDI_TX(unsigned char MESSAGE, unsigned char PITCH, unsigned char VELOCITY) ;

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

    void spi_init(void);
    uint8_t spi_transfer(uint8_t _data);

#endif /* end of include guard: PIANOCADE_H */