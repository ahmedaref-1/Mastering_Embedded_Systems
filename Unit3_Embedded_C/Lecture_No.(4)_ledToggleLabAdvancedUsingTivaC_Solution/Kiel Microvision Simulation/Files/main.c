/*
LearnInDepth, UnitNo.(3), Embedded C, LessonNo.(4)
LabNo.(3), Toggle LED Lab, TM4C123GH6PM
@Copyright: Ahmed Aref Omaira
*/

/**********************************************************************************/
/*                                 TYPEDEFS                                       */
/**********************************************************************************/
typedef unsigned long vuint32_t;

/**********************************************************************************/
/*                                REGISTERS DEFINITIONS                           */
/**********************************************************************************/

#define SYSCTL_RCGC2_R    	 (*(vuint32_t*)(0x400FE108))
#define GPIO_PORTF_DIR_R  	 (*(vuint32_t*)(0x40025400))
#define GPIO_PORTF_DEN_R  	 (*(vuint32_t*)(0x4002551C))
#define GPIO_PORTF_DATA_R    (*(vuint32_t*)(0x400253FC))

/**********************************************************************************/
/*                                BITFIELDS DEFINITIONS                           */
/**********************************************************************************/
#define SYSCTL_RCGC2_PORTF_CLOCK_ENABLE 	(1<<5)
#define GPIO_DIR_PORTF_PIN3_OUTPUT    		(1<<3)
#define GPIO_DEN_PORTF_PIN3_DIGITAL    		(1<<3)
#define GPIO_DATA_PORTF_PIN3_VALUE   		(1<<3)

int main(void)
{
	vuint32_t delay_count;

	/* 1.Enable clock to PORTF Input/Output in the SYSCTL RCGC2 Register */
	SYSCTL_RCGC2_R |= SYSCTL_RCGC2_PORTF_CLOCK_ENABLE;

	/* 2.Delay until the clock to portF is activated */
	for(delay_count=0; delay_count<200;delay_count++);

	/* 3.Set the Direction bit for PORTF Pin3 as Output */
	GPIO_PORTF_DIR_R |= GPIO_DIR_PORTF_PIN3_OUTPUT;
	
	/* 4.Set the Mode bit for PORTF Pin3 as Digital */
	GPIO_PORTF_DEN_R |= GPIO_DEN_PORTF_PIN3_DIGITAL;

	while(1)
	{
		/* 5.Output High to PortF Pin No.(3) through the Output Data Register */
		GPIO_PORTF_DATA_R |= GPIO_DATA_PORTF_PIN3_VALUE;
		/* 6.Busy wait using generic delay */
		for(delay_count=0; delay_count<200000;delay_count++);
		/* 7.Output LOW to PortF Pin No.(3) through the Output Data Register */
		GPIO_PORTF_DATA_R &= ~(GPIO_DATA_PORTF_PIN3_VALUE);
		/* 8.Busy wait using generic delay */
		for(delay_count=0; delay_count<200000;delay_count++);
	}
	return 0;
}