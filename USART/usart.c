/***************************************************************
* File: usart.c											       *
* Programmer: Chris Halcarz									   *
* Date: 7-11-13											   	   *
* Version: 1.00												   *
* Dependencies: requires no other files	   					   *
* Description: basic usart functions for pic18f series. 	   *
* Note:                                                        *
***************************************************************/
#include <xc.h>
#include "usart.h"
#define SERIAL_BUFFER_SIZE 64

 typedef struct
{
  unsigned char buffer[SERIAL_BUFFER_SIZE];
  volatile unsigned int head;
  volatile unsigned int tail;
} ring_buffer;

  ring_buffer rx_buffer;
  ring_buffer tx_buffer;

void 	putch(unsigned char byte)
{	/* output one byte */
	while(!PIR1bits.TX1IF)	continue;	//set when the register is empty
	TXREG1 = byte;
}

unsigned char	getch(void)
{	//retrieve one byte
	while(!RCIF)	continue;	//set when the register is not empty
	return RCREG;
}
void 	putch2(unsigned char byte)
{	/* output one byte */
	while(!PIR3bits.TX2IF)	continue;	//set when the register is empty
	TXREG2 = byte;
}

unsigned char	getch2(void)
{	//retrieve one byte
	while(!PIR3bits.RC2IF)	continue;	//set when the register is not empty
	return RCREG2;
}
//
inline void serial_storeChar(unsigned char c, ring_buffer *buffer)
{
  int i = (unsigned int)(buffer->head + 1) % SERIAL_BUFFER_SIZE;

  // if we should be storing the received character into the location
  // just before the tail (meaning that the head would advance to the
  // current location of the tail), we're about to overflow the buffer
  // and so we don't write the character or advance the head.
  if (i != buffer->tail) {
    buffer->buffer[buffer->head] = c;
    buffer->head = i;
  }
}

int serial_available(void)
{
    return (int)(SERIAL_BUFFER_SIZE + rx_buffer.head - rx_buffer.tail)%SERIAL_BUFFER_SIZE;
 //return (unsigned int)(SERIAL_BUFFER_SIZE + rx_buffer->head - rx_buffer->tail) % 
}