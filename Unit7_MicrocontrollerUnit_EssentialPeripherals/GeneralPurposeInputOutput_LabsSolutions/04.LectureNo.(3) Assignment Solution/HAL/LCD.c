/*
 * LCD.c
 *
 *  Created on: Jul 23, 2023
 *      Author: Ahmed Aref Omaira
 */
/******************************************
 *                                        *
 *                INCLUDES                *
 * 										  *
 * ****************************************/
#include "lCD.h"

/******************************************
 *                                        *
 *         FUNCTIONS DEFINITION           *
 * 										  *
 * ****************************************/
/*******************************************
 *      INTERNALLY USED FUNCITONS          *
 * *****************************************/
void _delay_ms(int t)
{
	int i  , j;
	for(i = 0 ; i < t ; i++)
		for(j = 0 ; j < 255 ; j++);
}
void LCD_kick()
{
	// Make PIN(E) disabled, To ensure that doesn't exist any command is executing while checking LCD BUSY
	MCAL_GPIO_WritePin(LCD_CTRL_PORT, LCD_EN_SWITCH, LOW);
	_delay_ms(50);
	// Return PIN(E) enabled,To execute any command I want after then
	MCAL_GPIO_WritePin(LCD_CTRL_PORT, LCD_EN_SWITCH, HIGH);
}
/*******************************************
 *      APIs USED BY USER FUNCITONS        *
 *******************************************/
void LCD_isBusy(void){
	GPIO_PinConfig_t LCDconfig;

	#ifdef EIGHT_BIT_MODE

		LCDconfig.GPIO_PinNumber = GPIO_PIN_0;
		LCDconfig.GPIO_Mode = GPIO_MODE_Input_FLO;
		LCDconfig.GPIO_OutputSpeed = GPIO_SPEED_Input;
		MCAL_GPIO_Init(LCD_DATA_PORT, &LCDconfig);

		LCDconfig.GPIO_PinNumber = GPIO_PIN_1;
		LCDconfig.GPIO_Mode = GPIO_MODE_Input_FLO;
		LCDconfig.GPIO_OutputSpeed = GPIO_SPEED_Input;
		MCAL_GPIO_Init(LCD_DATA_PORT, &LCDconfig);

		LCDconfig.GPIO_PinNumber = GPIO_PIN_2;
		LCDconfig.GPIO_Mode = GPIO_MODE_Input_FLO;
		LCDconfig.GPIO_OutputSpeed = GPIO_SPEED_Input;
		MCAL_GPIO_Init(LCD_DATA_PORT, &LCDconfig);

		LCDconfig.GPIO_PinNumber = GPIO_PIN_3;
		LCDconfig.GPIO_Mode = GPIO_MODE_Input_FLO;
		LCDconfig.GPIO_OutputSpeed = GPIO_SPEED_Input;
		MCAL_GPIO_Init(LCD_DATA_PORT, &LCDconfig);

		LCDconfig.GPIO_PinNumber = GPIO_PIN_4;
		LCDconfig.GPIO_Mode = GPIO_MODE_Input_FLO;
		LCDconfig.GPIO_OutputSpeed = GPIO_SPEED_Input;
		MCAL_GPIO_Init(LCD_DATA_PORT, &LCDconfig);

		LCDconfig.GPIO_PinNumber = GPIO_PIN_5;
		LCDconfig.GPIO_Mode = GPIO_MODE_Input_FLO;
		LCDconfig.GPIO_OutputSpeed = GPIO_SPEED_Input;
		MCAL_GPIO_Init(LCD_DATA_PORT, &LCDconfig);

		LCDconfig.GPIO_PinNumber = GPIO_PIN_6;
		LCDconfig.GPIO_Mode = GPIO_MODE_Input_FLO;
		LCDconfig.GPIO_OutputSpeed = GPIO_SPEED_Input;
		MCAL_GPIO_Init(LCD_DATA_PORT, &LCDconfig);

		LCDconfig.GPIO_PinNumber = GPIO_PIN_7;
		LCDconfig.GPIO_Mode = GPIO_MODE_Input_FLO;
		LCDconfig.GPIO_OutputSpeed = GPIO_SPEED_Input;
		MCAL_GPIO_Init(LCD_DATA_PORT, &LCDconfig);

		MCAL_GPIO_WritePin(LCD_CTRL_PORT , LCD_RW_SWITCH , HIGH);
		MCAL_GPIO_WritePin(LCD_CTRL_PORT , LCD_RS_SWITCH , LOW);

		LCD_kick();

		LCDconfig.GPIO_PinNumber = GPIO_PIN_0;
		LCDconfig.GPIO_Mode = GPIO_MODE_Output_pp;
		LCDconfig.GPIO_OutputSpeed = GPIO_SPEED_10MHZ;
		MCAL_GPIO_Init(LCD_DATA_PORT, &LCDconfig);

		LCDconfig.GPIO_PinNumber = GPIO_PIN_1;
		LCDconfig.GPIO_Mode = GPIO_MODE_Output_pp;
		LCDconfig.GPIO_OutputSpeed = GPIO_SPEED_10MHZ;
		MCAL_GPIO_Init(LCD_DATA_PORT, &LCDconfig);

		LCDconfig.GPIO_PinNumber = GPIO_PIN_2;
		LCDconfig.GPIO_Mode = GPIO_MODE_Output_pp;
		LCDconfig.GPIO_OutputSpeed = GPIO_SPEED_10MHZ;
		MCAL_GPIO_Init(LCD_DATA_PORT, &LCDconfig);

		LCDconfig.GPIO_PinNumber = GPIO_PIN_3;
		LCDconfig.GPIO_Mode = GPIO_MODE_Output_pp;
		LCDconfig.GPIO_OutputSpeed = GPIO_SPEED_10MHZ;
		MCAL_GPIO_Init(LCD_DATA_PORT, &LCDconfig);

		LCDconfig.GPIO_PinNumber = GPIO_PIN_4;
		LCDconfig.GPIO_Mode = GPIO_MODE_Output_pp;
		LCDconfig.GPIO_OutputSpeed = GPIO_SPEED_10MHZ;
		MCAL_GPIO_Init(LCD_DATA_PORT, &LCDconfig);

		LCDconfig.GPIO_PinNumber = GPIO_PIN_5;
		LCDconfig.GPIO_Mode = GPIO_MODE_Output_pp;
		LCDconfig.GPIO_OutputSpeed = GPIO_SPEED_10MHZ;
		MCAL_GPIO_Init(LCD_DATA_PORT, &LCDconfig);

		LCDconfig.GPIO_PinNumber = GPIO_PIN_6;
		LCDconfig.GPIO_Mode = GPIO_MODE_Output_pp;
		LCDconfig.GPIO_OutputSpeed = GPIO_SPEED_10MHZ;
		MCAL_GPIO_Init(LCD_DATA_PORT, &LCDconfig);

		LCDconfig.GPIO_PinNumber = GPIO_PIN_7;
		LCDconfig.GPIO_Mode = GPIO_MODE_Output_pp;
		LCDconfig.GPIO_OutputSpeed = GPIO_SPEED_10MHZ;
		MCAL_GPIO_Init(LCD_DATA_PORT, &LCDconfig);

	#endif

	#ifdef FOUR_BIT_MODE

		LCDconfig.GPIO_PinNumber = GPIO_PIN_4;
		LCDconfig.GPIO_Mode = GPIO_MODE_Input_FLO;
		LCDconfig.GPIO_OutputSpeed = GPIO_SPEED_Input;
		MCAL_GPIO_Init(LCD_DATA_PORT, &LCDconfig);

		LCDconfig.GPIO_PinNumber = GPIO_PIN_5;
		LCDconfig.GPIO_Mode = GPIO_MODE_Input_FLO;
		LCDconfig.GPIO_OutputSpeed = GPIO_SPEED_Input;
		MCAL_GPIO_Init(LCD_DATA_PORT, &LCDconfig);

		LCDconfig.GPIO_PinNumber = GPIO_PIN_6;
		LCDconfig.GPIO_Mode = GPIO_MODE_Input_FLO;
		LCDconfig.GPIO_OutputSpeed = GPIO_SPEED_Input;
		MCAL_GPIO_Init(LCD_DATA_PORT, &LCDconfig);

		LCDconfig.GPIO_PinNumber = GPIO_PIN_7;
		LCDconfig.GPIO_Mode = GPIO_MODE_Input_FLO;
		LCDconfig.GPIO_OutputSpeed = GPIO_SPEED_Input;
		MCAL_GPIO_Init(LCD_DATA_PORT, &LCDconfig);

		MCAL_GPIO_WritePin(LCD_CTRL_PORT , LCD_RW_SWITCH , HIGH);
		MCAL_GPIO_WritePin(LCD_CTRL_PORT , LCD_EN_SWITCH , LOW);

		LCD_kick();

		LCDconfig.GPIO_PinNumber = GPIO_PIN_4;
		LCDconfig.GPIO_Mode = GPIO_MODE_Output_pp;
		LCDconfig.GPIO_OutputSpeed = GPIO_SPEED_10MHZ;
		MCAL_GPIO_Init(LCD_DATA_PORT, &LCDconfig);

		LCDconfig.GPIO_PinNumber = GPIO_PIN_5;
		LCDconfig.GPIO_Mode = GPIO_MODE_Output_pp;
		LCDconfig.GPIO_OutputSpeed = GPIO_SPEED_10MHZ;
		MCAL_GPIO_Init(LCD_DATA_PORT, &LCDconfig);

		LCDconfig.GPIO_PinNumber = GPIO_PIN_6;
		LCDconfig.GPIO_Mode = GPIO_MODE_Output_pp;
		LCDconfig.GPIO_OutputSpeed = GPIO_SPEED_10MHZ;
		MCAL_GPIO_Init(LCD_DATA_PORT, &LCDconfig);

		LCDconfig.GPIO_PinNumber = GPIO_PIN_7;
		LCDconfig.GPIO_Mode = GPIO_MODE_Output_pp;
		LCDconfig.GPIO_OutputSpeed = GPIO_SPEED_10MHZ;
		MCAL_GPIO_Init(LCD_DATA_PORT, &LCDconfig);
	#endif

		MCAL_GPIO_WritePin(LCD_CTRL_PORT , LCD_RW_SWITCH , LOW);

}
void LCD_sendCommand(uint8_t command){
	LCD_isBusy();
#ifdef EIGHT_BIT_MODE
	MCAL_GPIO_WritePort(LCD_DATA_PORT,command);

	MCAL_GPIO_WritePin(LCD_CTRL_PORT , LCD_RW_SWITCH , LOW);
	MCAL_GPIO_WritePin(LCD_CTRL_PORT , LCD_RS_SWITCH , LOW);

	_delay_ms(1);

	LCD_kick();
#endif

#ifdef FOUR_BIT_MODE

	MCAL_GPIO_WritePort(LCD_DATA_PORT, ((MCAL_GPIO_ReadPort(LCD_DATA_PORT) & 0xFF0F) | (command & 0xF0)));

	MCAL_GPIO_WritePin(LCD_CTRL_PORT , LCD_RW_SWITCH , LOW);
	MCAL_GPIO_WritePin(LCD_CTRL_PORT , LCD_RS_SWITCH , LOW);

	_delay_ms(1);
	LCD_kick();

	MCAL_GPIO_WritePort(LCD_DATA_PORT, ((MCAL_GPIO_ReadPort(LCD_DATA_PORT) & 0xFF0F) | ((command & 0x0F) << DATA_SHIFT)));

	MCAL_GPIO_WritePin(LCD_CTRL_PORT , LCD_RW_SWITCH , LOW);
	MCAL_GPIO_WritePin(LCD_CTRL_PORT , LCD_RS_SWITCH , LOW);

	LCD_kick();
#endif
}

void LCD_clearScreen (){
	LCD_sendCommand(LCD_CMD_CLEAR_SCREEN);
}
void LCD_init(void){
	_delay_ms(20);

	LCD_isBusy();

	GPIO_PinConfig_t LCDconfig;
	LCDconfig.GPIO_PinNumber = LCD_RS_SWITCH;
	LCDconfig.GPIO_Mode = GPIO_MODE_Output_pp;
	LCDconfig.GPIO_OutputSpeed = GPIO_SPEED_10MHZ;
	MCAL_GPIO_Init(LCD_DATA_PORT, &LCDconfig);

	LCDconfig.GPIO_PinNumber = LCD_RW_SWITCH;
	LCDconfig.GPIO_Mode = GPIO_MODE_Output_pp;
	LCDconfig.GPIO_OutputSpeed = GPIO_SPEED_10MHZ;
	MCAL_GPIO_Init(LCD_DATA_PORT, &LCDconfig);

	LCDconfig.GPIO_PinNumber = LCD_EN_SWITCH;
	LCDconfig.GPIO_Mode = GPIO_MODE_Output_pp;
	LCDconfig.GPIO_OutputSpeed = GPIO_SPEED_10MHZ;
	MCAL_GPIO_Init(LCD_DATA_PORT, &LCDconfig);


#ifdef EIGHT_BIT_MODE

	MCAL_GPIO_WritePin(LCD_CTRL_PORT , LCD_RW_SWITCH , LOW);
	MCAL_GPIO_WritePin(LCD_CTRL_PORT , LCD_RS_SWITCH , LOW);
	MCAL_GPIO_WritePin(LCD_CTRL_PORT , LCD_EN_SWITCH , LOW);

	//for stm32
	LCDconfig.GPIO_PinNumber = GPIO_PIN_0;
	LCDconfig.GPIO_Mode = GPIO_MODE_Output_pp;
	LCDconfig.GPIO_OutputSpeed = GPIO_SPEED_10MHZ;
	MCAL_GPIO_Init(LCD_DATA_PORT, &LCDconfig);

	LCDconfig.GPIO_PinNumber = GPIO_PIN_1;
	LCDconfig.GPIO_Mode = GPIO_MODE_Output_pp;
	LCDconfig.GPIO_OutputSpeed = GPIO_SPEED_10MHZ;
	MCAL_GPIO_Init(LCD_DATA_PORT, &LCDconfig);

	LCDconfig.GPIO_PinNumber = GPIO_PIN_2;
	LCDconfig.GPIO_Mode = GPIO_MODE_Output_pp;
	LCDconfig.GPIO_OutputSpeed = GPIO_SPEED_10MHZ;
	MCAL_GPIO_Init(LCD_DATA_PORT, &LCDconfig);

	LCDconfig.GPIO_PinNumber = GPIO_PIN_3;
	LCDconfig.GPIO_Mode = GPIO_MODE_Output_pp;
	LCDconfig.GPIO_OutputSpeed = GPIO_SPEED_10MHZ;
	MCAL_GPIO_Init(LCD_DATA_PORT, &LCDconfig);

	LCDconfig.GPIO_PinNumber = GPIO_PIN_4;
	LCDconfig.GPIO_Mode = GPIO_MODE_Output_pp;
	LCDconfig.GPIO_OutputSpeed = GPIO_SPEED_10MHZ;
	MCAL_GPIO_Init(LCD_DATA_PORT, &LCDconfig);

	LCDconfig.GPIO_PinNumber = GPIO_PIN_5;
	LCDconfig.GPIO_Mode = GPIO_MODE_Output_pp;
	LCDconfig.GPIO_OutputSpeed = GPIO_SPEED_10MHZ;
	MCAL_GPIO_Init(LCD_DATA_PORT, &LCDconfig);

	LCDconfig.GPIO_PinNumber = GPIO_PIN_6;
	LCDconfig.GPIO_Mode = GPIO_MODE_Output_pp;
	LCDconfig.GPIO_OutputSpeed = GPIO_SPEED_10MHZ;
	MCAL_GPIO_Init(LCD_DATA_PORT, &LCDconfig);

	LCDconfig.GPIO_PinNumber = GPIO_PIN_7;
	LCDconfig.GPIO_Mode = GPIO_MODE_Output_pp;
	LCDconfig.GPIO_OutputSpeed = GPIO_SPEED_10MHZ;
	MCAL_GPIO_Init(LCD_DATA_PORT, &LCDconfig);

	_delay_ms(15);

	LCD_clearScreen();
	LCD_sendCommand(LCD_CMD_FUNCTION_8BIT_2LINES);
#endif

#ifdef FOUR_BIT_MODE

	MCAL_GPIO_WritePin(LCD_CTRL_PORT , LCD_RW_SWITCH , LOW);
	MCAL_GPIO_WritePin(LCD_CTRL_PORT , LCD_RS_SWITCH , LOW);
	MCAL_GPIO_WritePin(LCD_CTRL_PORT , LCD_EN_SWITCH , LOW);

	LCDconfig.GPIO_PinNumber = GPIO_PIN_4;
	LCDconfig.GPIO_Mode = GPIO_MODE_Output_pp;
	LCDconfig.GPIO_OutputSpeed = GPIO_SPEED_10MHZ;
	MCAL_GPIO_Init(LCD_DATA_PORT, &LCDconfig);

	LCDconfig.GPIO_PinNumber = GPIO_PIN_5;
	LCDconfig.GPIO_Mode = GPIO_MODE_Output_pp;
	LCDconfig.GPIO_OutputSpeed = GPIO_SPEED_10MHZ;
	MCAL_GPIO_Init(LCD_DATA_PORT, &LCDconfig);

	LCDconfig.GPIO_PinNumber = GPIO_PIN_6;
	LCDconfig.GPIO_Mode = GPIO_MODE_Output_pp;
	LCDconfig.GPIO_OutputSpeed = GPIO_SPEED_10MHZ;
	MCAL_GPIO_Init(LCD_DATA_PORT, &LCDconfig);

	LCDconfig.GPIO_PinNumber = GPIO_PIN_7;
	LCDconfig.GPIO_Mode = GPIO_MODE_Output_pp;
	LCDconfig.GPIO_OutputSpeed = GPIO_SPEED_10MHZ;
	MCAL_GPIO_Init(LCD_DATA_PORT, &LCDconfig);

	_delay_ms(15);

	LCD_clearScreen
	LCD_sendCommand(LCD_CMD_FUNCTION_4BIT_2LINES_1st_CMD);
	LCD_sendCommand(LCD_CMD_FUNCTION_4BIT_2LINES);
#endif


	LCD_sendCommand(LCD_CMD_ENTRY_MODE);
	LCD_sendCommand(LCD_CMD_BEGIN_AT_FIRST_ROW);
	LCD_sendCommand(LCD_CMD_DISP_ON_CURSOR_BLINK);
}

void LCD_displayCharacter(unsigned char character){
	LCD_isBusy();
	#ifdef EIGHT_BIT_MODE

		MCAL_GPIO_WritePort(LCD_DATA_PORT, character);
		MCAL_GPIO_WritePin(LCD_CTRL_PORT , LCD_RS_SWITCH , HIGH);
		MCAL_GPIO_WritePin(LCD_CTRL_PORT , LCD_RW_SWITCH , LOW);
		LCD_kick();

	#endif

	#ifdef FOUR_BIT_MODE
			MCAL_GPIO_WritePort(LCD_DATA_PORT, ((MCAL_GPIO_ReadPort(LCD_DATA_PORT) & 0xFF0F) | (character & 0xF0)));
			MCAL_GPIO_WritePin(LCD_CTRL_PORT , LCD_RS_SWITCH , HIGH);
			MCAL_GPIO_WritePin(LCD_CTRL_PORT , LCD_RW_SWITCH , LOW);
			LCD_kick();

			MCAL_GPIO_WritePort(LCD_DATA_PORT, ((MCAL_GPIO_ReadPort(LCD_DATA_PORT) & 0xFF0F) | ((character & 0x0F) << DATA_SHIFT)));
			MCAL_GPIO_WritePin(LCD_CTRL_PORT , LCD_RS_SWITCH , HIGH);
			MCAL_GPIO_WritePin(LCD_CTRL_PORT , LCD_RW_SWITCH , LOW);
			LCD_kick();

	#endif
		}
void LCD_displayString(char *string){
	volatile static char counter = 0;
		while(*string != 0)
		{
			LCD_displayCharacter(*string ++);
			counter++;
			if(counter == 16)
			{
				LCD_GoToXY(LCD_SECOND_LINE, LCD_FIRST_COLUMN);
			}

			else if(counter == 32)
			{
				LCD_sendCommand(LCD_CMD_CLEAR_SCREEN);
				LCD_GoToXY(LCD_FIRST_LINE, LCD_FIRST_COLUMN);
				counter = 0 ;
			}

		}
}
void LCD_GoToXY(unsigned char line, unsigned char position){
	if((position >= 0) && (position < 16))
	{
		if(line == 1)
		{
			LCD_sendCommand(LCD_CMD_BEGIN_AT_FIRST_ROW + position);
		}
		else if(line == 2)
		{
			LCD_sendCommand(LCD_CMD_BEGIN_AT_SECOND_ROW + position);
		}
	}

}

