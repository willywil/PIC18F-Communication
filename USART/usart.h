//file: H16_usart.h
#include <stdio.h>
//#define 	BAUD 	9600
//#define 	FOSC		4000000L
//#define 	baudsetting 	((int)(FOSC/(4UL * BAUD)-1))
//#define 	TX_PIN	TRISC6
//#define 	RX_PIN	TRISC7
#ifndef __MYUSART_H
#define __MYUSART_H

void 	putch(unsigned char);
unsigned char	getch(void);
void 	putch2(unsigned char);
unsigned char	getch2(void);
//void	init_comms(void);



//void	init_comms(void)
//{
//	TRISC6 = 0;	//configure RC6 pin as output for transmission
//	TRISC7 = 1;	//configure RC7 pin as input for reception
//
//	//set up transmitter and receiver without interrupt
//	SPBRG = baudsetting;	//for baud rate calculation
//	SYNC = 0;	//asynchronous transmission
//	BRG16 = 1;	//16-bit asynchronous communication
//	BRGH = 1;	//high speed communication
//	SCKP = 0;	//non-inverted data communication
//	CREN = 1;	//continuous asynchronous reception
//	TX9D = 0;	//set for 8-bit ASCII transmission (9-bit mode disabled)
//	RX9D = 0;	//set for 8-bit ASCII reception (9-bit mode disabled)
//	TXEN = 1;	//Enable the transmission. This will also set interrupt bit TXIF = 1
//	SPEN = 1;	/*enables the EUSART and automatically configures the TX/CK I/O pin
// RC6 as an output and RX/DT I/O pin RC7 as input terminals for
// asynchronous serial communication. */
//}
#endif