/*
 * GeneralPurposeInputOutput_Lecture1Assignment.c
 *
 * Created: 7/20/2023 3:33:38 AM
 * Author : Ahmed Aref Omaira
 */ 
#define F_CPU 8000000UL
#include "memorymap.h"

void GPIO_INIT(void){
	// Configuring PORTD PIN 0 as floating input
	DDRD &=~(0b1<<0);
	PORTD &=~(0b1<<0);
	
	// Configuring PORTD PINS 4,5,6&7 as push-pull output
	DDRD |=(0b1111<<4);
}

void delay(void){
	for(uint8_t i = 0 ; i < 255 ; i++)
		for(uint8_t j = 0 ; j < 255 ; j++);
}

int main(void)
{
    GPIO_INIT();
	uint8_t buttonOneCounter=0;
    while (1) 
    {
		if((PIND&(1<<0))==1){
			buttonOneCounter++;
			switch (buttonOneCounter){
				case 1:
					PORTD|=(1<<5);
					delay();
					break;
				case 2:
					PORTD&=~(1<<5);
					delay();
					PORTD|=(1<<5);
					PORTD|=(1<<6);
					delay();
					break;
				case 3:
					PORTD&=~(1<<5);
					PORTD&=~(1<<6);
					delay();
					PORTD|=(1<<5);
					PORTD|=(1<<6);
					PORTD|=(1<<7);
					delay();
					break;
				case 4:
					PORTD |=(1<<4);
					delay();
					break;
				default:
				PORTD=0x0;
				buttonOneCounter=0;
			}
			while((PIND&(1<<0))==1);
		}
		delay();
    }
}

