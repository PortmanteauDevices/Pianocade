#include "Serial.h"

void SerialBegin(void){
    /* Set baud rate */ 
    UBRR1H = ( BAUD_PRESCALE >> 8); 
    UBRR1L = BAUD_PRESCALE;
    
    /* Enable receiver and transmitter */ 
    UCSR1B = (1<<RXEN1)|(1<<TXEN1); 
    /* Set frame format: 8 data, 1 stop bit */ 
    UCSR1C = (1<<UCSZ10)|(1<<UCSZ11);
}

void SerialPrint(uint8_t ByteToSend){
    while (( UCSR1A & (1 << UDRE1 )) == 0) {}; // Do nothing until UDR is ready for more data to be written to it
    UDR1 = ByteToSend ; // Send out the byte value in the variable " ByteToSend "
}