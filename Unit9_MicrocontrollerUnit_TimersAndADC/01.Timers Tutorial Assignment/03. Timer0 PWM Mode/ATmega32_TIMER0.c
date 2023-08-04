/*
 * ATmega32_TIMER0.c
 *
 * Created: 8/1/2023 6:25:04 AM
 *  Author: Ahmed Aref Omaira
 */ 
/******************************************
 *                                        *
 *                INCLUDES                *
 * 										  *
 ******************************************/
#include "ATmega32_TIMER0.h"


/******************************************
 *                                        *
 *     GLOBAL VARIABLES DEFINITION        *
 * 										  *
 ******************************************/
void (*GPtr_TIMER0_IRQCallBack[2])(void) = {NULL};
uint16_t Timer0NumberOfOverflowOccurence;


/*********************************************
 *                                           *
 *         IRQ HANDLERS DEFINITION           *
 * 							    			 *
 *********************************************/
ISR(TIMER0_CTC_IRQHandler) {
	if (GPtr_TIMER0_IRQCallBack[TIMER0_CTC_VECTOR_ID] != NULL) {
		//Call Back C function() which will be called once IRQ happen
		GPtr_TIMER0_IRQCallBack[TIMER0_CTC_VECTOR_ID]();
	}
}

ISR(TIMER0_OVF_IRQHandler) {
	if (GPtr_TIMER0_IRQCallBack[TIMER0_OVF_VECTOR_ID] != NULL) {
		//Call Back C function() which will be called once IRQ happen
		GPtr_TIMER0_IRQCallBack[TIMER0_OVF_VECTOR_ID]();
		Timer0NumberOfOverflowOccurence++;
	}
}
/******************************************
 *                                        *
 *         FUNCTIONS DEFINITION           *
 * 										  *
 ******************************************/
void MCAL_TIMER0_Init(TIMER0Configuration_t* TIMER0_Config){
		
	// 1. Select Timer Mode
	switch(TIMER0_Config->Timer0Mode){
		case(TIMER0_MODE_NORMAL):
			TCCR0->WGM00 = LOW;
			TCCR0->WGM01 = LOW;
		break;
		case(TIMER0_MODE_CTC):
			TCCR0->WGM00 = LOW;
			TCCR0->WGM01 = HIGH;
		break;
		case(TIMER0_MODE_Fast_PWM_Inverting):
			TCCR0->WGM00 = HIGH;
			TCCR0->WGM01 = HIGH;
			TCCR0->COM00 = HIGH;
			TCCR0->COM01 = HIGH;
		break;
		case(TIMER0_MODE_Fast_PWM_Noninverting):
			TCCR0->WGM00 = HIGH;
			TCCR0->WGM01 = HIGH;
			TCCR0->COM00 = LOW;
			TCCR0->COM01 = HIGH;		
		break;
		case(TIMER0_MODE_Phase_Correct_PWM_Set_DC):
			TCCR0->WGM00 = LOW;
			TCCR0->WGM01 = HIGH;
			TCCR0->COM00 = LOW;
			TCCR0->COM01 = HIGH;	
		break;
		case(TIMER0_MODE_Phase_Correct_PWM_Set_UC):
			TCCR0->WGM00 = LOW;
			TCCR0->WGM01 = HIGH;
			TCCR0->COM00 = HIGH;
			TCCR0->COM01 = HIGH;			
		break;
	}
	
	if ((TIMER0_Config->Timer0Mode != TIMER0_MODE_CTC) && (TIMER0_Config->Timer0Mode != TIMER0_MODE_NORMAL))
		GPIOB->DDR.bits.DD3 = HIGH;    //Configure OC0 (PINB3) as Output
		
	// 2. Select Clock Source
	switch(TIMER0_Config->Timer0ClockSource){
		case(TIMER0_CLOCK_SOURCE_INTERNAL_NO_PRESCALER):
			TCCR0->CS00 = HIGH;
			TCCR0->CS01 = LOW;
			TCCR0->CS02 = LOW;
		break;
		case(TIMER0_CLOCK_SOURCE_INTERNAL_PRESCALER_8):
			TCCR0->CS00 = LOW;
			TCCR0->CS01 = HIGH;
			TCCR0->CS02 = LOW;
		break;
		case(TIMER0_CLOCK_SOURCE_INTERNAL_PRESCALER_64):
			TCCR0->CS00 = HIGH;
			TCCR0->CS01 = HIGH;
			TCCR0->CS02 = LOW;
		break;
		case(TIMER0_CLOCK_SOURCE_INTERNAL_PRESCALER_256):
			TCCR0->CS00 = LOW;
			TCCR0->CS01 = LOW;
			TCCR0->CS02 = HIGH;
		break;
		case(TIMER0_CLOCK_SOURCE_INTERNAL_PRESCALER_1024):
			TCCR0->CS00 = HIGH;
			TCCR0->CS01 = LOW;
			TCCR0->CS02 = HIGH;
		break;
		case(TIMER0_CLOCK_SOURCE_EXTERNAL_FALLING_EDGE):
			TCCR0->CS00 = LOW;
			TCCR0->CS01 = HIGH;
			TCCR0->CS02 = HIGH;
		break;
		case(TIMER0_CLOCK_SOURCE_EXTERNAL_RISING_EDGE):
			TCCR0->CS00 = HIGH;
			TCCR0->CS01 = HIGH;
			TCCR0->CS02 = HIGH;
		break;
	}
	if ((TIMER0_Config->Timer0ClockSource == TIMER0_CLOCK_SOURCE_EXTERNAL_RISING_EDGE) || (TIMER0_Config->Timer0ClockSource == TIMER0_CLOCK_SOURCE_EXTERNAL_FALLING_EDGE))
		GPIOB->DDR.bits.DD0 = LOW; //Configure T0 (PINB0) as Input
	
	// 3. Enable Or Disable IRQ
	switch(TIMER0_Config->Timer0IRQEnable){
		case(TIMER0_IRQ_ENABLE_TOIE0):
		TIMSK->TOIE0 = HIGH;
		break;
		case(TIMER0_IRQ_ENABLE_OCIE0):
		TIMSK->OCIE0 = HIGH;
		break;
	}
	if (TIMER0_Config->Timer0IRQEnable != TIMER0_IRQ_ENABLE_NONE)
		Enable_GlobalInterrupt();
	
	// 4. Call back ISR function
		switch(TIMER0_Config->Timer0IRQEnable){
			case(TIMER0_IRQ_ENABLE_TOIE0):
				GPtr_TIMER0_IRQCallBack[TIMER0_OVF_VECTOR_ID] = TIMER0_Config->P_IRQ_CallBack;
			break;
			case(TIMER0_IRQ_ENABLE_OCIE0):
				GPtr_TIMER0_IRQCallBack[TIMER0_CTC_VECTOR_ID] = TIMER0_Config->P_IRQ_CallBack;
			break;
		}
}
void MCAL_TIMER0_DeInit(void){
	/* Reset the Pre-scaler */
	TCCR0->CS00 = LOW;
	TCCR0->CS01 = LOW;
	TCCR0->CS02 = LOW;
}
void MCAL_TIMER0_GetCounterValue(uint8_t* TicksNumber){
	*TicksNumber = TCNT0;
}

void MCAL_TIMER0_SetCounterValue(uint8_t u8_TicksNumber){
	TCNT0 = u8_TicksNumber;
}

void MCAL_TIMER0_GetCompareValue(uint8_t* TicksNumber){
	 *TicksNumber = OCR0;
}
void MCAL_TIMER0_SetCompareValue(uint8_t  u8TicksNumber){
	OCR0 = u8TicksNumber;
}

void MCAL_TIMER0_GetOverflowCount(uint16_t* TicksNumber){
	*TicksNumber = Timer0NumberOfOverflowOccurence;
}

void MCAL_TIMER0_SetOverflowCount(uint16_t u8_TicksNumber){
	Timer0NumberOfOverflowOccurence = u8_TicksNumber;
}

void MCAL_TIMER0_SetPWMDutyCycle(TIMER0Configuration_t* TIMER0_Config,uint8_t Duty_Cycle){
		if(TIMER0_Config->Timer0Mode == TIMER0_MODE_Fast_PWM_Noninverting)
		{
			OCR0 = Duty_Cycle;
		}
		else if(TIMER0_Config->Timer0Mode == TIMER0_MODE_Fast_PWM_Inverting)
		{
			OCR0 = (uint8_t)(255 - Duty_Cycle);
		}
}