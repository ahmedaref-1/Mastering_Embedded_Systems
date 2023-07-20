/*
 * lcd.c
 *
 * Created: 7/20/2023 1:23:58 PM
 *  Author: Ahmed Aref Omaira
 */ 
#include "lcd.h"
void LCD_kick()
{
	LCD_CTRL_PORT &=  ~(1<<LCD_EN_SWITCH); // Make PIN(E) disabled, To ensure that doesn't exist any command is executing while checking LCD BUSY
	_delay_ms(50);
	LCD_CTRL_PORT |=  (1<<LCD_EN_SWITCH); // Return PIN(E) enabled,To execute any command I want after then
}
void LCD_isBusy(void){
	#ifdef	EIGHT_BIT_MODE
	LCD_PORT_DATADIRECTION = 0x00; //  make the PORT connected with the LCD (D0--->D7) work as Input
	#endif
	#ifdef	FOUR_BIT_MODE
	LCD_PORT_DATADIRECTION &= ~(0xF << DATA_SHIFT); //  Mask the PORT connected with the LCD (D4-->D7) to work as Input
	#endif
	LCD_CTRL_PORT |=  (1<<LCD_RW_SWITCH); //read mode
	LCD_CTRL_PORT &=  ~(1<<LCD_RS_SWITCH); //command mode
	LCD_kick(); 
	LCD_PORT_DATADIRECTION = 0xFF; //  return PORTA work as Output
	LCD_CTRL_PORT &=  ~(1<<LCD_RW_SWITCH);
}
void LCD_clearScreen (){
	LCD_sendCommand(LCD_CLEAR_SCREEN);
}
void LCD_init(void){
	// 01.After power on, wait for Vcc rise to 4.5v
	_delay_ms(20);
	// 02.Check if the LCD is busy executing anything
	LCD_isBusy();
	// 03.Make (E,RS,RW) OUTPUT PINS
	LCD_CTRL_DATADIRECTION |= (1<<LCD_RW_SWITCH | 1<<LCD_RS_SWITCH | 1<<LCD_EN_SWITCH);
	// 04.Make control pins off to do (reset/set) according the command we want to do after then
	LCD_CTRL_PORT &= ~(1<<LCD_RW_SWITCH | 1<<LCD_RS_SWITCH | 1<<LCD_EN_SWITCH);
	// 05.Return PORTA work as Output
	LCD_PORT_DATADIRECTION = 0xFF; 
	// 06.Clear screen to be ready
	LCD_clearScreen();
	
	#ifdef	EIGHT_BIT_MODE
	LCD_sendCommand(LCD_FUNCTION_8BIT_2LINES);
	#endif
	
	#ifdef	FOUR_BIT_MODE
	LCD_sendCommand(0x02);
	LCD_sendCommand(LCD_FUNCTION_4BIT_2LINES);
	#endif
	// 07.Entry mode configuration 
	LCD_sendCommand(LCD_ENTRY_MODE);
	LCD_sendCommand(LCD_BEGIN_AT_FIRST_ROW);
	LCD_sendCommand(LCD_DISP_ON_CURSOR_BLINK);
	
}
void LCD_sendCommand(unsigned char command){
		LCD_isBusy();
		#ifdef	EIGHT_BIT_MODE
		LCD_DATA_PORT = command;
		LCD_CTRL_PORT &= ~(1<<LCD_RW_SWITCH | 1<<LCD_RS_SWITCH); // Write Command Mode
		LCD_kick();
		#endif
		#ifdef	FOUR_BIT_MODE
		// Send Most Significant 4 Bits in the command
		LCD_DATA_PORT = ((LCD_DATA_PORT & 0x0F) | (command & 0xF0));
		LCD_CTRL_PORT &= ~(1<<LCD_RW_SWITCH | 1<<LCD_RS_SWITCH); // Write Command Mode
		_delay_ms(1);
		LCD_kick();
		// Send Least Significant 4 Bits in the command
		LCD_DATA_PORT = (LCD_DATA_PORT & 0x0F) | (command << 4);
		LCD_CTRL_PORT &= ~(1<<LCD_RW_SWITCH | 1<<LCD_RS_SWITCH); // Write Command Mode
		_delay_ms(1);
		LCD_kick();
		#endif
		
}
void LCD_displayCharacter(unsigned char character){
		LCD_isBusy();
		#ifdef	EIGHT_BIT_MODE
		LCD_DATA_PORT = character;
		// Write data Mode
		LCD_CTRL_PORT &= ~(1<<LCD_RW_SWITCH);
		LCD_CTRL_PORT |= (1<<LCD_RS_SWITCH);
		LCD_kick();
		#endif
		#ifdef	FOUR_BIT_MODE
		// Send Most Significant 4 Bits in the data
		LCD_DATA_PORT = (LCD_DATA_PORT & 0x0F) | (character & 0xF0);
		// Write data Mode
		LCD_CTRL_PORT &= ~(1<<LCD_RW_SWITCH);
		LCD_CTRL_PORT |= (1<<LCD_RS_SWITCH);
		_delay_ms(1);
		LCD_kick();
		// Send Least Significant 4 Bits in the data
		LCD_DATA_PORT = (LCD_DATA_PORT & 0x0F) | (character << 4);
		// Write data Mode
		LCD_CTRL_PORT &= ~(1<<LCD_RW_SWITCH);
		LCD_CTRL_PORT |= (1<<LCD_RS_SWITCH);
		_delay_ms(1);
		LCD_kick();
		
		#endif
}
void LCD_displayString(char *string){
	unsigned char counter = 0;
	while(*string > 0 )
	{
		LCD_displayCharacter(*string++);
		counter++;
		if(counter == 16)
		{
			LCD_GoToXY(2,0);
		}
		else if(counter == 32)
		{
			LCD_sendCommand(LCD_CLEAR_SCREEN);
			LCD_GoToXY(1,0);
			counter = 0;
		}
	}
}
void LCD_GoToXY(unsigned char line, unsigned char position){
		if((position >= 0) && (position < 16))
		{
			if(line == 1)
			{
				LCD_sendCommand(LCD_BEGIN_AT_FIRST_ROW + position);
			}
			else if(line == 2)
			{
				LCD_sendCommand(LCD_BEGIN_AT_SECOND_ROW + position);
			}
		}

}
void LCD_displayInteger (int Number ){
		unsigned char str[10];
		// convert integer to string
		itoa(Number,str,10);
		// Display the string
		LCD_displayString(str);
}
void LCD_displayRealNumber (double  Number ){
	char str[16];
	
	char * Numsign = (Number< 0) ? "-" : "";
	int IntNum1 = Number ; // cast the integer Part of the number (653)
	float Float_Part = Number - IntNum1;// cast the Float Part of the number (0.0332)
	int IntNum2 = Float_Part * 10000 ; // turn into integer
	
	sprintf(str,"%s%d.%04d",Numsign,IntNum1,IntNum2);
	
	LCD_displayString(str); // Send string
}