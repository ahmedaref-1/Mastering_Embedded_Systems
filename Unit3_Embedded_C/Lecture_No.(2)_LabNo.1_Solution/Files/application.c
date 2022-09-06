#include "uart.h"

unsigned char stringBuffer[100] = "Learn In Depth < Ahmed Aref >";
unsigned char stringBuffer2[100]; //"To Create .bss Section in RAM";
unsigned char const stringBuffer3[100] = "To Create rodata Section";

void main (void)
{
	uartSendString(stringBuffer);
} 