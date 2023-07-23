/*
 * LCD.h
 *
 *  Created on: Jul 23, 2023
 *      Author: Ahmed Aref Omaira
 */

#ifndef LCD_H_
#define LCD_H_

/******************************************
 *                                        *
 *                INCLUDES                *
 * 										  *
 * ****************************************/
#include "../MCAL/STM32F103C6_GPIO.h"
#include "../Utilities/STM32F103C6_REGISTERS.h"


/******************************************
 *                                        *
 *   LCD INTERFACING AND CONFIGURATION    *
 * 										  *
 * ****************************************/
/*******************************************
 *             MODE CONFIGURATION          *
 * *****************************************/
#define	EIGHT_BIT_MODE
//#define FOUR_BIT_MODE

#ifdef  EIGHT_BIT_MODE
#define DATA_SHIFT 0 // if 8 bit mode defined, then we are in 8 bit mode so define data shift with value equals 0
#endif

#ifndef DATA_SHIFT
#define DATA_SHIFT 4 // if data shift is not defined, then we are in the 4 bit mode so define data shift with value equals 4
#endif

/*******************************************
 *             LCD INTERFACING             *
 * *****************************************/
#define LCD_DATA_PORT GPIOA
#define LCD_CTRL_PORT GPIOA

#define LCD_EN_SWITCH GPIO_PIN_10
#define LCD_RW_SWITCH GPIO_PIN_9
#define LCD_RS_SWITCH GPIO_PIN_8

#define LCD_FIRST_LINE								(0UL)
#define LCD_SECOND_LINE								(1UL)
#define LCD_FIRST_COLUMN							(0UL)

/*******************************************
 *               LCD COMMANDS              *
 * *****************************************/
#define LCD_CMD_FUNCTION_8BIT_2LINES   					(0x38)
#define LCD_CMD_FUNCTION_4BIT_2LINES   					(0x28)
#define LCD_CMD_FUNCTION_4BIT_2LINES_1st_CMD 			(0x02)
#define LCD_CMD_MOVE_DISP_RIGHT       					(0x1C)
#define LCD_CMD_MOVE_DISP_LEFT   						(0x18)
#define LCD_CMD_MOVE_CURSOR_RIGHT   					(0x14)
#define LCD_CMD_MOVE_CURSOR_LEFT 	  					(0x10)
#define LCD_CMD_DISP_OFF   								(0x08)
#define LCD_CMD_DISP_ON_CURSOR   						(0x0E)
#define LCD_CMD_DISP_ON_CURSOR_BLINK   					(0x0F)
#define LCD_CMD_DISP_ON_BLINK   						(0x0D)
#define LCD_CMD_DISP_ON   								(0x0C)
#define LCD_CMD_ENTRY_DEC   							(0x04)
#define LCD_CMD_ENTRY_DEC_SHIFT   						(0x05)
#define LCD_CMD_ENTRY_INC_   							(0x06)
#define LCD_CMD_ENTRY_INC_SHIFT   						(0x07)
#define LCD_CMD_BEGIN_AT_FIRST_ROW						(0x80)
#define LCD_CMD_BEGIN_AT_SECOND_ROW						(0xC0)
#define LCD_CMD_CLEAR_SCREEN							(0x01)
#define LCD_CMD_ENTRY_MODE								(0x06)

/******************************************
 *                                        *
 *   APIs SUPPORTED BY THE "LCD DRIVER"   *
 * 										  *
 * ****************************************/
void LCD_init(void);
void LCD_sendCommand(unsigned char command);
void LCD_displayCharacter(unsigned char character);
void LCD_displayString(char *string);
void LCD_isBusy(void);
void LCD_clearScreen ();
void LCD_GoToXY(unsigned char line, unsigned char position);


#endif /* LCD_H_ */
