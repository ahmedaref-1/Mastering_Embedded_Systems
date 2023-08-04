/*
 * ATmega32.c
 *
 * Created: 7/29/2023 9:32:11 PM
 * Author : Ahmed Aref Omaira
 */ 
#include "ATmega32_GPIO.h"
#include "ATmega32_EXTERNALINTERRUPTS.h"
#include "ATmega32_TIMER0.h"

void Timer_OverFlow_Interrupt_Handler(void)
{
	uint16_t NumberOfOccuredOverflows;
	MCAL_TIMER0_GetOverflowCount(&NumberOfOccuredOverflows);
	if( NumberOfOccuredOverflows == 3907) /* 3907 ---> 1 sec*/
	{
		/* Toggle Led every one second */
		MCAL_GPIO_TogglePin(GPIOD,GPIO_PIN_5);

		/* Clear Counter */
		MCAL_TIMER0_SetOverflowCount(0);
	}
}

void GPIO_INIT(){
	/* Configure PIND5 as Output */
	GPIOConfiguration_t outputConfiguration;
	outputConfiguration.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
	outputConfiguration.GPIO_Pin = GPIO_PIN_5;
	MCAL_GPIO_Init(GPIOD,&outputConfiguration);
}

void TIMER0_INIT(){
	/* Configure Timer 0 */
	MCAL_TIMER0_SetOverflowCount(3907);
	
	TIMER0Configuration_t timer0delay1SecConfiguration;
	timer0delay1SecConfiguration.P_IRQ_CallBack = Timer_OverFlow_Interrupt_Handler;
	timer0delay1SecConfiguration.Timer0ClockSource = TIMER0_CLOCK_SOURCE_INTERNAL_PRESCALER_8;
	timer0delay1SecConfiguration.Timer0IRQEnable = TIMER0_IRQ_ENABLE_TOIE0;
	timer0delay1SecConfiguration.Timer0Mode = TIMER0_MODE_NORMAL;
	MCAL_TIMER0_Init(&timer0delay1SecConfiguration);
	
}

int main(void)
{		
	GPIO_INIT();
	TIMER0_INIT();
	while (1){
		
	}
}
