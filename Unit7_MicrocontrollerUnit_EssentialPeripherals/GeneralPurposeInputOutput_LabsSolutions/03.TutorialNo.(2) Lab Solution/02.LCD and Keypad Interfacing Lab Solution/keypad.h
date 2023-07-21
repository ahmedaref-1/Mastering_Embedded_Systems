/*
 * keypad.h
 *
 * Created: 7/21/2023 5:56:41 AM
 *  Author: Ahmed Aref Omaira
 */ 

#define F_CPU 8000000UL
#include <avr/io.h>

/************************************************************************/
/*                     KEYPAD PIN CONFIGURATION                         */
/************************************************************************/

#ifndef KEYPAD_H_
#define KEYPAD_H_

#define  KEYPAD_DATA_PORT PORTD
#define  KEYPAD_PORT_DATADIRECTION DDRD
#define  KEYPAD_PORT_PIN PIND
#define	 R0 0
#define  R1 1
#define  R2 2
#define  R3 3
#define  C0 4
#define  C1 5
#define  C2 6
#define  C3 7

/************************************************************************/
/*                       FUNCTIONS PROTOTYPES                           */
/************************************************************************/

void KEYPAD_init();
char KEYPAD_getChar();

#endif /* KEYPAD_H_ */