/*
 * LCD Interfacing.c
 *
 * Created: 7/20/2023 12:53:19 PM
 * Author : ahmed
 */ 

#include "lcd.h"

int main(void)
{
    /* Replace with your application code */
    LCD_init();
	while (1) 
    {
		LCD_displayString("Numbers Display");
		LCD_GoToXY(2,0);
		LCD_displayInteger(23);
		LCD_GoToXY(2,8);
		LCD_displayRealNumber(23.5);
		_delay_ms(10000);
    }
}

