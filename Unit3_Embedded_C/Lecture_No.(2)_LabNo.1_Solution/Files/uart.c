#include <uart.h>
#define UART0DR  *((volatile unsigned int*const)((volatile unsigned int*)0x101f1000))

void uartSendString(unsigned char* ptr_TX_String)
{
  while(*ptr_TX_String|='\0')
    {
      UART0DR=(unsigned int)(*ptr_TX_String);
      ptr_TX_String++;
    }
}