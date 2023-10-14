#include "config.h"


/* GPIO���ʾ�� */
tagGPIO_T demoGPIO[] =
{
	
	[0]=
	{ 
		.tGPIOInit.Pin 		= GPIO_PIN_13,				/* GPIO���� */
		.tGPIOInit.Mode 	= GPIO_MODE_OUTPUT_PP,		/* GPIOģʽ */
		.tGPIOInit.Pull 	= GPIO_NOPULL,				/* GPIO���������ã��Ƿ���Ҫ��������Ӳ�� */
		.tGPIOInit.Speed 	= GPIO_SPEED_FREQ_HIGH,		/* GPIO�ٶ� */	
		.tGPIOPort 			= GPIOD,					/* GPIO���� */
	},
    [1]=
	{ 
		.tGPIOInit.Pin 		= GPIO_PIN_14,				/* GPIO���� */
		.tGPIOInit.Mode 	= GPIO_MODE_OUTPUT_PP,		/* GPIOģʽ */
		.tGPIOInit.Pull 	= GPIO_NOPULL,				/* GPIO���������ã��Ƿ���Ҫ��������Ӳ�� */
		.tGPIOInit.Speed 	= GPIO_SPEED_FREQ_HIGH,		/* GPIO�ٶ� */	
		.tGPIOPort 			= GPIOD,					/* GPIO���� */
	},
    [2]=
	{ 
		.tGPIOInit.Pin 		= GPIO_PIN_15,				/* GPIO���� */
		.tGPIOInit.Mode 	= GPIO_MODE_OUTPUT_PP,		/* GPIOģʽ */
		.tGPIOInit.Pull 	= GPIO_NOPULL,				/* GPIO���������ã��Ƿ���Ҫ��������Ӳ�� */
		.tGPIOInit.Speed 	= GPIO_SPEED_FREQ_HIGH,		/* GPIO�ٶ� */	
		.tGPIOPort 			= GPIOD,					/* GPIO���� */
	},
    
};

/* ���ھ��ʾ�� */
tagUART_T demoUart = 
{
	//���ڹ���ģʽ����
	.tUARTHandle.Instance 				= USART1,					/* STM32 �����豸 */
	.tUARTHandle.Init.BaudRate   		= 115200,					/* ���ڲ����� */
	.tUARTHandle.Init.WordLength 		= UART_WORDLENGTH_8B,
	.tUARTHandle.Init.StopBits   		= UART_STOPBITS_1,
	.tUARTHandle.Init.Parity     		= UART_PARITY_NONE,
	.tUARTHandle.Init.HwFlowCtl  		= UART_HWCONTROL_NONE,
	.tUARTHandle.Init.Mode       		= UART_MODE_TX_RX,
	.tUARTHandle.Init.OverSampling 		= UART_OVERSAMPLING_16,

#if defined (STM32L4_SGA_ENABLE)
	.tUARTHandle.Init.OneBitSampling 	= UART_ONE_BIT_SAMPLE_DISABLE,
	.tUARTHandle.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT,
#endif
	
	.ucPriority							= 1,						/* �ж����ȼ� */
	.ucSubPriority						= 3,						/* �ж������ȼ� */
	
	//����DMA���ղ�������
	.tUartDMA.bRxEnable					= true,						/* DMA����ʹ�� */
	.tUartDMA.tDMARx.Instance			= DMA1_Channel5,
	.tUartDMA.tDMARx.Init.Direction		= DMA_PERIPH_TO_MEMORY,
	.tUartDMA.tDMARx.Init.PeriphInc		= DMA_PINC_DISABLE,
	.tUartDMA.tDMARx.Init.MemInc		= DMA_MINC_ENABLE,
	.tUartDMA.tDMARx.Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE,
	.tUartDMA.tDMARx.Init.MemDataAlignment	  = DMA_MDATAALIGN_BYTE,
	.tUartDMA.tDMARx.Init.Mode			= DMA_CIRCULAR,
	.tUartDMA.tDMARx.Init.Priority		= DMA_PRIORITY_LOW,

	.tRxInfo.usDMARxMAXSize             	= 100,              	/* �������ݳ��� ���ȱ�����Э����ֽ�*2���ϣ�ȷ�������һ���ܹ��ȶ�����һ������������֡*/

	.tUartDMA.ucDMARxPriority				= 1,					/* DMA�����ж����ȼ� */
	.tUartDMA.ucDMARxSubPriority			= 1,					/* DMA�����ж������ȼ� */
	
	//����DMA���Ͳ�������
	.tUartDMA.bTxEnable					= true,						/* DMA����ʹ�� */
	.tUartDMA.tDMATx.Instance			= DMA1_Channel4,
	.tUartDMA.tDMATx.Init.Direction		= DMA_MEMORY_TO_PERIPH,
	.tUartDMA.tDMATx.Init.PeriphInc		= DMA_PINC_DISABLE,
	.tUartDMA.tDMATx.Init.MemInc		= DMA_MINC_ENABLE,
	.tUartDMA.tDMATx.Init.PeriphDataAlignment	= DMA_PDATAALIGN_BYTE,
	.tUartDMA.tDMATx.Init.MemDataAlignment		= DMA_MDATAALIGN_BYTE,
	.tUartDMA.tDMATx.Init.Mode			= DMA_NORMAL,
	.tUartDMA.tDMATx.Init.Priority		= DMA_PRIORITY_LOW,

	.tTxInfo.usDMATxMAXSize				= 50,						/* ��������ݳ��� */
	
	.tUartDMA.ucDMATxPriority				= 1,					/* DMA�����ж����ȼ� */
	.tUartDMA.ucDMATxSubPriority			= 1,					/* DMA�����ж������ȼ� */

	//����GPIO����
	.tGPIO[0].tGPIOInit.Pin 			= GPIO_PIN_9,				/* GPIO���� */
	.tGPIO[0].tGPIOInit.Mode 			= GPIO_MODE_AF_PP,			/* GPIOģʽ */
	.tGPIO[0].tGPIOInit.Pull 			= GPIO_NOPULL,				/* GPIO���������ã��Ƿ���Ҫ��������Ӳ�� */
	.tGPIO[0].tGPIOInit.Speed 			= GPIO_SPEED_FREQ_HIGH,		/* GPIO�ٶ� */	
	.tGPIO[0].tGPIOPort 				= GPIOA,					/* GPIO���� */
	.tGPIO[0].ucAFMode					= NO_REMAP,					/* GPIO��ӳ�� */
	
	.tGPIO[1].tGPIOInit.Pin 			= GPIO_PIN_10,				/* GPIO���� */
	.tGPIO[1].tGPIOInit.Mode 			= GPIO_MODE_INPUT,			/* GPIOģʽ */
	.tGPIO[1].tGPIOInit.Pull 			= GPIO_NOPULL,				/* GPIO���������ã��Ƿ���Ҫ��������Ӳ�� */
	.tGPIO[1].tGPIOInit.Speed 			= GPIO_SPEED_FREQ_HIGH,		/* GPIO�ٶ� */	
	.tGPIO[1].tGPIOPort 				= GPIOA,					/* GPIO���� */
	.tGPIO[1].ucAFMode					= NO_REMAP,					/* GPIO��ӳ�� */
};

tagRM3100_T RM3100[4] = 
{
	[0]=
	{
		.bSPIEnable								= true,
		.tSPI.tSPIHandle.Instance 				= SPI1,
		.tSPI.tSPIHandle.Init.Mode 				= SPI_MODE_MASTER,
		.tSPI.tSPIHandle.Init.Direction 		= SPI_DIRECTION_2LINES,
		.tSPI.tSPIHandle.Init.DataSize 			= SPI_DATASIZE_8BIT,
		.tSPI.tSPIHandle.Init.CLKPolarity 		= SPI_POLARITY_LOW,
		.tSPI.tSPIHandle.Init.CLKPhase 			= SPI_PHASE_1EDGE,
		.tSPI.tSPIHandle.Init.NSS 				= SPI_NSS_SOFT,
		.tSPI.tSPIHandle.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_64,
		.tSPI.tSPIHandle.Init.FirstBit 			= SPI_FIRSTBIT_MSB,
		.tSPI.tSPIHandle.Init.TIMode 			= SPI_TIMODE_DISABLE,
		.tSPI.tSPIHandle.Init.CRCCalculation 	= SPI_CRCCALCULATION_DISABLE,
		.tSPI.tSPIHandle.Init.CRCPolynomial 	= 10,	
#if defined (STM32L4_SGA_ENABLE)
		.tSPI.tSPIHandle.Init.CRCLength 		= SPI_CRC_LENGTH_DATASIZE,
		.tSPI.tSPIHandle.Init.NSSPMode 			= SPI_NSS_PULSE_ENABLE,	
#endif
		/**SPI1 GPIO Configuration
		PA5     ------> SPI1_SCK
		PA6     ------> SPI1_MISO
		PA7     ------> SPI1_MOSI
		PC5     ------> SPI1_NSS
		*/
		.tSPI.tGPIO[0].tGPIOInit.Pin	= GPIO_PIN_5,
		.tSPI.tGPIO[0].tGPIOInit.Mode 	= GPIO_MODE_AF_PP,
		.tSPI.tGPIO[0].tGPIOInit.Speed 	= GPIO_SPEED_FREQ_HIGH,
		.tSPI.tGPIO[0].tGPIOPort		= GPIOA,
		.tSPI.tGPIO[0].ucAFMode			= NO_REMAP,

		.tSPI.tGPIO[1].tGPIOInit.Pin 	= GPIO_PIN_6,
		.tSPI.tGPIO[1].tGPIOInit.Mode 	= GPIO_MODE_AF_PP,
		.tSPI.tGPIO[1].tGPIOInit.Pull 	= GPIO_NOPULL,
		.tSPI.tGPIO[1].tGPIOPort		= GPIOA,
		.tSPI.tGPIO[1].ucAFMode			= NO_REMAP,

		.tSPI.tGPIO[2].tGPIOInit.Pin	= GPIO_PIN_7,
		.tSPI.tGPIO[2].tGPIOInit.Mode 	= GPIO_MODE_AF_PP,
		.tSPI.tGPIO[2].tGPIOInit.Speed 	= GPIO_SPEED_FREQ_HIGH,
		.tSPI.tGPIO[2].tGPIOPort		= GPIOA,
		.tSPI.tGPIO[2].ucAFMode			= NO_REMAP,
		
		.tSPI.tGPIO[3].tGPIOInit.Pin	= GPIO_PIN_5,
		.tSPI.tGPIO[3].tGPIOInit.Mode 	= GPIO_MODE_OUTPUT_PP,
		.tSPI.tGPIO[3].tGPIOInit.Speed 	= GPIO_SPEED_FREQ_HIGH,
		.tSPI.tGPIO[3].tGPIOPort		= GPIOC,
		.tSPI.tGPIO[3].ucAFMode			= NO_REMAP,
	
	},
	[1]=
	{
		.bSPIEnable								= true,
		.tSPI.tSPIHandle.Instance 				= SPI2,
		.tSPI.tSPIHandle.Init.Mode 				= SPI_MODE_MASTER,
		.tSPI.tSPIHandle.Init.Direction 		= SPI_DIRECTION_2LINES,
		.tSPI.tSPIHandle.Init.DataSize 			= SPI_DATASIZE_8BIT,
		.tSPI.tSPIHandle.Init.CLKPolarity 		= SPI_POLARITY_LOW,
		.tSPI.tSPIHandle.Init.CLKPhase 			= SPI_PHASE_1EDGE,
		.tSPI.tSPIHandle.Init.NSS 				= SPI_NSS_SOFT,
		.tSPI.tSPIHandle.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_32,
		.tSPI.tSPIHandle.Init.FirstBit 			= SPI_FIRSTBIT_MSB,
		.tSPI.tSPIHandle.Init.TIMode 			= SPI_TIMODE_DISABLE,
		.tSPI.tSPIHandle.Init.CRCCalculation 	= SPI_CRCCALCULATION_DISABLE,
		.tSPI.tSPIHandle.Init.CRCPolynomial 	= 10,	
#if defined (STM32L4_SGA_ENABLE)
		.tSPI.tSPIHandle.Init.CRCLength 		= SPI_CRC_LENGTH_DATASIZE,
		.tSPI.tSPIHandle.Init.NSSPMode 			= SPI_NSS_PULSE_ENABLE,	
#endif
		/**SPI2 GPIO Configuration
		PB13     ------> SPI2_SCK
		PB14     ------> SPI2_MISO
		PB15     ------> SPI2_MOSI
		PD9     ------> SPI2_NSS
		*/
		.tSPI.tGPIO[0].tGPIOInit.Pin	= GPIO_PIN_13,
		.tSPI.tGPIO[0].tGPIOInit.Mode 	= GPIO_MODE_AF_PP,
		.tSPI.tGPIO[0].tGPIOInit.Speed 	= GPIO_SPEED_FREQ_HIGH,
		.tSPI.tGPIO[0].tGPIOPort		= GPIOB,
		.tSPI.tGPIO[0].ucAFMode			= NO_REMAP,

		.tSPI.tGPIO[1].tGPIOInit.Pin 	= GPIO_PIN_14,
		.tSPI.tGPIO[1].tGPIOInit.Mode 	= GPIO_MODE_AF_PP,
		.tSPI.tGPIO[1].tGPIOInit.Pull 	= GPIO_NOPULL,
		.tSPI.tGPIO[1].tGPIOPort		= GPIOB,
		.tSPI.tGPIO[1].ucAFMode			= NO_REMAP,

		.tSPI.tGPIO[2].tGPIOInit.Pin	= GPIO_PIN_15,
		.tSPI.tGPIO[2].tGPIOInit.Mode 	= GPIO_MODE_AF_PP,
		.tSPI.tGPIO[2].tGPIOInit.Speed 	= GPIO_SPEED_FREQ_HIGH,
		.tSPI.tGPIO[2].tGPIOPort		= GPIOB,
		.tSPI.tGPIO[2].ucAFMode			= NO_REMAP,
		
		.tSPI.tGPIO[3].tGPIOInit.Pin	= GPIO_PIN_9,
		.tSPI.tGPIO[3].tGPIOInit.Mode 	= GPIO_MODE_OUTPUT_PP,
		.tSPI.tGPIO[3].tGPIOInit.Speed 	= GPIO_SPEED_FREQ_HIGH,
		.tSPI.tGPIO[3].tGPIOPort		= GPIOD,
		.tSPI.tGPIO[3].ucAFMode			= NO_REMAP,
	
	},
	[2]=
	{
		.bSPIEnable								= true,
		.tSPI.tSPIHandle.Instance 				= SPI3,
		.tSPI.tSPIHandle.Init.Mode 				= SPI_MODE_MASTER,
		.tSPI.tSPIHandle.Init.Direction 		= SPI_DIRECTION_2LINES,
		.tSPI.tSPIHandle.Init.DataSize 			= SPI_DATASIZE_8BIT,
		.tSPI.tSPIHandle.Init.CLKPolarity 		= SPI_POLARITY_LOW,
		.tSPI.tSPIHandle.Init.CLKPhase 			= SPI_PHASE_1EDGE,
		.tSPI.tSPIHandle.Init.NSS 				= SPI_NSS_SOFT,
		.tSPI.tSPIHandle.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_32,
		.tSPI.tSPIHandle.Init.FirstBit 			= SPI_FIRSTBIT_MSB,
		.tSPI.tSPIHandle.Init.TIMode 			= SPI_TIMODE_DISABLE,
		.tSPI.tSPIHandle.Init.CRCCalculation 	= SPI_CRCCALCULATION_DISABLE,
		.tSPI.tSPIHandle.Init.CRCPolynomial 	= 10,	
#if defined (STM32L4_SGA_ENABLE)
		.tSPI.tSPIHandle.Init.CRCLength 		= SPI_CRC_LENGTH_DATASIZE,
		.tSPI.tSPIHandle.Init.NSSPMode 			= SPI_NSS_PULSE_ENABLE,	
#endif
	/**SPI3 GPIO Configuration
		PB3     ------> SPI3_SCK
		PB4     ------> SPI3_MISO
		PB5     ------> SPI3_MOSI
		PB7     ------> SPI3_NSS
		*/
		.tSPI.tGPIO[0].tGPIOInit.Pin	= GPIO_PIN_3,
		.tSPI.tGPIO[0].tGPIOInit.Mode 	= GPIO_MODE_AF_PP,
		.tSPI.tGPIO[0].tGPIOInit.Speed 	= GPIO_SPEED_FREQ_HIGH,
		.tSPI.tGPIO[0].tGPIOPort		= GPIOB,
		.tSPI.tGPIO[0].ucAFMode			= NO_REMAP,

		.tSPI.tGPIO[1].tGPIOInit.Pin 	= GPIO_PIN_4,
		.tSPI.tGPIO[1].tGPIOInit.Mode 	= GPIO_MODE_AF_PP,
		.tSPI.tGPIO[1].tGPIOInit.Pull 	= GPIO_NOPULL,
		.tSPI.tGPIO[1].tGPIOPort		= GPIOB,
		.tSPI.tGPIO[1].ucAFMode			= NO_REMAP,

		.tSPI.tGPIO[2].tGPIOInit.Pin	= GPIO_PIN_5,
		.tSPI.tGPIO[2].tGPIOInit.Mode 	= GPIO_MODE_AF_PP,
		.tSPI.tGPIO[2].tGPIOInit.Speed 	= GPIO_SPEED_FREQ_HIGH,
		.tSPI.tGPIO[2].tGPIOPort		= GPIOB,
		.tSPI.tGPIO[2].ucAFMode			= NO_REMAP,
		
		.tSPI.tGPIO[3].tGPIOInit.Pin	= GPIO_PIN_7,
		.tSPI.tGPIO[3].tGPIOInit.Mode 	= GPIO_MODE_OUTPUT_PP,
		.tSPI.tGPIO[3].tGPIOInit.Speed 	= GPIO_SPEED_FREQ_HIGH,
		.tSPI.tGPIO[3].tGPIOPort		= GPIOB,
		.tSPI.tGPIO[3].ucAFMode			= NO_REMAP,
	},
	[3]=
	{
		/**SPI Soft GPIO Configuration
		PE2     ------> SPI_SCK
		PE4     ------> SPI_MISO
		PE3     ------> SPI_MOSI
		PE1     ------> SPI_NSS 
		*/
		.bSPISoftEnable							= true,
		.tSoftSPI.tSPISoft[0].tGPIOInit.Pin		= GPIO_PIN_2,
		.tSoftSPI.tSPISoft[0].tGPIOInit.Mode 	= GPIO_MODE_OUTPUT_PP,
		.tSoftSPI.tSPISoft[0].tGPIOInit.Pull 	= GPIO_PULLUP,
		.tSoftSPI.tSPISoft[0].tGPIOInit.Speed 	= GPIO_SPEED_FREQ_HIGH,
		.tSoftSPI.tSPISoft[0].tGPIOPort			= GPIOE,
		.tSoftSPI.tSPISoft[0].ucAFMode			= NO_REMAP,
		
		.tSoftSPI.tSPISoft[1].tGPIOInit.Pin		= GPIO_PIN_4,
		.tSoftSPI.tSPISoft[1].tGPIOInit.Mode 	= GPIO_MODE_INPUT,
		.tSoftSPI.tSPISoft[1].tGPIOInit.Pull 	= GPIO_PULLUP,
		.tSoftSPI.tSPISoft[1].tGPIOPort			= GPIOE,
		.tSoftSPI.tSPISoft[1].ucAFMode			= NO_REMAP,
		
		.tSoftSPI.tSPISoft[2].tGPIOInit.Pin		= GPIO_PIN_3,
		.tSoftSPI.tSPISoft[2].tGPIOInit.Mode 	= GPIO_MODE_OUTPUT_PP,
		.tSoftSPI.tSPISoft[2].tGPIOInit.Pull 	= GPIO_PULLUP,
		.tSoftSPI.tSPISoft[2].tGPIOInit.Speed 	= GPIO_SPEED_FREQ_HIGH,
		.tSoftSPI.tSPISoft[2].tGPIOPort			= GPIOE,
		.tSoftSPI.tSPISoft[2].ucAFMode			= NO_REMAP,
		
		.tSoftSPI.tSPISoft[3].tGPIOInit.Pin		= GPIO_PIN_1,
		.tSoftSPI.tSPISoft[3].tGPIOInit.Mode 	= GPIO_MODE_OUTPUT_PP,
		.tSoftSPI.tSPISoft[3].tGPIOInit.Pull 	= GPIO_PULLUP,
		.tSoftSPI.tSPISoft[3].tGPIOInit.Speed 	= GPIO_SPEED_FREQ_HIGH,
		.tSoftSPI.tSPISoft[3].tGPIOPort			= GPIOE,
		.tSoftSPI.tSPISoft[3].ucAFMode			= NO_REMAP,
	},
};


