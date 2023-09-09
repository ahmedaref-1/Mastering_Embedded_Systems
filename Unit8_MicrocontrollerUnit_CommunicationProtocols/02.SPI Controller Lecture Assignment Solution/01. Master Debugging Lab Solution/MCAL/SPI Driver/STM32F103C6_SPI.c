/*
 * STM32F103C6_SPI.c
 *
 *  Created on: Aug 31, 2023
 *      Author: ahmed
 */
/******************************************
 *                                        *
 *                INCLUDES                *
 * 										  *
 * ****************************************/
#include <STM32F103C6_SPI.h>


/********************************************
 *                                          *
 *         GLOBAL VARIABLES DEFINITION      *
 * 								   		    *
 * ******************************************/
static SPI_Configuration_t* Global_SPI_Config[2]= {NULL};
const uint16_t SPI_GPIO_Pins[2][4] = {{GPIO_PIN_4 , GPIO_PIN_5 , GPIO_PIN_6 , GPIO_PIN_7 },
		                              {GPIO_PIN_12, GPIO_PIN_13, GPIO_PIN_14, GPIO_PIN_15}};


/*********************************************
 *                                           *
 *         IRQ HANDLERS DEFINITION           *
 * 							    			 *
 * *******************************************/
void SPI1_IRQHandler(void)
{
	Global_SPI_Config[SPI1_Index]->P_IRQ_CallBack();
}

void SPI2_IRQHandler(void)
{
	Global_SPI_Config[SPI2_Index]->P_IRQ_CallBack();
}


/***********************************************************
 *                                                         *
 *  APIS SUPPORTED BY MCAL SPI DRIVER FUNCTIONS DEFINITION *
 * 								  			   		       *
 * *********************************************************/
void MCAL_SPI_Init  (SPI_t *SPIx, SPI_Configuration_t *SPI_Config){
	   // 1. Enable the clock for given USART peripheral
		if      (SPIx == SPI1){ MCAL_RCC_PERIPHERAL_EN(RCC_SPI1) ; Global_SPI_Config[SPI1_Index] = SPI_Config; }
		else if (SPIx == SPI2){ MCAL_RCC_PERIPHERAL_EN(RCC_SPI2); Global_SPI_Config[SPI2_Index] = SPI_Config; }
		else                  { /*  Misra  */ }

		// 2. Enable SPI
		SPIx->CR1.SPE = HIGH;

		// 3. Set Master or Slave
		SPIx->CR1.MSTR = SPI_Config->Mode;

		// 4. Set Communication Mode
		switch (SPI_Config->CommunicationMode){
		case SPI_COMMUNICATION_MODE_2LINE_FULL_DUPLEX:
			SPIx->CR1.BIDIMODE = LOW;
			SPIx->CR1.RXONLY   = LOW;
			break;
		case SPI_COMMUNICATION_MODE_2LINE_RXE_ONLY:
			SPIx->CR1.BIDIMODE = LOW;
			SPIx->CR1.RXONLY   = HIGH;
			break;
		case SPI_COMMUNICATION_MODE_1LINE_RX_ONLY:
			SPIx->CR1.BIDIMODE = HIGH ;
			SPIx->CR1.BIDIOE   = LOW;
			break;
		case SPI_COMMUNICATION_MODE_1LINE_TX_ONLY:
			SPIx->CR1.BIDIMODE = HIGH;
			SPIx->CR1.BIDIOE   = HIGH;
			break;
		}

		// 5. Set Frame Format
		SPIx->CR1.LSBFIRST = SPI_Config->FrameFormat;

		// 6. Set Data size
		SPIx->CR1.DFF = SPI_Config->FrameSize;

		// 7. Set Clock Polarity
		SPIx->CR1.CPOL = SPI_Config->CLKPolarity;

		// 8. Set Clock Phase
		SPIx->CR1.CPHA = SPI_Config->CLKPhase;

		// 9. Set Slave Select Management
		if      (SPI_Config->SlaveSelectManagement == SPI_NSS_HW_SLAVE)                       {SPIx->CR2.SSOE = LOW;}
		else if (SPI_Config->SlaveSelectManagement == SPI_NSS_HW_MASTER_SS_OUTPUT_ENABLED)    {SPIx->CR2.SSOE = HIGH; }
		else if (SPI_Config->SlaveSelectManagement == SPI_NSS_HW_MASTER_SS_OUTPUT_DISABLED)   {SPIx->CR2.SSOE = LOW;}
		else if (SPI_Config->SlaveSelectManagement == SPI_NSS_SW_SSI_RESET){SPIx->CR1.SSM  = HIGH; SPIx->CR1.SSI = HIGH;}
		else if (SPI_Config->SlaveSelectManagement == SPI_NSS_SW_SSI_SET){SPIx->CR1.SSM  = HIGH; SPIx->CR1.SSI = HIGH;}
		else                                                                        { /*  Misra  */ }

		// 10. Set BoudRate Pre-scaler
		SPIx->CR1.BR = SPI_Config->BaudRatePrescaler;

		// 11. Set Interrupt
		if (SPI_Config->IRQEnable != SPI_IRQ_ENABLE_NONE)
		{
			if      (SPI_Config->IRQEnable == SPI_IRQ_ENABLE_TXEIE)  { SPIx->CR2.TXEIE  = HIGH; }
			else if (SPI_Config->IRQEnable == SPI_IRQ_ENABLE_ERRIE)  { SPIx->CR2.ERRIE  = HIGH; }
			else if (SPI_Config->IRQEnable == SPI_IRQ_ENABLE_RXNEIE) { SPIx->CR2.RXNEIE = HIGH; }
			else                                                      { /*  Misra  */ }

			// 12. Open the global Interrupt for each peripheral
			if      (SPIx == SPI1){ NVIC_ISER->NVIC_ISER1 |= (1 << (SPI1_IRQ - 32)); }
			else if (SPIx == SPI2){ NVIC_ISER->NVIC_ISER1 |= (1 << (SPI2_IRQ - 32)); }
			else                  { /*  Misra  */ }

		}
		else { /*  Misra  */ }
}
void MCAL_SPI_DeInit(SPI_t *SPIx){
		if      (SPIx == SPI1){ RCC->APB2RSTR.SPI1RST = TRUE; NVIC_ICER->NVIC_ICER1 |= (1 << (SPI1_IRQ - 32)); }
		else if (SPIx == SPI2){ RCC->APB1RSTR.SPI2RST = TRUE; NVIC_ICER->NVIC_ICER1 |= (1 << (SPI2_IRQ - 32)); }
		else                  { /*  Misra  */ }
}
void MCAL_SPI_GPIO_Set_Pins(SPI_t *SPIx){
	GPIO_PinConfig_t SPI_GPIO_Config;
	GPIO_t* GPIOx = NULL;
	uint16_t* GPIOPins = NULL;
	SPI_Configuration_t* SPIxConfig = NULL;

	SPIxConfig = (SPI_Configuration_t*)((SPIx == SPI1)? Global_SPI_Config[SPI1_Index] : Global_SPI_Config[SPI2_Index]);
	GPIOPins   =     (uint16_t*)((SPIx == SPI1)? (SPI_GPIO_Pins) : (SPI_GPIO_Pins + 1));
	GPIOx      =       (GPIO_t*)((SPIx == SPI1)? GPIOA : GPIOB);

	//Enable GPIOA and AFIO
	MCAL_RCC_PERIPHERAL_EN(RCC_GPIOA);
	MCAL_RCC_PERIPHERAL_EN(RCC_AFIO);

	if (SPIxConfig->Mode == SPI_MODE_MASTER)
	{
		// SPI_GPIO_Pins[x][0] >> SPIx_NSS
		if (SPIxConfig->SlaveSelectManagement == SPI_NSS_HW_MASTER_SS_OUTPUT_DISABLED)
		{
			SPI_GPIO_Config.GPIO_PinNumber = GPIOPins[SPIx_NSS_Index];
			SPI_GPIO_Config.GPIO_Mode = GPIO_MODE_Input_AF;
			SPI_GPIO_Config.GPIO_OutputSpeed = GPIO_SPEED_Input;
			MCAL_GPIO_Init(GPIOx, &SPI_GPIO_Config);
		}
		else if (SPIxConfig->SlaveSelectManagement == SPI_NSS_HW_MASTER_SS_OUTPUT_ENABLED)
		{
			SPI_GPIO_Config.GPIO_PinNumber = GPIOPins[SPIx_NSS_Index];
			SPI_GPIO_Config.GPIO_Mode = GPIO_MODE_Output_AF_PP;
			SPI_GPIO_Config.GPIO_OutputSpeed = GPIO_SPEED_10MHz;
			MCAL_GPIO_Init(GPIOx, &SPI_GPIO_Config);
		}
		else { /* Misra */ }

		// SPI_GPIO_Pins[x][1] >> SPIx_SCK
		SPI_GPIO_Config.GPIO_PinNumber = GPIOPins[SPIx_SCK_Index];
		SPI_GPIO_Config.GPIO_Mode = GPIO_MODE_Output_AF_PP;
		SPI_GPIO_Config.GPIO_OutputSpeed = GPIO_SPEED_10MHz;
		MCAL_GPIO_Init(GPIOx, &SPI_GPIO_Config);

		// SPI_GPIO_Pins[x][2] >> SPIx_MISO
		SPI_GPIO_Config.GPIO_PinNumber = GPIOPins[SPIx_MISO_Index];
		SPI_GPIO_Config.GPIO_Mode = GPIO_MODE_Input_FLO;
		SPI_GPIO_Config.GPIO_OutputSpeed = GPIO_SPEED_Input;
		MCAL_GPIO_Init(GPIOx, &SPI_GPIO_Config);

		// SPI_GPIO_Pins[x][3] >> SPIx_MOSI
		SPI_GPIO_Config.GPIO_PinNumber = GPIOPins[SPIx_MOSI_Index];
		SPI_GPIO_Config.GPIO_Mode = GPIO_MODE_Output_AF_PP;
		SPI_GPIO_Config.GPIO_OutputSpeed = GPIO_SPEED_10MHz;
		MCAL_GPIO_Init(GPIOx, &SPI_GPIO_Config);
	}
	else if (SPIxConfig->Mode == SPI_MODE_SLAVE)
	{
		if (SPIxConfig->SlaveSelectManagement == SPI_NSS_HW_SLAVE)
		{
			// SPI_GPIO_Pins[x][0] >> SPIx_NSS
			SPI_GPIO_Config.GPIO_PinNumber = GPIOPins[SPIx_NSS_Index];
			SPI_GPIO_Config.GPIO_Mode = GPIO_MODE_Input_AF;
			SPI_GPIO_Config.GPIO_OutputSpeed = GPIO_SPEED_Input;
			MCAL_GPIO_Init(GPIOx, &SPI_GPIO_Config);
		}
		// SPI_GPIO_Pins[x][1] >> SPIx_SCK
		SPI_GPIO_Config.GPIO_PinNumber = GPIOPins[SPIx_SCK_Index];
		SPI_GPIO_Config.GPIO_Mode = GPIO_MODE_Input_AF;
		SPI_GPIO_Config.GPIO_OutputSpeed = GPIO_SPEED_Input;
		MCAL_GPIO_Init(GPIOx, &SPI_GPIO_Config);

		// SPI_GPIO_Pins[x][2] >> SPIx_MISO
		SPI_GPIO_Config.GPIO_PinNumber = GPIOPins[SPIx_MISO_Index];
		SPI_GPIO_Config.GPIO_Mode = GPIO_MODE_Output_AF_PP;
		SPI_GPIO_Config.GPIO_OutputSpeed = GPIO_SPEED_10MHz;
		MCAL_GPIO_Init(GPIOx, &SPI_GPIO_Config);

		// SPI_GPIO_Pins[x][3] >> SPIx_MOSI
		SPI_GPIO_Config.GPIO_PinNumber = GPIOPins[SPIx_MOSI_Index];
		SPI_GPIO_Config.GPIO_Mode = GPIO_MODE_Input_AF;
		SPI_GPIO_Config.GPIO_OutputSpeed = GPIO_SPEED_Input;
		MCAL_GPIO_Init(GPIOx, &SPI_GPIO_Config);
	}
	else { /* Misra */ }
}
void MCAL_SPI_Send_Data    (SPI_t *SPIx, uint16_t *P_TxBuffer, uint8_t Mechanism){
		// 1. Wait until TXE (Transmit data register empty)
		if (Mechanism == SPI_PollingMechanism) { while(!(SPIx->SR.TXE)); }
		else                                { /*  Misra  */ }

		// 2. Start transmission, Write data to SPI data register
		SPIx->DR.DR = *(P_TxBuffer);
}
void MCAL_SPI_Recieve_Data (SPI_t *SPIx, uint16_t *P_RxBuffer, uint8_t Mechanism){
		// 1. Wait until RXNE (Read data register not empty)
		if (Mechanism == SPI_PollingMechanism) { while(!(SPIx->SR.RXNE)); }
		else                                { /*  Misra  */ }

		// 2. Start reception, Write data to SPI data register
		*(P_RxBuffer) = (uint16_t)SPIx->DR.DR;
}
void MCAL_SPI_TX_RX        (SPI_t *SPIx, uint16_t *P_TxBuffer, uint8_t Mechanism){
		// 1. Wait until TXE (Transmit data register empty)
		if (Mechanism == SPI_PollingMechanism) { while(!(SPIx->SR.TXE)); }
		else                                { /*  Misra  */ }

		// 2. Start transmission, Write data to SPI data register
		SPIx->DR.DR = *(P_TxBuffer);

		// 3. Wait until RXNE (Read data register not empty)
		if (Mechanism == SPI_PollingMechanism) { while(!(SPIx->SR.RXNE)); }
		else                                { /*  Misra  */ }

		// 4. Start reception, Write data to SPI data register
		*(P_TxBuffer) = (uint16_t)SPIx->DR.DR;
}
