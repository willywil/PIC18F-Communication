/*
 * File:   Main.c
 * Author: jon
 *
 * Created on February 23, 2018, 7:40 PM
 * This program uses pic18f46k80 and EUSART 1 Pins:25TXpluginRX,26RXpluginTX
 * Pickit pins 1.MCLR pic pin 1
 *             2.VDD Target pic pin 10
 *             3.VSS GND pic pin 11
 *             4.PGD pic pin 40
 *             5.PGC pic pin 39 
 */

#include <xc.h>
#include "usart.h"
/*----------------CONFIGBITS--------------------------------------------------*/
#pragma config FOSC = INTIO2
#pragma config MCLRE = ON
#pragma config WDTEN = OFF
#pragma config BOREN = OFF
#pragma config PLLCFG = ON
#pragma config XINST  = OFF
void main(void) {
    OSCCON = 0b01110000;
	OSCTUNEbits.PLLEN = 1;
	/*ADCON0 = 0;
	ADCON1 = 0b00110000;
	ADCON2 = 0b10010110;
	ANCON0 = 0b00000000;
	ANCON1 = 0;
        INTCON = 0b11000000;
        INTCONbits.INT0IE = 1;
        INTCON3bits.INT1IE = 1;
        INTCON3bits.INT1IP = 1;
        TRISA = 0b00000000;
        TRISB = 0b00000000;
        TRISC = 0b10000000;
        TRISDbits.TRISD1 = 0;
        TRISE = 0b00000010;
	LATB = 0;*/
//-----------------------------Usart 9600 baud----------------------------------
	TXSTA1 = 0b10100010;
	RCSTA1 = 152;
	BAUDCON1 = 0b01000000;
	SPBRG1 = 103;
    TXSTA2 = 0b10100010;
	RCSTA2 = 152;
	BAUDCON2 = 0b01000000;
	SPBRG2 = 103;
//------------------------------------------------------------------------------
    
    while(1)
    {
        putch('H');
        putch('e');
        putch('l');
        putch('l');
        putch('o');
        putch('\n');
        _delay(8000000);
    }
    return;
}
