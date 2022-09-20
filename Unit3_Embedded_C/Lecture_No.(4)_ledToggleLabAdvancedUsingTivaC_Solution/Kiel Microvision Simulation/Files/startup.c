/*
LearnInDepth, UnitNo.(3), Embedded C, LessonNo.(4)
LabNo.(3), Toggle LED Lab, TM4C123GH6PM
@Copyright: Ahmed Aref Omaira
*/

#include <stdint.h>

void Reset_Handler(void);
extern int main(void);

void Default_Handler(void)
{
	Reset_Handler();
}

void NMI_Handler(void)__attribute__((weak,alias("Default_Handler")));;
void H_Fault_Handler(void)__attribute__((weak,alias("Default_Handler")));;
void Bus_Handler(void)__attribute__((weak,alias("Default_Handler")));;
void Usage_Fault_Handler(void) __attribute__((weak,alias("Default_Handler")));;

/*****************************************/
/*    RESERVE STACK SIZE OF 1024 BYTE    */
/*****************************************/
static uint32_t STACK_TOP[256];
/****************************************/

void (* const g_Ptr_Func_Vectors[])(void) __attribute__((section(".vectors"))) = {
(void(*)(void)) ((uint32_t)&STACK_TOP[0] + sizeof(STACK_TOP)),
 &Reset_Handler, 
 &NMI_Handler,
 &H_Fault_Handler, 
 &Bus_Handler,
 &Usage_Fault_Handler
};


extern uint8_t _E_TEXT;
extern uint8_t _S_DATA;
extern uint8_t _E_DATA;
extern uint8_t _S_BSS;
extern uint8_t _E_BSS;

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



