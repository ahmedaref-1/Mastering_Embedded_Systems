/*
 * STM32F103C6_KEYPAD.h
 *
 *  Created on: Jul 26, 2023
 *      Author: Ahmed Aref Omaira
 */

#ifndef STM32F103C6_KEYPAD_H_
#define STM32F103C6_KEYPAD_H_

/******************************************
 *                                        *
 *                INCLUDES                *
 * 										  *
 * ****************************************/
#include <STM32F103C6_GPIO.h>
#include <STM32F103C6_REGISTERS.h>


/******************************************
 *                                        *
 *            KEYPAD INTERFACING          *
 * 										  *
 * ****************************************/
#define KEYPAD_PORT GPIOB

#define R0 GPIO_PIN_0
#define R1 GPIO_PIN_1
#define R2 GPIO_PIN_3
#define R3 GPIO_PIN_4
#define C0 GPIO_PIN_5
#define C1 GPIO_PIN_6
#define C2 GPIO_PIN_7
#define C3 GPIO_PIN_8


/********************************************
 *                                          *
 *   APIs SUPPORTED BY THE "KEYPAD DRIVER"  *
 * 										    *
 * ******************************************/
void Keypad_init();
char Keypad_getkey();

#endif /* STM32F103C6_KEYPAD_H_ */
