/*
 * STM32F103C6_RCC.h
 *
 *  Created on: Aug 30, 2023
 *      Author: ahmed
 */

#ifndef STM32F103C6_RCC_H_
#define STM32F103C6_RCC_H_

/******************************************
 *                                        *
 *                INCLUDES                *
 * 										  *
 * ****************************************/
#include <STM32F103C6_REGISTERS.h>


/******************************************
 *                                        *
 *        CLOCK DEFINITION MACROS         *
 * 										  *
 * ****************************************/
#define HSE_CLKFREQ 	(uint32_t)(16000000)
#define HSI_CLKFREQ     (uint32_t)(8000000)


/*********************************************
 *                                           *
 *    RCC CONFIGURATION MACROS DEFINITION    *
 *                                           *
 *********************************************/
/*******************************************
 *     @ref RCC_CLOCK_SOURCE_define        *
 * *****************************************/
#define RCC_SELECT_HSI_CLKSRC	(uint8_t)0x00
#define RCC_SELECT_HSE_CLKSRC	(uint8_t)0x01
#define RCC_SELECT_PLL_CLKSRC	(uint8_t)0x02

/*******************************************
 *     @ref RCC_PERIPHERALS_define         *
 * *****************************************/
#define RCC_GPIOA		(uint8_t)0x00
#define RCC_GPIOB		(uint8_t)0x01
#define RCC_GPIOC		(uint8_t)0x02
#define RCC_GPIOD		(uint8_t)0x03
#define RCC_GPIOE		(uint8_t)0x04
#define RCC_AFIO		(uint8_t)0x05
#define RCC_USART1		(uint8_t)0x06
#define RCC_USART2		(uint8_t)0x07
#define RCC_USART3		(uint8_t)0x08
#define RCC_SPI1        (uint8_t)0x09
#define RCC_SPI2        (uint8_t)0x0A


/*********************************************
 *                                           *
 *    APIs SUPPORTED BY MCAL RCC DRIVER      *
 *                                           *
 *********************************************/
void MCAL_RCC_PERIPHERAL_EN(uint8_t peripheral);
void MCAL_RCC_PERIPHERAL_DS(uint8_t peripheral);
void MCAL_RCC_CLKSRCSEL(uint8_t clockSource);
uint32_t MCAL_RCC_GetSYSCLKFreq(void);
uint32_t MCAL_RCC_GetHCLKFreq(void);
uint32_t MCAL_RCC_GetPCLK1Freq(void);
uint32_t MCAL_RCC_GetPCLK2Freq(void);

#endif /*STM32F103C6_RCC_H_ */
