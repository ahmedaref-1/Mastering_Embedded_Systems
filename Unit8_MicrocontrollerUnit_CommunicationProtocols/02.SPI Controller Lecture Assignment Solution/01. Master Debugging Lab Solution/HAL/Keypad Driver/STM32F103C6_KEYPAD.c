/*
 * STM32F103C6_KEYPAD.c
 *
 *  Created on: Jul 26, 2023
 *      Author: Ahmed Aref Omaira
 */

/******************************************
 *                                        *
 *                INCLUDES                *
 * 										  *
 * ****************************************/
#include <STM32F103C6_KEYPAD.h>

/******************************************
 *                                        *
 *         FUNCTIONS DEFINITION           *
 * 										  *
 * ****************************************/
/*******************************************
 *      INTERNALLY USED FUNCITONS          *
 * *****************************************/
void ___delay___ms(uint32_t t)
{
	uint32_t i  , j;
	for(i = 0 ; i < t ; i++)
		for(j = 0 ; j < 255 ; j++);
}

int KeypadRow[] = { R0, R1, R2, R3 }; //rows of the keypad
int KeypadCol[] = { C0, C1, C2, C3 }; //columns
/*******************************************
 *      APIs USED BY USER FUNCITONS        *
 *******************************************/
void Keypad_init() {

	GPIO_PinConfig_t keypadPinConfiguration;

	// 1.Initialize all the port pins to be output
	keypadPinConfiguration.GPIO_Mode = GPIO_MODE_Output_PP;
	keypadPinConfiguration.GPIO_OutputSpeed = GPIO_SPEED_10MHz;

	keypadPinConfiguration.GPIO_PinNumber = R0;
	MCAL_GPIO_Init(KEYPAD_PORT, &keypadPinConfiguration);
	keypadPinConfiguration.GPIO_PinNumber = R1;
	MCAL_GPIO_Init(KEYPAD_PORT, &keypadPinConfiguration);
	keypadPinConfiguration.GPIO_PinNumber = R2;
	MCAL_GPIO_Init(KEYPAD_PORT, &keypadPinConfiguration);
	keypadPinConfiguration.GPIO_PinNumber = R3;
	MCAL_GPIO_Init(KEYPAD_PORT, &keypadPinConfiguration);
	keypadPinConfiguration.GPIO_PinNumber = C0;
	MCAL_GPIO_Init(KEYPAD_PORT, &keypadPinConfiguration);
	keypadPinConfiguration.GPIO_PinNumber = C1;
	MCAL_GPIO_Init(KEYPAD_PORT, &keypadPinConfiguration);
	keypadPinConfiguration.GPIO_PinNumber = C2;
	MCAL_GPIO_Init(KEYPAD_PORT, &keypadPinConfiguration);
	keypadPinConfiguration.GPIO_PinNumber = C3;
	MCAL_GPIO_Init(KEYPAD_PORT, &keypadPinConfiguration);

	// 2.Output high on all the port pins
	MCAL_GPIO_WritePort(KEYPAD_PORT,GPIO_PORT_SET);

}

char Keypad_getkey() {
	int i, j;
	for (i = 0; i < 4; i++) {
		MCAL_GPIO_WritePin(KEYPAD_PORT, KeypadCol[0], GPIO_PIN_SET);
		MCAL_GPIO_WritePin(KEYPAD_PORT, KeypadCol[1], GPIO_PIN_SET);
		MCAL_GPIO_WritePin(KEYPAD_PORT, KeypadCol[2], GPIO_PIN_SET);
		MCAL_GPIO_WritePin(KEYPAD_PORT, KeypadCol[3], GPIO_PIN_SET);
		MCAL_GPIO_WritePin(KEYPAD_PORT, KeypadCol[i], GPIO_PIN_RESET);
		for (j = 0; j < 4; j++) {
			if (MCAL_GPIO_ReadPin(KEYPAD_PORT, KeypadRow[j]) == 0) {
				while (MCAL_GPIO_ReadPin(KEYPAD_PORT, KeypadRow[j]) == 0);
				switch (i) {
				case (0):
					if (j == 0)
						return '7';
					else if (j == 1)
						return '4';
					else if (j == 2)
						return '1';
					else if (j == 3)
						return '?';
					break;
				case (1):
					if (j == 0)
						return '8';
					else if (j == 1)
						return '5';
					else if (j == 2)
						return '2';
					else if (j == 3)
						return '0';
					break;
				case (2):
					if (j == 0)
						return '9';
					else if (j == 1)
						return '6';
					else if (j == 2)
						return '3';
					else if (j == 3)
						return '=';
					break;
				case (3):
					if (j == 0)
						return '/';
					else if (j == 1)
						return '*';
					else if (j == 2)
						return '-';
					else if (j == 3)
						return '+';
					break;
				}
			}
		}
	}
	return 'A';
}
