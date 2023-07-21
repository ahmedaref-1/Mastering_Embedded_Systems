/*
 * LCD Interfacing.c
 *
 * Created: 7/20/2023 12:53:19 PM
 * Author : ahmed
 */ 

#include "lcd.h"
#include "keypad.h"

int main(void)
{
    /* Replace with your application code */
    LCD_init();
	KEYPAD_init();
	uint8_t pressedCharacter;
	while (1) 
    {
		pressedCharacter = KEYPAD_getChar();
		switch(pressedCharacter){
			case'N':
				break;
			case '!':
			LCD_clearScreen();
			break;
			default:
			LCD_displayCharacter(pressedCharacter);
			break;
		}
	}
}

