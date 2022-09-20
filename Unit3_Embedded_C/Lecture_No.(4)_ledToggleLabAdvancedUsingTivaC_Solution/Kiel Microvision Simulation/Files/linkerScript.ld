/*
LearnInDepth, UnitNo.(3), Embedded C, LessonNo.(4)
LabNo.(3), Toggle LED Lab, TM4C123GH6PM
@Copyright: Ahmed Aref Omaira
*/

MEMORY
{
	flash(RX) : ORIGIN = 0x00000000, LENGTH = 512M
	sram(RWX) : ORIGIN = 0x20000000, LENGTH = 512M
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
}
