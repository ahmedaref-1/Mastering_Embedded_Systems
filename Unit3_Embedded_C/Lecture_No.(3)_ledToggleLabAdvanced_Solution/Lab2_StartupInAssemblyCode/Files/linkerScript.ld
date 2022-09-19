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
		*(.vectors) 
		*(.text)
	} > flash
	.bss : {
		*(.bss)
	} > sram
}
