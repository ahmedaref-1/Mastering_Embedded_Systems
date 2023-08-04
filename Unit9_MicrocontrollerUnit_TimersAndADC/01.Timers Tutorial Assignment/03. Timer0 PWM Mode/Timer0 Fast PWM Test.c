/*
 * ATmega32.c
 *
 * Created: 7/29/2023 9:32:11 PM
 * Author : Ahmed Aref Omaira
 */ 
#include "ATmega32_GPIO.h"
#include "ATmega32_EXTERNALINTERRUPTS.h"
#include "ATmega32_TIMER0.h"



void GPIO_INIT(){
	/* Configure PIND5 as Output */
	GPIOConfiguration_t outputConfiguration;
	outputConfiguration.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
	outputConfiguration.GPIO_Pin = GPIO_PIN_5;
	MCAL_GPIO_Init(GPIOD,&outputConfiguration);
}

void TIMER0_INIT(){
	/* Configure Timer 0 */
	TIMER0Configuration_t timer0delay1SecConfiguration;
	timer0delay1SecConfiguration.P_IRQ_CallBack = NULL;
	timer0delay1SecConfiguration.Timer0ClockSource = TIMER0_CLOCK_SOURCE_INTERNAL_PRESCALER_8;
	timer0delay1SecConfiguration.Timer0IRQEnable = TIMER0_IRQ_ENABLE_NONE;
	timer0delay1SecConfiguration.Timer0Mode = TIMER0_MODE_Fast_PWM_Noninverting;
	MCAL_TIMER0_Init(&timer0delay1SecConfiguration);
	
}

int main(void)
{		
	GPIO_INIT();
	TIMER0_INIT();
	while (1){
		MCAL_TIMER0_SetPWMDutyCycle(128);
	}
}
