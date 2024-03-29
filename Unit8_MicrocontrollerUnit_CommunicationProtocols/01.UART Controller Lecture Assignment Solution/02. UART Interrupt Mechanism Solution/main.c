/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#include"STM32F103C6_UART.h"

uint16_t data;

void UART_ReceiveInterruptCallBackFunction(void){
	MCAL_UART_ReceiveData(USART1, &data, UART_InterruptMechanism);
	MCAL_UART_SendData(USART1, &data, UART_PollingMechanism);
}

USART_t* ptrUart = USART1;
GPIO_t* ptrGPIOA = GPIOA;
RCC_t* ptrRCC = RCC;

int main(void)
{
	// Configuration of USART1
	UART_Configuration_t UART1_Configuration;
	UART1_Configuration.BaudRate          = UART_BaudRate_115200;
	UART1_Configuration.HWFlowControl     = UART_HW_FlowControl_NONE;
	UART1_Configuration.IRQEnable         = UART_IRQ_Enable_RXNEIE;
	UART1_Configuration.P_IRQ_CallBack    = UART_ReceiveInterruptCallBackFunction;
	UART1_Configuration.Parity            = UART_Parity_Disable;
	UART1_Configuration.PayloadLength     = UART_Payload_Length_8B;
	UART1_Configuration.NumberOfStopBits  = UART_StopBits_1;
	UART1_Configuration.Mode     		  = UART_Mode_BothTxRx;

	MCAL_UART_Init(USART1, &UART1_Configuration);
	MCAL_UART_GPIO_Set_Pins(USART1);

	while(1)
	{

	}
}
