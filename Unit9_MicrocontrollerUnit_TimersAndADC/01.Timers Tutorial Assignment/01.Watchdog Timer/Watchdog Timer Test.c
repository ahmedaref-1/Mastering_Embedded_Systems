/*
 * ATmega32.c
 *
 * Created: 7/29/2023 9:32:11 PM
 * Author : Ahmed Aref Omaira
 */ 

#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>

#define SET_BIT(PORT, BIT)			PORT |= (1<< BIT)
#define RESET_BIT(PORT, BIT)		PORT &= ~(1<<BIT)
#define TOGGLE_BIT(PORT, BIT)			PORT ^= (1<<BIT)
#define READ_BIT(PORT, BIT)			PORT & (1<<BIT)

#define LED_DDR DDRC
#define LED_PORT PORTC
#define LED_PIN 0

void WDT_ON()
{
		WDTCR = (1 << WDP1)|(1 << WDP1)|(1 << WDE);
		RESET_BIT(WDTCR, WDP0);
}

void WDT_OFF()
{
	WDTCR = (1<<WDTOE)|(1<<WDE);
	WDTCR = 0x00;
}

int main(void)
{
	//1. Make Pin0 on PortC as Output
	SET_BIT(LED_DDR,LED_PIN);
	
	_delay_ms(1000);
	while (1)
	{
		TOGGLE_BIT(LED_PORT, LED_PIN);
		WDT_ON();
		_delay_ms(2000);
		WDT_OFF();
	}
}