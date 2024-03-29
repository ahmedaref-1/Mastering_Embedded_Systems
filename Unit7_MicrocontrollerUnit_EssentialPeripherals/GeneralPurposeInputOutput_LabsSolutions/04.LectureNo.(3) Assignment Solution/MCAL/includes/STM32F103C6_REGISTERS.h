/*
 * STM32F103C6_REGISTERS.h
 *
 *  Created on: Jul 25, 2023
 *      Author: Ahmed Aref Omaira
 */

#ifndef INCLUDES_STM32F103C6_REGISTERS_H_
#define INCLUDES_STM32F103C6_REGISTERS_H_
/******************************************
 *                                        *
 *                INCLUDES                *
 * 										  *
 * ****************************************/
#include <stdint.h>
#include <stdlib.h>



/******************************************
 *                                        *
 *        MEMORIES BASE ADDRESSES         *
 *                                        *
 ******************************************/
#define FLASH_MEMORY_BASE                                 0x08000000UL
#define SYSTEM_MEMORY_BASE                                0x1FFFF000UL
#define SRAM_MEMORY_BASE                                  0x20000000UL
#define PERIPHERALS_BASE                                  0x40000000UL
#define CORTEX_M3_INTERNAL_PERIPHERALS_BASE               0xE0000000UL


/******************************************
 *                                        *
 *     BUS PERIPHERALS BASE ADDRESSES     *
 *                                        *
 ******************************************/

/******************************************
 *   AHB BUS PERIPHERALS BASE ADDRESSES   *
 * ****************************************/
#define RCC_BASE                                  		  0x40021000UL

/******************************************
 *  APB1 BUS PERIPHERALS BASE ADDRESSES   *
 * ****************************************/

/******************************************
 *  APB2 BUS PERIPHERALS BASE ADDRESSES   *
 * ****************************************/
#define GPIOA_BASE                               		  0x40010800UL
#define GPIOB_BASE                               		  0x40010C00UL
#define GPIOC_BASE                                        0x40011000UL
#define GPIOD_BASE                                        0x40011400UL
#define GPIOE_BASE                                        0x40011800UL
#define EXIT_BASE                                         0x40010400UL
#define AFIO_BASE                                         0x40010000UL


/*********************************************
 *                                           *
 *     PERIPHERALS REGISTERS BASE ADDRESSES  *
 *                                           *
 *********************************************/

/**********************************************************
 *  RESET AND CONTROL PERIPHERAL REGISTERS BASE ADDRESSES *
 * ********************************************************/
/*********** RCC Registers' Bits ***********/
//TRM @ Section 7.3.11 on page 121

// Clock control register (RCC_CR)
typedef union{
	volatile uint32_t CR;
	struct{
		volatile uint32_t HSION		:1;
		volatile uint32_t HSIRDY	:1;
		volatile uint32_t Reserved	:1;
		volatile uint32_t HSITRIM	:5;
		volatile uint32_t HSICAL	:8;
		volatile uint32_t HSEON		:1;
		volatile uint32_t HSERDY	:1;
		volatile uint32_t HSEBYP	:1;
		volatile uint32_t CSSON		:1;
		volatile uint32_t Reserved0 :4;
		volatile uint32_t PLLON		:1;
		volatile uint32_t PLLRDY	:1;
		volatile uint32_t Reserved1	:6;
	};
}RCC_CR_t;

// Clock configuration register (RCC_CFGR)
typedef union{
	volatile uint32_t CFGR;
	struct{
		volatile uint32_t SW		:2;
		volatile uint32_t SWS		:2;
		volatile uint32_t HPRE		:4;
		volatile uint32_t PPRE1		:3;
		volatile uint32_t PPRE2		:3;
		volatile uint32_t ADCPRE	:2;
		volatile uint32_t PLLSRC	:1;
		volatile uint32_t PLLXTPRE	:1;
		volatile uint32_t PLLMUL	:4;
		volatile uint32_t USBPRE	:1;
		volatile uint32_t Res		:1;
		volatile uint32_t MCO		:3;
		volatile uint32_t Reserved	:5;
	};
}RCC_CFGR_t;

// Clock interrupt register (RCC_CIR)
typedef union{
	volatile uint32_t CIR;
	struct{
		volatile uint32_t LSIRDYF	:1;
		volatile uint32_t LSERDYF	:1;
		volatile uint32_t HSIRDYF	:1;
		volatile uint32_t HSERDYF	:1;
		volatile uint32_t PLLRDYF	:1;
		volatile uint32_t Reserved	:2;
		volatile uint32_t CSSF		:1;
		volatile uint32_t LSIRDYIE	:1;
		volatile uint32_t LSERDYIE	:1;
		volatile uint32_t HSIRDYIE	:1;
		volatile uint32_t HSERDYIE	:1;
		volatile uint32_t PLLRDYIE	:1;
		volatile uint32_t Reserved1	:3;
		volatile uint32_t LSIRDYC	:1;
		volatile uint32_t LSERDYC	:1;
		volatile uint32_t HSIRDYC	:1;
		volatile uint32_t HSERDYC	:1;
		volatile uint32_t PLLRDYC	:1;
		volatile uint32_t Reserved2	:2;
		volatile uint32_t CSSC		:1;
		volatile uint32_t Reserved3	:8;
	};
}RCC_CIR_t;

// APB2 peripheral reset register (RCC_APB2RSTR)
typedef union{
	volatile uint32_t APB2RSTR;
	struct{
		volatile uint32_t AFIORST	:1;
		volatile uint32_t Reserved	:1;
		volatile uint32_t IOPARST	:1;
		volatile uint32_t IOPBRST	:1;
		volatile uint32_t IOPCRST	:1;
		volatile uint32_t IOPDRST	:1;
		volatile uint32_t IOPERST	:1;
		volatile uint32_t IOPFRST	:1;
		volatile uint32_t IOPGRST	:1;
		volatile uint32_t ADC1RST	:1;
		volatile uint32_t ADC2RST	:1;
		volatile uint32_t TIM1RST	:1;
		volatile uint32_t SPI1RST	:1;
		volatile uint32_t TIM8RST	:1;
		volatile uint32_t USART1RST	:1;
		volatile uint32_t ADC3RST	:1;
		volatile uint32_t Reserved1	:3;
		volatile uint32_t TIM9RST	:1;
		volatile uint32_t TIM10RST	:1;
		volatile uint32_t TIM11RST	:1;
		volatile uint32_t Reserved2	:10;
	};
}RCC_APB2RSTR_t;

// APB1 peripheral reset register (RCC_APB1RSTR)
typedef union{
	volatile uint32_t APB1RSTR;
	struct{
		volatile uint32_t TIM2RST	:1;
		volatile uint32_t TIM3RST	:1;
		volatile uint32_t TIM4RST	:1;
		volatile uint32_t TIM5RST	:1;
		volatile uint32_t TIM6RST	:1;
		volatile uint32_t TIM7RST	:1;
		volatile uint32_t TIM12RST	:1;
		volatile uint32_t TIM13RST	:1;
		volatile uint32_t TIM14RST	:1;
		volatile uint32_t Reserved	:2;
		volatile uint32_t WWDGRST	:1;
		volatile uint32_t Reserved1	:2;
		volatile uint32_t SPI2RST	:1;
		volatile uint32_t SPI3RST	:1;
		volatile uint32_t Reserved2	:1;
		volatile uint32_t USART2RST	:1;
		volatile uint32_t USART3RST	:1;
		volatile uint32_t UART4RST	:1;
		volatile uint32_t UART5RST	:1;
		volatile uint32_t I2C1RST	:1;
		volatile uint32_t I2C2RST	:1;
		volatile uint32_t USBRST	:1;
		volatile uint32_t Reserved3	:1;
		volatile uint32_t CANRST	:1;
		volatile uint32_t Reserved4	:1;
		volatile uint32_t BKPRST	:1;
		volatile uint32_t PWRRST	:1;
		volatile uint32_t DACRST	:1;
		volatile uint32_t Reserved5	:2;
	};
}RCC_APB1RSTR_t;

// AHB peripheral clock enable register (RCC_AHBENR)
typedef union{
	volatile uint32_t AHBENR;
	struct{
		volatile uint32_t DMA1EN	:1;
		volatile uint32_t DMA2EN	:1;
		volatile uint32_t SRAMEN	:1;
		volatile uint32_t Reserved	:1;
		volatile uint32_t FLITFEN	:1;
		volatile uint32_t Reserved1	:1;
		volatile uint32_t CRCEN		:1;
		volatile uint32_t Reserved2	:1;
		volatile uint32_t FSMCEN	:1;
		volatile uint32_t Reserved3	:1;
		volatile uint32_t SDIOEN	:1;
		volatile uint32_t Reserved4	:21;
	};
}RCC_AHBENR_t;

// APB2 peripheral clock enable register (RCC_APB2ENR)
typedef union{
	volatile uint32_t APB2ENR;
	struct{
		volatile uint32_t AFIOEN	:1;
		volatile uint32_t Reserved	:1;
		volatile uint32_t IOPAEN	:1;
		volatile uint32_t IOPBEN	:1;
		volatile uint32_t IOPCEN	:1;
		volatile uint32_t IOPDEN	:1;
		volatile uint32_t IOPEEN	:1;
		volatile uint32_t IOPFEN	:1;
		volatile uint32_t IOPGEN	:1;
		volatile uint32_t ADC1EN	:1;
		volatile uint32_t ADC2EN	:1;
		volatile uint32_t TIM1EN	:1;
		volatile uint32_t SPI1EN	:1;
		volatile uint32_t TIM8EN	:1;
		volatile uint32_t USART1EN	:1;
		volatile uint32_t ADC3EN	:1;
		volatile uint32_t Reserved1	:3;
		volatile uint32_t TIM9EN	:1;
		volatile uint32_t TIM10EN	:1;
		volatile uint32_t TIM11EN	:1;
		volatile uint32_t Reserved2	:10;
	};
}RCC_APB2ENR_t;

// APB1 peripheral clock enable register (RCC_APB1ENR)
typedef union{
	volatile uint32_t APB1ENR;
	struct{
		volatile uint32_t TIM2EN	:1;
		volatile uint32_t TIM3EN	:1;
		volatile uint32_t TIM4EN	:1;
		volatile uint32_t TIM5EN	:1;
		volatile uint32_t TIM6EN	:1;
		volatile uint32_t TIM7EN	:1;
		volatile uint32_t TIM12EN	:1;
		volatile uint32_t TIM13EN	:1;
		volatile uint32_t TIM14EN	:1;
		volatile uint32_t Reserved	:2;
		volatile uint32_t WWDGEN	:1;
		volatile uint32_t Reserved1	:2;
		volatile uint32_t SPI2EN	:1;
		volatile uint32_t SPI3EN	:1;
		volatile uint32_t Reserved2	:1;
		volatile uint32_t USART2EN	:1;
		volatile uint32_t USART3EN	:1;
		volatile uint32_t UART4REN	:1;
		volatile uint32_t UART5EN	:1;
		volatile uint32_t I2C1EN	:1;
		volatile uint32_t I2C2EN	:1;
		volatile uint32_t USBEN		:1;
		volatile uint32_t Reserved3	:1;
		volatile uint32_t CANEN		:1;
		volatile uint32_t Reserved4	:1;
		volatile uint32_t BKPEN		:1;
		volatile uint32_t PWREN		:1;
		volatile uint32_t DACEN		:1;
		volatile uint32_t Reserved5	:2;
	};
}RCC_APB1ENR_t;

// Backup domain control register (RCC_BDCR)
typedef union{
	volatile uint32_t BDCR;
	struct{
		volatile uint32_t LSEON		:1;
		volatile uint32_t LSERDY	:1;
		volatile uint32_t LSEBYP	:1;
		volatile uint32_t Reserved	:5;
		volatile uint32_t RTCSEL	:2;
		volatile uint32_t Reserved1	:5;
		volatile uint32_t RTCEN		:1;
		volatile uint32_t BDRST		:1;
		volatile uint32_t Reserved2	:15;
	};
}RCC_BDCR_t;

// Control/status register (RCC_CSR)
typedef union{
	volatile uint32_t CSR;
	struct{
		volatile uint32_t LSION		:1;
		volatile uint32_t LSIRDY	:1;
		volatile uint32_t Reserved	:22;
		volatile uint32_t RMVF		:1;
		volatile uint32_t Reserved1	:1;
		volatile uint32_t PINRSTF	:1;
		volatile uint32_t PORRSTF	:1;
		volatile uint32_t SETRSTF	:1;
		volatile uint32_t IWDGRSTF	:1;
		volatile uint32_t WWDGRSTF	:1;
		volatile uint32_t LPWRRSTF	:1;
	};
}RCC_CSR_t;

/*********** RCC REGISTERS ***************/
typedef struct{
	volatile RCC_CR_t 		CR;
	volatile RCC_CFGR_t 	CFGR;
	volatile RCC_CIR_t  	CIR;
	volatile RCC_APB2RSTR_t APB2RSTR;
	volatile RCC_APB1RSTR_t APB1RSTR;
	volatile RCC_AHBENR_t 	AHBENR;
	volatile RCC_APB2ENR_t 	APB2ENR;
	volatile RCC_APB1ENR_t 	APB1ENR;
	volatile RCC_BDCR_t 	BDCR;
	volatile RCC_CSR_t 		CSR;
}RCC_t;

/***********************************************
 *   GPIO PREIPHERAL REGISTERS BASE ADDRESSES  *
 * *********************************************/
/************ GPIO Registers' Bits ***********/
//TRM @ Section 9.5 on page 194
// Port configuration register low (GPIOx_CRL) (x=A..G)
typedef union{
	volatile uint32_t CRL;
	struct{
		volatile uint32_t MODE0	:2;
		volatile uint32_t  CNF0	:2;
		volatile uint32_t MODE1	:2;
		volatile uint32_t  CNF1	:2;
		volatile uint32_t MODE2	:2;
		volatile uint32_t  CNF2	:2;
		volatile uint32_t MODE3	:2;
		volatile uint32_t  CNF3	:2;
		volatile uint32_t MODE4	:2;
		volatile uint32_t  CNF4	:2;
		volatile uint32_t MODE5	:2;
		volatile uint32_t  CNF5	:2;
		volatile uint32_t MODE6	:2;
		volatile uint32_t  CNF6	:2;
		volatile uint32_t MODE7	:2;
		volatile uint32_t  CNF7	:2;
	};
}GPIOx_CRL_t;

// Port configuration register high (GPIOx_CRH) (x=A..G)
typedef union{
	volatile uint32_t CRH;
	struct{
		volatile uint32_t  MODE8 :2;
		volatile uint32_t   CNF8 :2;
		volatile uint32_t  MODE9 :2;
		volatile uint32_t   CNF9 :2;
		volatile uint32_t MODE10 :2;
		volatile uint32_t  CNF10 :2;
		volatile uint32_t MODE11 :2;
		volatile uint32_t  CNF11 :2;
		volatile uint32_t MODE12 :2;
		volatile uint32_t  CNF12 :2;
		volatile uint32_t MODE13 :2;
		volatile uint32_t  CNF13 :2;
		volatile uint32_t MODE14 :2;
		volatile uint32_t  CNF14 :2;
		volatile uint32_t MODE15 :2;
		volatile uint32_t  CNF15 :2;
	};
}GPIOx_CRH_t;

// Port input data register (GPIOx_IDR) (x=A..G)
typedef union{
	volatile uint32_t IDR;
	struct{
		volatile uint32_t PIN_0		:1;
		volatile uint32_t PIN_1		:1;
		volatile uint32_t PIN_2		:1;
		volatile uint32_t PIN_3		:1;
		volatile uint32_t PIN_4		:1;
		volatile uint32_t PIN_5		:1;
		volatile uint32_t PIN_6		:1;
		volatile uint32_t PIN_7		:1;
		volatile uint32_t PIN_8		:1;
		volatile uint32_t PIN_9		:1;
		volatile uint32_t PIN_10	:1;
		volatile uint32_t PIN_11	:1;
		volatile uint32_t PIN_12	:1;
		volatile uint32_t PIN_13	:1;
		volatile uint32_t PIN_14	:1;
		volatile uint32_t PIN_15	:1;
		volatile uint32_t Reserved	:16;
	};
}GPIOx_IDR_t;

// Port output data register (GPIOx_ODR) (x=A..G)
typedef union{
	volatile uint32_t ODR;
	struct{
		volatile uint32_t PIN_0		:1;
		volatile uint32_t PIN_1		:1;
		volatile uint32_t PIN_2		:1;
		volatile uint32_t PIN_3		:1;
		volatile uint32_t PIN_4		:1;
		volatile uint32_t PIN_5		:1;
		volatile uint32_t PIN_6		:1;
		volatile uint32_t PIN_7		:1;
		volatile uint32_t PIN_8		:1;
		volatile uint32_t PIN_9		:1;
		volatile uint32_t PIN_10	:1;
		volatile uint32_t PIN_11	:1;
		volatile uint32_t PIN_12	:1;
		volatile uint32_t PIN_13	:1;
		volatile uint32_t PIN_14	:1;
		volatile uint32_t PIN_15	:1;
		volatile uint32_t Reserved	:16;
	};
}GPIOx_ODR_t;

// Port bit set/reset register (GPIOx_BSRR) (x=A..G)
typedef union{
	volatile uint32_t BSRR;
	struct{
		volatile uint32_t BS	:16;
		volatile uint32_t BR	:16;
	};
}GPIOx_BSRR_t;

// Port bit reset register (GPIOx_BRR) (x=A..G)
typedef union{
	volatile uint32_t BRR;
	struct{
		volatile uint32_t BR		:16;
		volatile uint32_t Reserved	:16;
	};
}GPIOx_BRR_t;

// Port configuration lock register (GPIOx_LCKR) (x=A..G)
typedef union{
	volatile uint32_t LCKR;
	struct{
		volatile uint32_t PIN_0		:1;
		volatile uint32_t PIN_1		:1;
		volatile uint32_t PIN_2		:1;
		volatile uint32_t PIN_3		:1;
		volatile uint32_t PIN_4		:1;
		volatile uint32_t PIN_5		:1;
		volatile uint32_t PIN_6		:1;
		volatile uint32_t PIN_7		:1;
		volatile uint32_t PIN_8		:1;
		volatile uint32_t PIN_9		:1;
		volatile uint32_t PIN_10	:1;
		volatile uint32_t PIN_11	:1;
		volatile uint32_t PIN_12	:1;
		volatile uint32_t PIN_13	:1;
		volatile uint32_t PIN_14	:1;
		volatile uint32_t PIN_15	:1;
		volatile uint32_t LCKK		:1;
		volatile uint32_t Reserved	:15;
	};
}GPIOx_LCKR_t;

/*********** GPIO Registers ***********/
typedef struct{
	GPIOx_CRL_t 	CRL;
	GPIOx_CRH_t 	CRH;
	GPIOx_IDR_t 	IDR;
	GPIOx_ODR_t 	ODR;
	GPIOx_BSRR_t 	BSRR;
	GPIOx_BRR_t 	BRR;
	GPIOx_LCKR_t 	LCKR;
}GPIO_t;

/*************************************************************
 *  EXTERNAL INTERRUPTS PERIPHERAL REGISTERS BASE ADDRESSES  *
 * ***********************************************************/
/*********** EXTI Registers' Bits ***********/
//TRM @ Section 10.3.7 on page 214
// Interrupt mask register (EXTI_IMR)
typedef union{
	volatile uint32_t IMR;
	struct{
		volatile uint32_t MR0		:1;
		volatile uint32_t MR1		:1;
		volatile uint32_t MR2		:1;
		volatile uint32_t MR3		:1;
		volatile uint32_t MR4		:1;
		volatile uint32_t MR5		:1;
		volatile uint32_t MR6		:1;
		volatile uint32_t MR7		:1;
		volatile uint32_t MR8		:1;
		volatile uint32_t MR9		:1;
		volatile uint32_t MR10		:1;
		volatile uint32_t MR11		:1;
		volatile uint32_t MR12		:1;
		volatile uint32_t MR13		:1;
		volatile uint32_t MR14		:1;
		volatile uint32_t MR15		:1;
		volatile uint32_t MR16		:1;
		volatile uint32_t MR17		:1;
		volatile uint32_t MR18		:1;
		volatile uint32_t MR19		:1;
		volatile uint32_t Reserved	:12;
	};
}EXTI_IMR_t;

// Event mask register (EXTI_EMR)
typedef union{
	volatile uint32_t EMR;
	struct{
		volatile uint32_t MR0		:1;
		volatile uint32_t MR1		:1;
		volatile uint32_t MR2		:1;
		volatile uint32_t MR3		:1;
		volatile uint32_t MR4		:1;
		volatile uint32_t MR5		:1;
		volatile uint32_t MR6		:1;
		volatile uint32_t MR7		:1;
		volatile uint32_t MR8		:1;
		volatile uint32_t MR9		:1;
		volatile uint32_t MR10		:1;
		volatile uint32_t MR11		:1;
		volatile uint32_t MR12		:1;
		volatile uint32_t MR13		:1;
		volatile uint32_t MR14		:1;
		volatile uint32_t MR15		:1;
		volatile uint32_t MR16		:1;
		volatile uint32_t MR17		:1;
		volatile uint32_t MR18		:1;
		volatile uint32_t MR19		:1;
		volatile uint32_t Reserved	:12;
	};
}EXTI_EMR_t;

// Rising trigger selection register (EXTI_RTSR)
typedef union{
	volatile uint32_t RTSR;
	struct{
		volatile uint32_t TR0		:1;
		volatile uint32_t TR1		:1;
		volatile uint32_t TR2		:1;
		volatile uint32_t TR3		:1;
		volatile uint32_t TR4		:1;
		volatile uint32_t TR5		:1;
		volatile uint32_t TR6		:1;
		volatile uint32_t TR7		:1;
		volatile uint32_t TR8		:1;
		volatile uint32_t TR9		:1;
		volatile uint32_t TR10		:1;
		volatile uint32_t TR11		:1;
		volatile uint32_t TR12		:1;
		volatile uint32_t TR13		:1;
		volatile uint32_t TR14		:1;
		volatile uint32_t TR15		:1;
		volatile uint32_t TR16		:1;
		volatile uint32_t TR17		:1;
		volatile uint32_t TR18		:1;
		volatile uint32_t TR19		:1;
		volatile uint32_t Reserved	:12;
	};
}EXTI_RTSR_t;

// Falling trigger selection register (EXTI_FTSR)
typedef union{
	volatile uint32_t FTSR;
	struct{
		volatile uint32_t TR0		:1;
		volatile uint32_t TR1		:1;
		volatile uint32_t TR2		:1;
		volatile uint32_t TR3		:1;
		volatile uint32_t TR4		:1;
		volatile uint32_t TR5		:1;
		volatile uint32_t TR6		:1;
		volatile uint32_t TR7		:1;
		volatile uint32_t TR8		:1;
		volatile uint32_t TR9		:1;
		volatile uint32_t TR10		:1;
		volatile uint32_t TR11		:1;
		volatile uint32_t TR12		:1;
		volatile uint32_t TR13		:1;
		volatile uint32_t TR14		:1;
		volatile uint32_t TR15		:1;
		volatile uint32_t TR16		:1;
		volatile uint32_t TR17		:1;
		volatile uint32_t TR18		:1;
		volatile uint32_t TR19		:1;
		volatile uint32_t Reserved	:12;
	};
}EXTI_FTSR_t;

// Software interrupt event register (EXTI_SWIER)
typedef union{
	volatile uint32_t SWIER;
	struct{
		volatile uint32_t _SWIER0	:1;
		volatile uint32_t _SWIER1	:1;
		volatile uint32_t _SWIER2	:1;
		volatile uint32_t _SWIER3	:1;
		volatile uint32_t _SWIER4	:1;
		volatile uint32_t _SWIER5	:1;
		volatile uint32_t _SWIER6	:1;
		volatile uint32_t _SWIER7	:1;
		volatile uint32_t _SWIER8	:1;
		volatile uint32_t _SWIER9	:1;
		volatile uint32_t _SWIER10	:1;
		volatile uint32_t _SWIER11	:1;
		volatile uint32_t _SWIER12	:1;
		volatile uint32_t _SWIER13	:1;
		volatile uint32_t _SWIER14	:1;
		volatile uint32_t _SWIER15	:1;
		volatile uint32_t _SWIER16	:1;
		volatile uint32_t _SWIER17	:1;
		volatile uint32_t _SWIER18	:1;
		volatile uint32_t _SWIER19	:1;
		volatile uint32_t Reserved	:12;
	};
}EXTI_SWIER_t;

// Pending register (EXTI_PR)
typedef union{
	volatile uint32_t PR;
	struct{
		volatile uint32_t _PR0		:1;
		volatile uint32_t _PR1		:1;
		volatile uint32_t _PR2		:1;
		volatile uint32_t _PR3		:1;
		volatile uint32_t _PR4		:1;
		volatile uint32_t _PR5		:1;
		volatile uint32_t _PR6		:1;
		volatile uint32_t _PR7		:1;
		volatile uint32_t _PR8		:1;
		volatile uint32_t _PR9		:1;
		volatile uint32_t _PR10		:1;
		volatile uint32_t _PR11		:1;
		volatile uint32_t _PR12		:1;
		volatile uint32_t _PR13		:1;
		volatile uint32_t _PR14		:1;
		volatile uint32_t _PR15		:1;
		volatile uint32_t _PR16		:1;
		volatile uint32_t _PR17		:1;
		volatile uint32_t _PR18		:1;
		volatile uint32_t _PR19		:1;
		volatile uint32_t Reserved	:12;
	};
}EXTI_PR_t;

/************* EXTI Registers ************/
typedef struct{
	volatile EXTI_IMR_t 	IMR;
	volatile EXTI_EMR_t 	EMR;
	volatile EXTI_RTSR_t 	RTSR;
	volatile EXTI_FTSR_t 	FTSR;
	volatile EXTI_SWIER_t 	SWIER;
	volatile EXTI_PR_t 		PR;
}EXTI_t;

/**********************************************************
 *      AFIO PERIPHERAL REGISTERS BASE ADDRESSES          *
 * ********************************************************/
/*********** AFIO Registers' Bits ***********/
//TRM @ Section 9.5 on page 194
// Event control register (AFIO_EVCR)
typedef union{
	volatile uint32_t EVCR;
	struct{
		volatile uint32_t PIN		:4;
		volatile uint32_t PORT		:3;
		volatile uint32_t EVOE		:1;
		volatile uint32_t Reserved	:24;
	};
}AFIO_EVCR_t;

// AF re-map and debug I/O configuration register (AFIO_MAPR)
// Memory map and bit definitions for low-, medium- high- and XL-density devices
typedef union{
	volatile uint32_t MAPR;
	struct{
		volatile uint32_t SPI1_REMAP			:1;
		volatile uint32_t I2C1_REMAP			:1;
		volatile uint32_t USART1_REMAP			:1;
		volatile uint32_t USART2_REMAP			:1;
		volatile uint32_t USART3_REMAP			:2;
		volatile uint32_t TIM1_REMAP			:2;
		volatile uint32_t TIM2_REMAP			:2;
		volatile uint32_t TIM3_REMAP			:2;
		volatile uint32_t TIM4_REMAP			:1;
		volatile uint32_t CAN_REMAP				:2;
		volatile uint32_t PD01_REMAP			:1;
		volatile uint32_t TIM5CH4_IREMAP		:1;
		volatile uint32_t ADC1_ETRGINJ_IREMAP	:1;
		volatile uint32_t ADC1_ETRGREG_REMAP	:1;
		volatile uint32_t ADC2_ETRGINJ_REMAP	:1;
		volatile uint32_t ADC2_ETRGREG_REMAP	:1;
		volatile uint32_t Reserved				:3;
		volatile uint32_t SWJ_CFG				:3;
		volatile uint32_t Reserved1				:5;
	};
}AFIO_MAPR_t;

// External interrupt configuration register x (AFIO_EXTICRx)
typedef union{
	volatile uint32_t EXTICR;
	struct{
		volatile uint32_t EXTI_0	:4;
		volatile uint32_t EXTI_1	:4;
		volatile uint32_t EXTI_2	:4;
		volatile uint32_t EXTI_3	:4;
		volatile uint32_t Reserved	:16;
	};
}AFIO_EXTICRx_t;

// AF re-map and debug I/O configuration register2 (AFIO_MAPR2)
typedef union{
	volatile uint32_t MAPR2;
	struct{
		volatile uint32_t Reserved		:5;
		volatile uint32_t TIM9_REMAP	:1;
		volatile uint32_t TIM10_REMAP	:1;
		volatile uint32_t TIM11_REMAP	:1;
		volatile uint32_t TIM13_REMAP	:1;
		volatile uint32_t TIM14_REMAP	:1;
		volatile uint32_t FSMC_NADV		:1;
		volatile uint32_t Reserved1		:21;
	};
}AFIO_MAPR2_t;

/*********** AFIO Register ***********/
typedef struct{
	AFIO_EVCR_t 		EVCR;
	AFIO_MAPR_t 		MAPR;
	AFIO_EXTICRx_t 		AFIO_EXTICR[4];
	volatile uint32_t 	Reserved;
	AFIO_MAPR2_t 		MAPR2;
}AFIO_t;


/*********************************************
 *                                           *
 *          PERIPHERALS INSTANCES            *
 *                                           *
 *********************************************/

#define GPIOA                              ((GPIO_t *)GPIOA_BASE)
#define GPIOB                              ((GPIO_t *)GPIOB_BASE)
#define GPIOC                              ((GPIO_t *)GPIOC_BASE)
#define GPIOD                              ((GPIO_t *)GPIOD_BASE)
#define GPIOE                              ((GPIO_t *)GPIOE_BASE)
#define RCC                                ((volatile RCC_t  *)RCC_BASE)
#define AFIO                               ((volatile AFIO_t *)AFIO_BASE)
#define EXTI                               ((volatile EXTI_t *)EXTI_BASE)


/*********************************************
 *                                           *
 *         CLOCK ENABLING MACROS             *
 *                                           *
 *********************************************/

#define RCC_GPIOA_CLOCK_EN()             (RCC->APB2ENR.IOPAEN=HIGH)
#define RCC_GPIOB_CLOCK_EN()             (RCC->APB2ENR.IOPBEN=HIGH)
#define RCC_GPIOC_CLOCK_EN()             (RCC->APB2ENR.IOPCEN=HIGH)
#define RCC_GPIOD_CLOCK_EN()             (RCC->APB2ENR.IOPDEN=HIGH)
#define RCC_GPIOE_CLOCK_EN()             (RCC->APB2ENR.IOPEEN=HIGH)
#define RCC_AFIO_CLOCK_EN()              (RCC->APB2ENR.AFIOEN=HIGH)

/**********************************************
 *											  *
 *         COMMON MACROS DEFINITION           *
 *         									  *
 * ********************************************/
#define TRUE        1U
#define FALSE       0U
#define HIGH		1U
#define LOW 		0U
/*********** GLOBAL ENUM DEFINITION **********/
typedef enum{
	FAIL,
	SUCCESS
}Return_t;

#endif /* INCLUDES_STM32F103C6_REGISTERS_H_ */
