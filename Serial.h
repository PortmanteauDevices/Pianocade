#ifndef SERIAL_PIANOCADE
#define SERIAL_PIANOCADE
    #include <avr/io.h>
    #include <avr/interrupt.h>
    #include "MIDI.h"

    #define USART_BAUDRATE 31250
    #define BAUD_PRESCALE ((( F_CPU / ( USART_BAUDRATE * 16UL ))) - 1)

    extern uint8_t midi_tick;
    extern uint8_t midi_clock_flag;
    extern uint8_t midi_tempo;

    void SerialBegin(void);
    void SerialPrint(uint8_t);
    int SerialAvailable(void);
    unsigned char SerialPeek(void);
    unsigned char SerialRead(void);

#endif