#ifndef SERIAL_PIANOCADE
#define SERIAL_PIANOCADE
    #include <avr/io.h>

    #define USART_BAUDRATE 31250
    #define BAUD_PRESCALE ((( F_CPU / ( USART_BAUDRATE * 16UL ))) - 1)

    void SerialBegin(void);
    void SerialPrint(uint8_t);
    int SerialAvailable(void);
    unsigned char SerialPeek(void);
    unsigned char SerialRead(void);
    

#endif