typedef volatile unsigned int vuint32_t ;
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

// register address

//GPIO REGISTERS
#define GPIOA_BASE 0x40010800
#define GPIOA_CRH *(volatile uint32_t *)(GPIOA_BASE + 0x04)
#define GPIOA_CRL *(volatile uint32_t *)(GPIOA_BASE + 0x00)
#define GPIOA_ODR *(volatile uint32_t *)(GPIOA_BASE + 0x0C)

//CLOCKS REGISTERS
#define RCC_BASE 0x40021000
#define RCC_APB2ENR *(volatile uint32_t *)(RCC_BASE + 0x18)
#define RCC_CFGR *(volatile uint32_t *)(RCC_BASE + 0x04)
#define RCC_CR *(volatile uint32_t *)(RCC_BASE + 0x00)

//EXTERNAL INTERRUPTS REGISTERS
#define EXTI_BASE 0x40010400
#define EXTI_IMR *(volatile uint32_t *)(EXTI_BASE + 0x00)
#define EXTI_RTSR *(volatile uint32_t *)(EXTI_BASE + 0x08)
#define EXTI_PR *(volatile uint32_t *)(EXTI_BASE + 0x14)

//ALTERNATIVE FUNCTIONS REGISTERS
#define AFIO_BASE 0x40010000
#define AFIO_EXTICR1 *(volatile uint32_t *)(AFIO_BASE + 0x10)

//NVIC REGISTERS
#define NVIC_ISER0 *(volatile uint32_t *)0xE000E100

void CLOCK_INIT(void){
	//Init clock for GPIO Port A
	RCC_APB2ENR |= (0b1<<2);
	RCC_APB2ENR |= (0b1<<0);
}
void GPIO_INIT(void){
	//Init GPIOA PORT13 AS OUTPUT
	GPIOA_CRH &= 0xFF0FFFFF;
	GPIOA_CRH |= 0x00200000;
	//Init GPIOA PORT0 AS INPUT
	GPIOA_CRL |= (0b1<<2);
	//EXTI0 as PORTA PIN0
	AFIO_EXTICR1 = 0;
}
void EXTERNALINTERRUPT_INIT(void){
	//Enable EXTI0 INTERRUPT MASK
	EXTI_IMR |=(0b1<<0);
	//Enable EXTI0 INTERRUPT RISING EDGE
	EXTI_RTSR |= (0b1<<0);
	//Enable NVIC IRQ6 for EXTI0
	NVIC_ISER0 |= (1<<6);
}

int main(void)
{
	CLOCK_INIT();
	GPIO_INIT();
	EXTERNALINTERRUPT_INIT();
	while(1)
	{
	}
}
void EXTI0_IRQHandler(void){
	//Clear the EXTI0 pending request
	EXTI_PR|= (1<<0);
	//Toggle LED
	GPIOA_ODR ^= (1<<13);
}
