/*
 * STM32F103C6_LCD.h
 *
 *  Created on: Jul 25, 2023
 *      Author: Ahmed Aref Omaira
 */

#ifndef STM32F103C6_LCD_H_
#define STM32F103C6_LCD_H_

/******************************************
 *                                        *
 *                INCLUDES                *
 * 										  *
 * ****************************************/
#include "STM32F103C6_GPIO.h"
#include "STM32F103C6_REGISTERS.h"


/******************************************
 *                                        *
 *   LCD INTERFACING AND CONFIGURATION    *
 * 										  *
 * ****************************************/
/*******************************************
 *             MODE CONFIGURATION          *
 * *****************************************/
#define	EIGHT_BIT_MODE 				8U
#define FOUR_BIT_MODE				4U
#define LCD_OPERATING_MODE 			EIGHT_BIT_MODE

/*******************************************
 *             LCD INTERFACING             *
 * *****************************************/
#define LCD_DATA_PORT GPIOA
#define LCD_CTRL_PORT GPIOA

#define LCD_EN_SWITCH GPIO_PIN_10
#define LCD_RW_SWITCH GPIO_PIN_9
#define LCD_RS_SWITCH GPIO_PIN_8

#define LCD_D0_PIN GPIO_PIN_0
#define LCD_D1_PIN GPIO_PIN_1
#define LCD_D2_PIN GPIO_PIN_2
#define LCD_D3_PIN GPIO_PIN_3
#define LCD_D4_PIN GPIO_PIN_4
#define LCD_D5_PIN GPIO_PIN_5
#define LCD_D6_PIN GPIO_PIN_6
#define LCD_D7_PIN GPIO_PIN_7

#define LCD_FIRST_LINE		(0UL)
#define LCD_SECOND_LINE		(1UL)
#define LCD_FIRST_COLUMN	(0UL)

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


#endif /* STM32F103C6_LCD_H_ */
