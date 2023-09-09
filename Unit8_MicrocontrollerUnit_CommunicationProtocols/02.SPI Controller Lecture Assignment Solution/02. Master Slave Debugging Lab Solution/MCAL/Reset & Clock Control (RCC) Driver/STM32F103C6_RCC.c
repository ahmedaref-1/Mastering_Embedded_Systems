/*
 * STM32F103C6_RCC.c
 *
 *  Created on: Aug 30, 2023
 *      Author: ahmed
 */

/******************************************
 *                                        *
 *                INCLUDES                *
 * 										  *
 * ****************************************/
#include"STM32F103C6_RCC.h"


/******************************************
 *                                        *
 *      PRESCALERS ARRAYS DEFINITION      *
 * 										  *
 * ****************************************/
static const uint8_t APB_preScalerTable[8] = {0,0,0,0,1,2,3,4};
static const uint8_t AHB_preScalerTable[16] = {0,0,0,0,0,0,0,0,1,2,3,4,5,6,7,8};

/******************************************
 *                                        *
 *         FUNCTIONS DEFINITION           *
 * 										  *
 * ****************************************/
void MCAL_RCC_PERIPHERAL_EN(uint8_t peripheral){
	switch(peripheral){
	case RCC_GPIOA: 	RCC->APB2ENR.IOPAEN 	= HIGH;  break;
	case RCC_GPIOB: 	RCC->APB2ENR.IOPBEN 	= HIGH;  break;
	case RCC_GPIOC: 	RCC->APB2ENR.IOPCEN 	= HIGH;  break;
	case RCC_GPIOD: 	RCC->APB2ENR.IOPDEN 	= HIGH;  break;
	case RCC_GPIOE: 	RCC->APB2ENR.IOPEEN 	= HIGH;  break;
	case RCC_AFIO:		RCC->APB2ENR.AFIOEN 	= HIGH;  break;
	case RCC_USART1:	RCC->APB2ENR.USART1EN 	= HIGH;  break;
	case RCC_USART2:	RCC->APB1ENR.USART2EN 	= HIGH;  break;
	case RCC_USART3:	RCC->APB1ENR.USART3EN 	= HIGH;  break;
	case RCC_SPI1:		RCC->APB2ENR.SPI1EN 	= HIGH;  break;
	case RCC_SPI2:		RCC->APB1ENR.SPI2EN 	= HIGH;  break;
	default: /* Do Nothing */ break;
	}
}


void MCAL_RCC_PERIPHERAL_DS(uint8_t peripheral){
	switch(peripheral){
	case RCC_GPIOA: 	RCC->APB2RSTR.IOPARST 	= HIGH;  break;
	case RCC_GPIOB: 	RCC->APB2RSTR.IOPBRST 	= HIGH;  break;
	case RCC_GPIOC: 	RCC->APB2RSTR.IOPCRST 	= HIGH;  break;
	case RCC_GPIOD: 	RCC->APB2RSTR.IOPDRST 	= HIGH;  break;
	case RCC_GPIOE: 	RCC->APB2RSTR.IOPERST 	= HIGH;  break;
	case RCC_AFIO:		RCC->APB2RSTR.AFIORST 	= HIGH;  break;
	case RCC_USART1:	RCC->APB2RSTR.USART1RST = HIGH;  break;
	case RCC_USART2:	RCC->APB1RSTR.USART2RST = HIGH;  break;
	case RCC_USART3:	RCC->APB1RSTR.USART3RST = HIGH;  break;
	case RCC_SPI1:		RCC->APB2RSTR.SPI1RST 	= HIGH;  break;
	case RCC_SPI2:		RCC->APB1RSTR.SPI2RST 	= HIGH;  break;
	default: /* Do Nothing */ break;
	}
}


void MCAL_RCC_CLKSRCSEL(uint8_t clockSource){
	switch(clockSource){
	case RCC_SELECT_HSI_CLKSRC:
		RCC->CR.HSION = HIGH; 				  	    // 01.Internal 8 MHz RC oscillator ON
		while(!(RCC->CR.HSIRDY)); 			        // 02.Wait until internal clock is ready
		RCC->CFGR.SW = 0b00;			  			// 03.HSI selected as system clock
		while(!(RCC->CFGR.SWS == 0b00));            // 04.Wait until HSI is the clock source
		RCC->CR.HSEON = LOW ;						// 05. HSE oscillator OFF
		RCC->CR.PLLON = LOW ;						// 06. PLL OFF
		break;
	case RCC_SELECT_HSE_CLKSRC:
		RCC->CR.HSEON = HIGH; 				  		// 01.HSE oscillator ON
		while(!(RCC->CR.HSERDY)); 			        // 02.Wait until external clock is ready			  			// 03.Clear previous clock selection
		RCC->CFGR.SW = 0b01;						// 03.Set External oscillator HSE as clock source
		while(!(RCC->CFGR.SWS == 0b01));            // 04.Wait until HSE is the clock source
		RCC->CR.HSION = LOW;						// 05.internal 8 MHz RC oscillator OFF
		RCC->CR.PLLON = LOW;						// 06. PLL OFF
		break;
	case RCC_SELECT_PLL_CLKSRC:
		/* TODO: Implement PLL Configuration */
		break;
	default: /* Do Nothing */ break;
	}
}


uint32_t MCAL_RCC_GetSYSCLKFreq(void){
		uint32_t returnValue;
		switch((RCC->CFGR.SWS)){
		case 0:
			returnValue = HSI_CLKFREQ;
			break;
		case 1:
			returnValue = HSE_CLKFREQ;
			break;
		case 2:
			/* TODO: Need to calculate the PLLCLK and PLLMUL and PLL Source MUX */
			break;
		default: returnValue = 0; break;
		}
		return returnValue;
}


uint32_t MCAL_RCC_GetHCLKFreq(void){
	return (MCAL_RCC_GetSYSCLKFreq()>>(AHB_preScalerTable[RCC->CFGR.HPRE]));
}


uint32_t MCAL_RCC_GetPCLK1Freq(void){
	return (MCAL_RCC_GetHCLKFreq()>>(APB_preScalerTable[RCC->CFGR.PPRE1]));
}


uint32_t MCAL_RCC_GetPCLK2Freq(void){
	return (MCAL_RCC_GetHCLKFreq()>>(APB_preScalerTable[RCC->CFGR.PPRE2]));
}
