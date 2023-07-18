/*
 * InterruptFundamentals_ATmega32.c
 *
 * Created: 7/17/2023 9:03:26 PM
 * Author : ahmed aref omaira
 */ 
#define F_CPU 1000000UL
#include <stdint.h>
#include <avr/interrupt.h>
#include <util/delay.h>
/************************** 
*	register addresses    *
***************************/

//GPIO REGISTERS
#define GPIO_DDRD *(volatile uint32_t *)(0x31)
#define GPIO_DDRB *(volatile uint32_t *)(0x37)
#define GPIO_PORTD *(volatile uint32_t *)(0x32)

//EXTERNAL INTERRUPTS REGISTERS
#define EXTI_MCUCR *(volatile uint32_t *)(0x55)
#define EXTI_MCUCSR *(volatile uint32_t *)(0x54)
#define EXTI_GICR *(volatile uint32_t *)(0x5B)
#define EXTI_GIFR *(volatile uint32_t *)(0x5A)

//ALTERNATIVE FUNCTIONS REGISTERS

void GPIO_INIT(void){
	//PORTD PINS 2 & 3 and PORTB PIN 2 as DIGITAL INPUT
	GPIO_DDRD &=~(1<<2);
	GPIO_DDRD &=~(1<<3);
	GPIO_DDRB &=~(1<<2);
	//PORTD PINS 5, 6 & 7 as DIGITAL OUTPUT
	GPIO_DDRD |=(1<<5);
	GPIO_DDRD |=(1<<6);
	GPIO_DDRD |=(1<<7);
}
void EXTERNALINTERRUPT_INIT(void){
	// Global interrupt enable
	sei();
	//Enable INT0:2 in the General Interrupt Control Register
	EXTI_GICR |= (0b111<<5);
	//Configure INT0 to request IRQ when any Logical change occur (bit0)
	//Configure INT1 to request IRQ when on Rising edge (bit3:2)
	EXTI_MCUCR |= (0b1101<<0);
	//Configure INT2 to request IRQ when on Falling edge (bit6)
	EXTI_MCUCSR &=~(1<<6);
}

int main(void)
{
	GPIO_INIT();
	EXTERNALINTERRUPT_INIT();
	while(1)
	{
		//Clear PortD-Bit5:7
		GPIO_PORTD &= ~(0b111<<5);
		_delay_ms(1000);
	}
}

ISR(INT0_vect){
	GPIO_PORTD |= (1<<5);
	_delay_ms(1000);
	//w1c INT0 pending request
	EXTI_GIFR|=(1<<6);
}

ISR(INT1_vect){
	GPIO_PORTD |= (1<<6);
	_delay_ms(1000);
	//w1c INT1 pending request
	EXTI_GIFR |=(1<<7);
}

ISR(INT2_vect){
	GPIO_PORTD |= (1<<7);
	_delay_ms(1000);
	//w1c INT2 pending request
	EXTI_GIFR |=(1<<5);
}
