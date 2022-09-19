/*
LearnInDepth, UnitNo.(3), Embedded C, LessonNo.(3)
LabNo.(2), Toggle LED Lab, STM32F103Cx
@Copyright: Ahmed Aref Omaira
*/

MEMORY
{
	flash(RX) : ORIGIN = 0x08000000, LENGTH = 128K
	sram(RWX) : ORIGIN = 0x20000000, LENGTH = 20K
}

SECTIONS
{
	
	.text : {
		*(.vectors*) 
		*(.text*)
		*(.rodata*)
		. = ALIGN(4);
		_E_TEXT = .;
	} > flash
	.data : {
		_S_DATA = .;
		*(.data*)
		. = ALIGN(4);
		_E_DATA = .;
	}> sram AT> flash
	.bss  : {
		_S_BSS = .;
		*(.bss*)
		. = ALIGN(4);
		_E_BSS = .;
	} > sram
	. = . + 0x2000;
	STACK_TOP = .;
}
