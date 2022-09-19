/*
LearnInDepth, UnitNo.(3), Embedded C, LessonNo.(3)
LabNo.(2), Toggle LED Lab, STM32F103Cx
@Copyright: Ahmed Aref Omaira
*/

/**********************************************************************************/
/*                                 TYPEDEFS                                       */
/**********************************************************************************/
typedef volatile unsigned int vuint32_t;

/**********************************************************************************/
/*                                REGISTERS DEFINITIONS                           */
/**********************************************************************************/
#define RCC_BASE 		(0x40021000)
#define GPIO_PORTA_BASE (0x40010800)
#define RCC_APB2ENR     (*(vuint32_t*)(RCC_BASE + 0x18))
#define GPIO_PORTA_CRH  (*(vuint32_t*)(GPIO_PORTA_BASE + 0x04))
#define GPIO_PORTA_ODR  (*(vuint32_t*)(GPIO_PORTA_BASE + 0x0C))

/**********************************************************************************/
/*                                BITFIELDS DEFINITIONS                           */
/**********************************************************************************/
#define RCC_IOPAEN (1<<2)
#define GPIOA13    (1<<13)

int main(void)
{
	/* 1.Enable clock to PORT A Input/Output in the RCC APB2 Enable Register */
	RCC_APB2ENR |= RCC_IOPAEN;

	/* 2.Set the mode bits from bit 20 to bit 23 to 2 in the GPIO_PORTA CRH Register */
	GPIO_PORTA_CRH &= 0xff0fffff;
	GPIO_PORTA_CRH |= 0x00200000;

	while(1)
	{
		/* 3.Output LOW to PortA Pin No.(13) through the Output Data Register */
		GPIO_PORTA_ODR &=~GPIOA13;
		/* 4.Busy wait using generic delay */
		for(int i = 0; i<5000 ; i++);
		/* 5.Output High to PortA Pin No.(13) through the Output Data Register */
		GPIO_PORTA_ODR |= GPIOA13;
		/* 6.Busy wait using generic delay */
		for(int i = 0; i<5000 ; i++);
	}
	return 0;
}