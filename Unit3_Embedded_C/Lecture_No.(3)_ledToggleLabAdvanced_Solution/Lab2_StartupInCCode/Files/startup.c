/*
LearnInDepth, UnitNo.(3), Embedded C, LessonNo.(3)
LabNo.(2), Toggle LED Lab, STM32F103Cx
@Copyright: Ahmed Aref Omaira
*/

#include <stdint.h>

extern int main(void);
extern void Reset_Handler(void);

extern uint8_t _E_TEXT;
extern uint8_t _S_DATA;
extern uint8_t _E_DATA;
extern uint8_t _S_BSS;
extern uint8_t _E_BSS;
extern uint8_t STACK_TOP;

void Default_Handler(void)
{
	Reset_Handler();
}

void Reset_Handler(void) {
	/* Copy data from FLASH to SRAM */
	uint32_t DATA_SIZE = (uint8_t*)&_E_DATA - (uint8_t*)&_S_DATA ;
	uint8_t* P_SRC = (uint8_t*)&_E_TEXT;
	uint8_t* P_DEST = (uint8_t*)&_S_DATA;
	for(int i = 0 ; i < DATA_SIZE ; i++)
	{
		*((uint8_t*)P_DEST++) = *((uint8_t*)P_SRC++);
	}

	/* Initialize the .bss with zeros */
	uint32_t BSS_SIZE = (uint8_t*)&_E_BSS - (uint8_t*)&_S_BSS ;
    P_DEST = (uint8_t*)&_S_BSS ;
	for(int i = 0 ; i < BSS_SIZE ; i++)
	{
		*((uint8_t*)P_DEST++) = (uint8_t)0 ;
	}

	/* Jump to main */
	main();
}

void NMI_Handler(void)__attribute__((weak,alias("Default_Handler")));;
void H_Fault_Handler(void)__attribute__((weak,alias("Default_Handler")));;
void Bus_Handler(void)__attribute__((weak,alias("Default_Handler")));;
void Usage_Fault_Handler(void) __attribute__((weak,alias("Default_Handler")));;

uint32_t vectors[] __attribute__((section(".vectors"))) = {
(uint32_t) &STACK_TOP,
(uint32_t) &Reset_Handler, 
(uint32_t) &NMI_Handler,
(uint32_t) &H_Fault_Handler, 
(uint32_t) &Bus_Handler,
(uint32_t) &Usage_Fault_Handler
};


