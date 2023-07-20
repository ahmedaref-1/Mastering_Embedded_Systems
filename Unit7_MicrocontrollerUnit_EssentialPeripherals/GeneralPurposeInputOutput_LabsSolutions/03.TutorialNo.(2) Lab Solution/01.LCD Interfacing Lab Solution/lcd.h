/*
 * IncFile1.h
 *
 * Created: 7/20/2023 12:54:51 PM
 *  Author: Ahmed Aref Omaira
 */ 


#ifndef LCD_H_
#define LCD_H_

#define F_CPU 8000000UL
#include <avr/io.h>
#include <stdio.h>
#include <string.h>
#include <util/delay.h>

/************************************************************************/
/*                     LCD PIN CONFIGURATION                            */
/************************************************************************/
#define	EIGHT_BIT_MODE
//#define FOUR_BIT_MODE

#define LCD_DATA_PORT PORTA
#define LCD_PORT_DATADIRECTION DDRA

#ifdef  EIGHT_BIT_MODE
#define DATA_SHIFT 0 // if 8 bit mode defined, then we are in 8 bit mode so define data shift with value equals 0
#endif

#ifndef DATA_SHIFT
#define DATA_SHIFT 4 // if data shift is not defined, then we are in the 4 bit mode so define data shift with value equals 4 
#endif

#define LCD_CTRL_PORT PORTB
#define LCD_CTRL_DATADIRECTION DDRB
#define LCD_EN_SWITCH 0
#define LCD_RW_SWITCH 1
#define LCD_RS_SWITCH 2

/************************************************************************/
/*                       COMMANDS DEFINITION                            */
/************************************************************************/
#define LCD_REGISTER_SELECT_PIN						(0)
#define LCD_READ_WRITE_PIN							(1)
#define LCD_ENABLE_PIN								(2)
#define LCD_REGISTER_SELECT_ENABLE					(1)
#define LCD_REGISTER_SELECT_DISABLE					(0)
#define READ_FROM_LCD								(1)
#define WRITE_TO_LCD								(0)
#define LCD_ENABLE									(1)
#define LCD_DISABLE									(0)
#define LCD_FIRST_LINE								(0)
#define LCD_SECOND_LINE								(1)
#define LCD_FUNCTION_8BIT_2LINES   					(0x38)
#define LCD_FUNCTION_4BIT_2LINES   					(0x28)
#define LCD_MOVE_DISP_RIGHT       					(0x1C)
#define LCD_MOVE_DISP_LEFT   						(0x18)
#define LCD_MOVE_CURSOR_RIGHT   					(0x14)
#define LCD_MOVE_CURSOR_LEFT 	  					(0x10)
#define LCD_DISP_OFF   								(0x08)
#define LCD_DISP_ON_CURSOR   						(0x0E)
#define LCD_DISP_ON_CURSOR_BLINK   					(0x0F)
#define LCD_DISP_ON_BLINK   						(0x0D)
#define LCD_DISP_ON   								(0x0C)
#define LCD_ENTRY_DEC   							(0x04)
#define LCD_ENTRY_DEC_SHIFT   						(0x05)
#define LCD_ENTRY_INC_   							(0x06)
#define LCD_ENTRY_INC_SHIFT   						(0x07)
#define LCD_BEGIN_AT_FIRST_ROW						(0x80)
#define LCD_BEGIN_AT_SECOND_ROW						(0xC0)
#define LCD_CLEAR_SCREEN							(0x01)
#define LCD_ENTRY_MODE								(0x06)

/************************************************************************/
/*                       FUNCTIONS PROTOTYPES                           */
/************************************************************************/
void LCD_init(void);
void LCD_sendCommand(unsigned char command);
void LCD_displayCharacter(unsigned char character);
void LCD_displayString(char *string);
void LCD_isBusy(void);
void LCD_clearScreen ();
void LCD_GoToXY(unsigned char line, unsigned char position);
void LCD_displayInteger (int Number );
void LCD_displayRealNumber (double  Number );

#endif /* LCD_H_ */