#include "Serial.h"

#define RX_BUFFER_SIZE 128

volatile unsigned char buffer[RX_BUFFER_SIZE] = {0};
volatile int writeIndex = 0;
volatile int readIndex = 0;

ISR(USART1_RX_vect){
    unsigned char c;
    c = UDR1;
    int i = (writeIndex + 1) % RX_BUFFER_SIZE;

    // if we should be storing the received character into the location
    // just before the readIndex (meaning that the writeIndex would advance to the
    // current location of the readIndex), we're about to overflow the buffer
    // and so we don't write the character or advance the writeIndex.
    if (i != readIndex) {
      buffer[writeIndex] = c;
      writeIndex = i;
    }
}

void SerialBegin(void){
    /* Set baud rate */ 
    UBRR1H = ( BAUD_PRESCALE >> 8); 
    UBRR1L = BAUD_PRESCALE;
    
    /* Enable receiver and transmitter */ 
    UCSR1B = (1<<RXEN1)|(1<<TXEN1); 
    /* Set frame format: 8 data, 1 stop bit */ 
    UCSR1C = (1<<UCSZ10)|(1<<UCSZ11);
    
    /* Enable receive byte interrupt */
    UCSR1B |= (1<<RXCIE1);
}

void SerialPrint(uint8_t ByteToSend){
    while (( UCSR1A & (1 << UDRE1 )) == 0) {}; // Do nothing until UDR is ready for more data to be written to it
    UDR1 = ByteToSend ; // Send out the byte value in the variable " ByteToSend "
}

int SerialAvailable(void)
{
  return (RX_BUFFER_SIZE + writeIndex - readIndex) % RX_BUFFER_SIZE;
}

unsigned char SerialPeek(void)
{
  if (writeIndex == readIndex) {
    return -1;
  } else {
    return buffer[readIndex];
  }
}

unsigned char SerialRead(void)
{
  // if the writeIndex equals the readIndex, the buffer is empty
  if (writeIndex == readIndex) {
    return -1;
  } else {
    unsigned char c = buffer[readIndex];
    readIndex = (readIndex + 1) % RX_BUFFER_SIZE;
    return c;
  }
}