/*
 * STM32F103C6_USART.c
 *
 *  Created on: Aug 30, 2023
 *      Author: ahmed
 */
/******************************************
 *                                        *
 *                INCLUDES                *
 * 										  *
 * ****************************************/
#include <STM32F103C6_UART.h>


/********************************************
 *                                          *
 *         GLOBAL VARIABLES DEFINITION      *
 * 								   		    *
 * ******************************************/
UART_Configuration_t* Global_UART_Config[3] = {NULL};

/*********************************************
 *                                           *
 *         IRQ HANDLERS DEFINITION           *
 * 							    			 *
 * *******************************************/
void USART1_IRQHandler(void)
{
	Global_UART_Config[0]->P_IRQ_CallBack();
}

void USART2_IRQHandler(void)
{
	Global_UART_Config[1]->P_IRQ_CallBack();
}

void USART3_IRQHandler(void)
{
	Global_UART_Config[2]->P_IRQ_CallBack();
}



/***********************************************************
 *                                                         *
 * APIS SUPPORTED BY MCAL UART DRIVER FUNCTIONS DEFINITION *
 * 								  			   		       *
 * *********************************************************/
void MCAL_UART_Init  (USART_t* USARTx, UART_Configuration_t* UART_Config){
	// 1. Enable the clock for given USART peripheral
	if      (USARTx == USART1){ MCAL_RCC_PERIPHERAL_EN(RCC_USART1); Global_UART_Config[0] = UART_Config; }
	else if (USARTx == USART2){ MCAL_RCC_PERIPHERAL_EN(RCC_USART2); Global_UART_Config[1] = UART_Config; }
	else if (USARTx == USART3){ MCAL_RCC_PERIPHERAL_EN(RCC_USART3); Global_UART_Config[2] = UART_Config; }
	else                      { /*  Misra  */ }

	// 2. Enable USART Module
	USARTx->CR1.UE = HIGH;

	// 3. Enable USART TX/RX engines according to the USART_Mode configuration item
	switch(UART_Config->Mode){
		case UART_Mode_RX:USARTx->CR1.RE = HIGH;break;
		case UART_Mode_TX:USARTx->CR1.TE = HIGH;break;
		case UART_Mode_BothTxRx:
			USARTx->CR1.RE = HIGH;
			USARTx->CR1.TE = HIGH;
			break;
		}

	//  4. Pay-load width
	USARTx->CR1.M = UART_Config->PayloadLength;

	// 5. configuration of parity control bit field
	if (UART_Config->Parity)
	{
		switch(UART_Config->Parity){
			case UART_Parity_ODD : USARTx->CR1.PCE = HIGH; USARTx->CR1.PS = HIGH; break;
			case UART_Parity_EVEN: USARTx->CR1.PCE = HIGH; USARTx->CR1.PS = LOW;break;
			}
	}else
	{
		USARTx->CR1.PCE = LOW;
	}

	// 6. configuration the no. of stop bits
	USARTx->CR2.STOP = UART_Config->NumberOfStopBits;

	// 7. USART HW Flow Control
	switch(UART_Config->HWFlowControl){
		case UART_HW_FlowControl_CTS: USARTx->CR3.CTSE = HIGH;break;
		case UART_HW_FlowControl_RTS: USARTx->CR3.RTSE = HIGH;break;
		case UART_HW_FlowControl_BothRTSCTS:
			USARTx->CR3.CTSE = HIGH;
			USARTx->CR3.RTSE = HIGH;break;
		}

	// 8. configuration baud-rate
	uint32_t pclk = (USARTx == USART1)? MCAL_RCC_GetPCLK2Freq() : MCAL_RCC_GetPCLK1Freq();
	USARTx->BRR.DIV_Fraction = DIV_Fraction(pclk, UART_Config->BaudRate);
	USARTx->BRR.DIV_Mantissa = DIV_Mantissa(pclk, UART_Config->BaudRate);

	// 9. Enable or Disable Interrupt
	if (UART_Config->IRQEnable != UART_IRQ_Enable_NONE)
	{
		if      (USARTx == USART1){ NVIC_ISER->NVIC_ISER1 |= (1 << (USART1_IRQ - 32)); }
	    else if (USARTx == USART2){ NVIC_ISER->NVIC_ISER1 |= (1 << (USART2_IRQ - 32)); }
	    else if (USARTx == USART3){ NVIC_ISER->NVIC_ISER1 |= (1 << (USART3_IRQ - 32)); }
	    else                      { /*  Misra  */ }

		if      (UART_Config->IRQEnable == UART_IRQ_Enable_TXE)    { USARTx->CR1.TXEIE  = HIGH; }
		else if (UART_Config->IRQEnable == UART_IRQ_Enable_TC)     { USARTx->CR1.TCIE   = HIGH; }
		else if (UART_Config->IRQEnable == UART_IRQ_Enable_RXNEIE) { USARTx->CR1.RXNEIE = HIGH; }
		else if (UART_Config->IRQEnable == UART_IRQ_Enable_PE)     { USARTx->CR1.PEIE   = HIGH; }
		else                                                        { /*  Misra  */ }
	}
}


void MCAL_UART_DeInit(USART_t* USARTx){
	if (USARTx == USART1){
			MCAL_RCC_PERIPHERAL_DS(RCC_USART1);
			NVIC_ICER->NVIC_ICER1 |= (1 << (USART1_IRQ - 32));
	}else if (USARTx == USART2){
		MCAL_RCC_PERIPHERAL_DS(RCC_USART2);
			NVIC_ICER->NVIC_ICER1 |= (1 << (USART2_IRQ - 32));
	}else if (USARTx == USART3){
		MCAL_RCC_PERIPHERAL_DS(RCC_USART3);
			NVIC_ICER->NVIC_ICER1 |= (1 << (USART3_IRQ - 32));
	}else { /*  Misra  */ }
}


void MCAL_UART_GPIO_Set_Pins(USART_t* USARTx){
	GPIO_PinConfig_t PinConfig;
    if (USARTx == USART1)
	{
    	//Enable GPIOA and AFIO
    	MCAL_RCC_PERIPHERAL_EN(RCC_AFIO);
    	MCAL_RCC_PERIPHERAL_EN(RCC_GPIOA);

    	// PA9 TX and PA10 RX
    	if (Global_UART_Config[0]->Mode != UART_Mode_TX)
    	{
			// Initialize GPIOA Pin 10 as a AFIO UART RX
			PinConfig.GPIO_PinNumber = GPIO_PIN_10;
			PinConfig.GPIO_Mode = GPIO_MODE_Input_AF;
			PinConfig.GPIO_OutputSpeed = GPIO_SPEED_Input;
			MCAL_GPIO_Init(GPIOA, &PinConfig);
    	}
    	if (Global_UART_Config[0]->Mode != UART_Mode_RX)
    	{
			// Initialize GPIOA Pin 9 as a AFIO UART TX
			PinConfig.GPIO_PinNumber = GPIO_PIN_9;
			PinConfig.GPIO_Mode = GPIO_MODE_Output_AF_PP;
			PinConfig.GPIO_OutputSpeed = GPIO_SPEED_10MHz;
			MCAL_GPIO_Init(GPIOA, &PinConfig);
    	}
    	else { /*  Misra  */ }

    	// PA11 CTS and PA12 RTS
    	if (Global_UART_Config[0]->HWFlowControl){
		if (Global_UART_Config[0]->HWFlowControl != UART_HW_FlowControl_RTS)
		{
			// Initialize GPIOA Pin 10 as a AFIO UART CTS
			PinConfig.GPIO_PinNumber = GPIO_PIN_11;
			PinConfig.GPIO_Mode = GPIO_MODE_Input_AF;
			PinConfig.GPIO_OutputSpeed = GPIO_SPEED_Input;
			MCAL_GPIO_Init(GPIOA, &PinConfig);
		}
		if (Global_UART_Config[0]->HWFlowControl != UART_HW_FlowControl_CTS)
		{
			// Initialize GPIOA Pin 9 as a AFIO UART RTS
			PinConfig.GPIO_PinNumber = GPIO_PIN_12;
			PinConfig.GPIO_Mode = GPIO_MODE_Output_AF_PP;
			PinConfig.GPIO_OutputSpeed = GPIO_SPEED_10MHz;
			MCAL_GPIO_Init(GPIOA, &PinConfig);
		}
		else { /*  Misra  */ }
    	}
	}
    else if (USARTx == USART2)
	{
    	//Enable GPIOA and AFIO
    	MCAL_RCC_PERIPHERAL_EN(RCC_AFIO);
    	MCAL_RCC_PERIPHERAL_EN(RCC_GPIOA);

		// PA2 TX and PA3 RX
		if (Global_UART_Config[1]->Mode != UART_Mode_TX)
		{
			// Initialize GPIOA Pin 3 as a AFIO UART RX
			PinConfig.GPIO_PinNumber = GPIO_PIN_3;
			PinConfig.GPIO_Mode = GPIO_MODE_Input_AF;
			PinConfig.GPIO_OutputSpeed = GPIO_SPEED_Input;
			MCAL_GPIO_Init(GPIOA, &PinConfig);
		}
		if (Global_UART_Config[1]->Mode != UART_Mode_RX)
		{
			// Initialize GPIOA Pin 2 as a AFIO UART TX
			PinConfig.GPIO_PinNumber = GPIO_PIN_2;
			PinConfig.GPIO_Mode = GPIO_MODE_Output_AF_PP;
			PinConfig.GPIO_OutputSpeed = GPIO_SPEED_10MHz;
			MCAL_GPIO_Init(GPIOA, &PinConfig);
		}
		else { /*  Misra  */ }

		// PA0 CTS and PA1 RTS
		if (Global_UART_Config[1]->HWFlowControl){
		if (Global_UART_Config[1]->HWFlowControl != UART_HW_FlowControl_RTS)
		{
			// Initialize GPIOA Pin 0 as a AFIO UART CTS
			PinConfig.GPIO_PinNumber = GPIO_PIN_0;
			PinConfig.GPIO_Mode = GPIO_MODE_Input_AF;
			PinConfig.GPIO_OutputSpeed = GPIO_SPEED_Input;
			MCAL_GPIO_Init(GPIOA, &PinConfig);
		}
		if (Global_UART_Config[1]->HWFlowControl != UART_HW_FlowControl_CTS)
		{
			// Initialize GPIOA Pin 1 as a AFIO UART RTS
			PinConfig.GPIO_PinNumber = GPIO_PIN_1;
			PinConfig.GPIO_Mode = GPIO_MODE_Output_AF_PP;
			PinConfig.GPIO_OutputSpeed = GPIO_SPEED_10MHz;
			MCAL_GPIO_Init(GPIOA, &PinConfig);
		}
		else { /*  Misra  */ }
		}
	}
    else if (USARTx == USART3)
	{
    	//Enable GPIOB and AFIO
    	MCAL_RCC_PERIPHERAL_EN(RCC_AFIO);
    	MCAL_RCC_PERIPHERAL_EN(RCC_GPIOB);

		// PB10 TX and PB11 RX
		if (Global_UART_Config[2]->Mode != UART_Mode_TX)
		{
			// Initialize GPIOB Pin 11 as a AFIO UART RX
			PinConfig.GPIO_PinNumber = GPIO_PIN_11;
			PinConfig.GPIO_Mode = GPIO_MODE_Input_AF;
			PinConfig.GPIO_OutputSpeed = GPIO_SPEED_Input;
			MCAL_GPIO_Init(GPIOB, &PinConfig);
		}
		if (Global_UART_Config[2]->Mode != UART_Mode_RX)
		{
			// Initialize GPIOB Pin 10 as a AFIO UART TX
			PinConfig.GPIO_PinNumber = GPIO_PIN_10;
			PinConfig.GPIO_Mode = GPIO_MODE_Output_AF_PP;
			PinConfig.GPIO_OutputSpeed = GPIO_SPEED_10MHz;
			MCAL_GPIO_Init(GPIOB, &PinConfig);
		}
		else { /*  Misra  */ }

		// PA13 CTS and PA14 RTS
		if (Global_UART_Config[2]->HWFlowControl){
		if (Global_UART_Config[2]->HWFlowControl != UART_HW_FlowControl_RTS)
		{
			// Initialize GPIOB Pin 13 as a AFIO UART CTS
			PinConfig.GPIO_PinNumber = GPIO_PIN_13;
			PinConfig.GPIO_Mode = GPIO_MODE_Input_AF;
			PinConfig.GPIO_OutputSpeed = GPIO_SPEED_Input;
			MCAL_GPIO_Init(GPIOB, &PinConfig);
		}
		if (Global_UART_Config[2]->HWFlowControl != UART_HW_FlowControl_CTS)
		{
			// Initialize GPIOB Pin 14 as a AFIO UART RTS
			PinConfig.GPIO_PinNumber = GPIO_PIN_14;
			PinConfig.GPIO_Mode = GPIO_MODE_Output_AF_PP;
			PinConfig.GPIO_OutputSpeed = GPIO_SPEED_10MHz;
			MCAL_GPIO_Init(GPIOB, &PinConfig);
		}
		else { /*  Misra  */ }
		}
	}
    else { /*  Misra  */ }
}


void MCAL_UART_SendData   (USART_t* USARTx, uint16_t* P_TxBuffer, uint8_t Mechanism){
	// 1. Wait until TXE (Transmit data register empty)
	if (Mechanism == UART_PollingMechanism) { while(!(USARTx->SR.TXE)); }
	else                                { /*  Misra  */ }

	// 2. Check the USART_WordLength item for 9-bit or 8-bit in a frame
	UART_Configuration_t* USARTxConfig = NULL;
	USARTxConfig = (UART_Configuration_t*)((USARTx == USART1)?  Global_UART_Config       :
			                            ((USARTx == USART2)? (Global_UART_Config + 1)  :
			                		                             (Global_UART_Config + 2)));

	switch(USARTxConfig->PayloadLength){
	case UART_Payload_Length_8B: USARTx->DR.DR = ((*P_TxBuffer) & (uint8_t)0xFF); break;
	case UART_Payload_Length_9B: USARTx->DR.DR = ((*P_TxBuffer) & (uint8_t)0x1FF);break;
	}
}


void MCAL_UART_ReceiveData(USART_t* USARTx, uint16_t* P_RxBuffer, uint8_t Mechanism){
	// 1. Wait until RXNE (Read data register not empty)
	if (Mechanism == UART_PollingMechanism) { while(!(USARTx->SR.RXNE)); }
	else                                { /*  Misra  */ }

	// 2. Check the USART_WordLength item for 9-bit or 8-bit in a frame
	UART_Configuration_t* USARTxConfig = NULL;
	USARTxConfig = (UART_Configuration_t*)((USARTx == USART1)?  Global_UART_Config       :
			                        ((USARTx == USART2)? (Global_UART_Config + 1)  :
			                		                     (Global_UART_Config + 2)));

	switch(USARTxConfig->PayloadLength){
	case UART_Payload_Length_8B:
		if (USARTxConfig->Parity == UART_Parity_Disable)
			*P_RxBuffer = (USARTx->DR.DR & (uint8_t)0xFF);
		else
			*P_RxBuffer = (USARTx->DR.DR & (uint8_t)0x7F);
		break;
	case UART_Payload_Length_9B:
		if (USARTxConfig->Parity == UART_Parity_Disable)
			*P_RxBuffer =  USARTx->DR.DR;
		else
			*P_RxBuffer = (USARTx->DR.DR & (uint8_t)0xFF);
		break;
	}
}
void MCAL_UART_WAIT_TC(USART_t* USARTx){
	while(!USARTx->SR.TC);
}
