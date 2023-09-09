/*
 * STM32F103C6_LCD.c
 *
 *  Created on: Jul 25, 2023
 *      Author: Ahmed Aref Omaira
 */

/******************************************
 *                                        *
 *                INCLUDES                *
 * 										  *
 * ****************************************/
#include <STM32F103C6_LCD.h>

/******************************************
 *                                        *
 *         FUNCTIONS DEFINITION           *
 * 										  *
 * ****************************************/
/*******************************************
 *      INTERNALLY USED FUNCITONS          *
 * *****************************************/
void _delay_ms(uint32_t t)
{
	uint32_t i  , j;
	for(i = 0 ; i < t ; i++)
		for(j = 0 ; j < 255 ; j++);
}
void LCD_kick()
{
	MCAL_GPIO_WritePin(LCD_CTRL_PORT, LCD_EN_SWITCH, HIGH);
	_delay_ms(50);
	MCAL_GPIO_WritePin(LCD_CTRL_PORT, LCD_EN_SWITCH, LOW);
}
void LCD_GPIO_init() {
	GPIO_PinConfig_t PinConfiguration;
	// 1.Initializing the Control Switches Pins as Output
	PinConfiguration.GPIO_Mode = GPIO_MODE_Output_PP;
	PinConfiguration.GPIO_OutputSpeed = GPIO_SPEED_10MHz;

	PinConfiguration.GPIO_PinNumber = LCD_RS_SWITCH;
	MCAL_GPIO_Init(LCD_CTRL_PORT, &PinConfiguration);
	PinConfiguration.GPIO_PinNumber = LCD_RW_SWITCH;
	MCAL_GPIO_Init(LCD_CTRL_PORT, &PinConfiguration);
	PinConfiguration.GPIO_PinNumber = LCD_EN_SWITCH;
	MCAL_GPIO_Init(LCD_CTRL_PORT, &PinConfiguration);


	// 2.Initializing the Data Pins as Output
#if LCD_OPERATING_MODE==EIGHT_BIT_MODE
	PinConfiguration.GPIO_PinNumber = LCD_D0_PIN;
	MCAL_GPIO_Init(LCD_DATA_PORT, &PinConfiguration);
	PinConfiguration.GPIO_PinNumber = LCD_D1_PIN;
	MCAL_GPIO_Init(LCD_DATA_PORT, &PinConfiguration);
	PinConfiguration.GPIO_PinNumber = LCD_D2_PIN;
	MCAL_GPIO_Init(LCD_DATA_PORT, &PinConfiguration);
	PinConfiguration.GPIO_PinNumber = LCD_D3_PIN;
	MCAL_GPIO_Init(LCD_DATA_PORT, &PinConfiguration);
#endif
	PinConfiguration.GPIO_PinNumber = LCD_D4_PIN;
	MCAL_GPIO_Init(LCD_DATA_PORT, &PinConfiguration);
	PinConfiguration.GPIO_PinNumber = LCD_D5_PIN;
	MCAL_GPIO_Init(LCD_DATA_PORT, &PinConfiguration);
	PinConfiguration.GPIO_PinNumber = LCD_D6_PIN;
	MCAL_GPIO_Init(LCD_DATA_PORT, &PinConfiguration);
	PinConfiguration.GPIO_PinNumber = LCD_D7_PIN;
	MCAL_GPIO_Init(LCD_DATA_PORT, &PinConfiguration);

	// 3.Reset all the configuration pins
	MCAL_GPIO_WritePin(LCD_CTRL_PORT , LCD_RW_SWITCH , LOW);
	MCAL_GPIO_WritePin(LCD_CTRL_PORT , LCD_RS_SWITCH , LOW);
	MCAL_GPIO_WritePin(LCD_CTRL_PORT , LCD_EN_SWITCH , LOW);

}
/*******************************************
 *      APIs USED BY USER FUNCITONS        *
 *******************************************/
void LCD_isBusy(void){
	GPIO_PinConfig_t LCDconfig;
	// 1.Initializing the Data Pins as Input
	LCDconfig.GPIO_Mode = GPIO_MODE_Input_FLO;
	LCDconfig.GPIO_OutputSpeed = GPIO_SPEED_Input;
#if LCD_OPERATING_MODE==EIGHT_BIT_MODE
	LCDconfig.GPIO_PinNumber = LCD_D0_PIN;
	MCAL_GPIO_Init(LCD_DATA_PORT, &LCDconfig);
	LCDconfig.GPIO_PinNumber = LCD_D1_PIN;
	MCAL_GPIO_Init(LCD_DATA_PORT, &LCDconfig);
	LCDconfig.GPIO_PinNumber = LCD_D2_PIN;
	MCAL_GPIO_Init(LCD_DATA_PORT, &LCDconfig);
	LCDconfig.GPIO_PinNumber = LCD_D3_PIN;
	MCAL_GPIO_Init(LCD_DATA_PORT, &LCDconfig);
#endif
	LCDconfig.GPIO_PinNumber = LCD_D4_PIN;
	MCAL_GPIO_Init(LCD_DATA_PORT, &LCDconfig);
	LCDconfig.GPIO_PinNumber = LCD_D5_PIN;
	MCAL_GPIO_Init(LCD_DATA_PORT, &LCDconfig);
	LCDconfig.GPIO_PinNumber = LCD_D6_PIN;
	MCAL_GPIO_Init(LCD_DATA_PORT, &LCDconfig);
	LCDconfig.GPIO_PinNumber = LCD_D7_PIN;
	MCAL_GPIO_Init(LCD_DATA_PORT, &LCDconfig);

	MCAL_GPIO_WritePin(LCD_CTRL_PORT , LCD_RW_SWITCH , HIGH);
	MCAL_GPIO_WritePin(LCD_CTRL_PORT , LCD_RS_SWITCH , LOW);

	LCD_kick();

	MCAL_GPIO_WritePin(LCD_CTRL_PORT , LCD_RW_SWITCH , LOW);

}
void LCD_sendCommand(uint8_t command){
#if LCD_OPERATING_MODE == EIGHT_BIT_MODE
	MCAL_GPIO_WritePort(LCD_CTRL_PORT,command);
	MCAL_GPIO_WritePin(LCD_CTRL_PORT , LCD_RW_SWITCH , LOW);
	MCAL_GPIO_WritePin(LCD_CTRL_PORT , LCD_RS_SWITCH , LOW);
	_delay_ms(10);
	LCD_kick();
#endif
#if LCD_OPERATING_MODE == FOUR_BIT_MODE
	MCAL_GPIO_WritePort(LCD_CTRL_PORT,((MCAL_GPIO_ReadPort(LCD_CTRL_PORT) & 0xFF0F) | (command & 0xF0)));
	MCAL_GPIO_WritePin(LCD_CTRL_PORT , LCD_RW_SWITCH , LOW);
	MCAL_GPIO_WritePin(LCD_CTRL_PORT , LCD_RS_SWITCH , LOW);
	_delay_ms(10);
	LCD_kick();
	MCAL_GPIO_WritePort(LCD_CTRL_PORT,((MCAL_GPIO_ReadPort(LCD_CTRL_PORT) & 0xFF0F) | ((command & 0x0F) << FOUR_BIT_MODE)));
	MCAL_GPIO_WritePin(LCD_CTRL_PORT , LCD_RW_SWITCH , LOW);
	MCAL_GPIO_WritePin(LCD_CTRL_PORT , LCD_RS_SWITCH , LOW);
	_delay_ms(10);
	LCD_kick();
#endif
}

void LCD_clearScreen (){
	LCD_sendCommand(LCD_CMD_CLEAR_SCREEN);
}
void LCD_init(void){
	_delay_ms(20);
	LCD_GPIO_init();
	_delay_ms(15);
	LCD_clearScreen();
#if LCD_OPERATING_MODE == EIGHT_BIT_MODE
	LCD_sendCommand(LCD_CMD_FUNCTION_8BIT_2LINES);
#endif
#if LCD_OPERATING_MODE == FOUR_BIT_MODE
	LCD_sendCommand(LCD_CMD_FUNCTION_4BIT_2LINES_1st_CMD);
	LCD_sendCommand(LCD_CMD_FUNCTION_4BIT_2LINES);
#endif
	LCD_sendCommand(LCD_CMD_ENTRY_MODE);
	LCD_sendCommand(LCD_CMD_BEGIN_AT_FIRST_ROW);
	LCD_sendCommand(LCD_CMD_DISP_ON_CURSOR_BLINK);
	_delay_ms(15);
}

void LCD_displayCharacter(unsigned char character){
#if LCD_OPERATING_MODE == EIGHT_BIT_MODE
	MCAL_GPIO_WritePort(LCD_DATA_PORT, character);
	MCAL_GPIO_WritePin(LCD_CTRL_PORT , LCD_RS_SWITCH , HIGH);
	MCAL_GPIO_WritePin(LCD_CTRL_PORT , LCD_RW_SWITCH , LOW);
	_delay_ms(10);
	LCD_kick();
#endif
#if LCD_OPERATING_MODE == FOUR_BIT_MODE
	MCAL_GPIO_WritePort(LCD_DATA_PORT, ((MCAL_GPIO_ReadPort(LCD_DATA_PORT) & 0xFF0F) | (character & 0xF0)));
	MCAL_GPIO_WritePin(LCD_CTRL_PORT , LCD_RS_SWITCH , HIGH);
	MCAL_GPIO_WritePin(LCD_CTRL_PORT , LCD_RW_SWITCH , LOW);
	_delay_ms(10);
	LCD_kick();
	MCAL_GPIO_WritePort(LCD_DATA_PORT, ((MCAL_GPIO_ReadPort(LCD_DATA_PORT) & 0xFF0F) | ((character & 0x0F) << FOUR_BIT_MODE)));
	MCAL_GPIO_WritePin(LCD_CTRL_PORT , LCD_RS_SWITCH , HIGH);
	MCAL_GPIO_WritePin(LCD_CTRL_PORT , LCD_RW_SWITCH , LOW);
	_delay_ms(10);
	LCD_kick();
#endif
		}
void LCD_displayString(char *string){
	uint8_t counter = 0;
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
		if(line == LCD_FIRST_LINE)
		{
			LCD_sendCommand(LCD_CMD_BEGIN_AT_FIRST_ROW + position);
		}
		else if(line == LCD_SECOND_LINE)
		{
			if (position < 16 && position >= 0){
				LCD_sendCommand(LCD_CMD_BEGIN_AT_SECOND_ROW + position);
			}
		}
	}
}
