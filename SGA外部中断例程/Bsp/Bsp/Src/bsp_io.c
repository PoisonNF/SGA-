#include "bsp_io.h"


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
	
	.ulPriority							= 1,						/* �ж����ȼ� */
	.ulSubPriority						= 3,						/* �ж������ȼ� */
	
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

	.tRxInfo.usRxMAXLenth             	= 100,              		/* �������ݳ��� ���ȱ�����Э����ֽ�*2���ϣ�ȷ�������һ���ܹ��ȶ�����һ������������֡*/

	.tUartDMA.ulDMARxPriority				= 1,					/* DMA�����ж����ȼ� */
	.tUartDMA.ulDMARxSubPriority			= 1,					/* DMA�����ж������ȼ� */
	
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

	.tTxInfo.usTxMAXLenth				= 50,						/* ��������ݳ��� */
	
	.tUartDMA.ulDMATxPriority				= 1,					/* DMA�����ж����ȼ� */
	.tUartDMA.ulDMATxSubPriority			= 1,					/* DMA�����ж������ȼ� */

	//����GPIO����
	.tGPIO[0].tGPIOInit.Pin 			= GPIO_PIN_9,				/* GPIO���� */
	.tGPIO[0].tGPIOInit.Mode 			= GPIO_MODE_AF_PP,			/* GPIOģʽ */
	.tGPIO[0].tGPIOInit.Pull 			= GPIO_NOPULL,				/* GPIO���������ã��Ƿ���Ҫ��������Ӳ�� */
	.tGPIO[0].tGPIOInit.Speed 			= GPIO_SPEED_FREQ_HIGH,		/* GPIO�ٶ� */	
	.tGPIO[0].tGPIOPort 				= GPIOA,					/* GPIO���� */
	.tGPIO[0].AFMode					= NO_REMAP,					/* GPIO��ӳ�� */
	
	.tGPIO[1].tGPIOInit.Pin 			= GPIO_PIN_10,				/* GPIO���� */
	.tGPIO[1].tGPIOInit.Mode 			= GPIO_MODE_INPUT,			/* GPIOģʽ */
	.tGPIO[1].tGPIOInit.Pull 			= GPIO_NOPULL,				/* GPIO���������ã��Ƿ���Ҫ��������Ӳ�� */
	.tGPIO[1].tGPIOInit.Speed 			= GPIO_SPEED_FREQ_HIGH,		/* GPIO�ٶ� */	
	.tGPIO[1].tGPIOPort 				= GPIOA,					/* GPIO���� */
	.tGPIO[1].AFMode					= NO_REMAP,					/* GPIO��ӳ�� */
};



/* ���SPI�������� */
tagSPISoft_T SPI_soft[2] =
{
	[0]=
	{
	/**SPI Soft GPIO Configuration
    PE2     ------> SPI_SCK
	PE4     ------> SPI_MISO
    PE3     ------> SPI_MOSI
	PE1     ------> SPI_NSS 
    */
	.tSPISoft[0].tGPIOInit.Pin		= GPIO_PIN_2,
	.tSPISoft[0].tGPIOInit.Mode 	= GPIO_MODE_OUTPUT_PP,
	.tSPISoft[0].tGPIOInit.Pull 	= GPIO_PULLUP,
	.tSPISoft[0].tGPIOInit.Speed 	= GPIO_SPEED_FREQ_HIGH,
	.tSPISoft[0].tGPIOPort			= GPIOE,
	.tSPISoft[0].AFMode				= NO_REMAP,
	
	.tSPISoft[1].tGPIOInit.Pin		= GPIO_PIN_4,
	.tSPISoft[1].tGPIOInit.Mode 	= GPIO_MODE_INPUT,
	.tSPISoft[1].tGPIOInit.Pull 	= GPIO_PULLUP,
	.tSPISoft[1].tGPIOPort			= GPIOE,
	.tSPISoft[1].AFMode				= NO_REMAP,
	
	.tSPISoft[2].tGPIOInit.Pin		= GPIO_PIN_3,
	.tSPISoft[2].tGPIOInit.Mode 	= GPIO_MODE_OUTPUT_PP,
	.tSPISoft[2].tGPIOInit.Pull 	= GPIO_PULLUP,
	.tSPISoft[2].tGPIOInit.Speed 	= GPIO_SPEED_FREQ_HIGH,
	.tSPISoft[2].tGPIOPort			= GPIOE,
	.tSPISoft[2].AFMode				= NO_REMAP,
	
	.tSPISoft[3].tGPIOInit.Pin		= GPIO_PIN_1,
	.tSPISoft[3].tGPIOInit.Mode 	= GPIO_MODE_OUTPUT_PP,
	.tSPISoft[3].tGPIOInit.Pull 	= GPIO_PULLUP,
	.tSPISoft[3].tGPIOInit.Speed 	= GPIO_SPEED_FREQ_HIGH,
	.tSPISoft[3].tGPIOPort			= GPIOE,
	.tSPISoft[3].AFMode				= NO_REMAP,
	},
	[1] = 
	{
	/**SPI Soft GPIO Configuration
    PB13      ------> SPI_SCK
    PB14      ------> SPI_MISO 
    PB15      ------> SPI_MOSI
    PD9      ------> SPI_NSS
    */
	.tSPISoft[0].tGPIOInit.Pin		= GPIO_PIN_13,
	.tSPISoft[0].tGPIOInit.Mode 	= GPIO_MODE_OUTPUT_PP,
	.tSPISoft[0].tGPIOInit.Pull 	= GPIO_PULLUP,
	.tSPISoft[0].tGPIOInit.Speed 	= GPIO_SPEED_FREQ_HIGH,
	.tSPISoft[0].tGPIOPort			= GPIOB,
	.tSPISoft[0].AFMode				= NO_REMAP,
	
	.tSPISoft[1].tGPIOInit.Pin		= GPIO_PIN_14,
	.tSPISoft[1].tGPIOInit.Mode 	= GPIO_MODE_INPUT,
	.tSPISoft[1].tGPIOInit.Pull 	= GPIO_PULLUP,
	.tSPISoft[1].tGPIOPort			= GPIOB,
	.tSPISoft[1].AFMode				= NO_REMAP,
	
	.tSPISoft[2].tGPIOInit.Pin		= GPIO_PIN_15,
	.tSPISoft[2].tGPIOInit.Mode 	= GPIO_MODE_OUTPUT_PP,
	.tSPISoft[2].tGPIOInit.Pull 	= GPIO_PULLUP,
	.tSPISoft[2].tGPIOInit.Speed 	= GPIO_SPEED_FREQ_HIGH,
	.tSPISoft[2].tGPIOPort			= GPIOB,
	.tSPISoft[2].AFMode				= NO_REMAP,
	
	.tSPISoft[3].tGPIOInit.Pin		= GPIO_PIN_9,
	.tSPISoft[3].tGPIOInit.Mode 	= GPIO_MODE_OUTPUT_PP,
	.tSPISoft[3].tGPIOInit.Pull 	= GPIO_PULLUP,
	.tSPISoft[3].tGPIOInit.Speed	= GPIO_SPEED_FREQ_HIGH,
	.tSPISoft[3].tGPIOPort			= GPIOD,
	.tSPISoft[3].AFMode				= NO_REMAP,
	},
};

/* Ӳ��SPI�������� */
tagSPI_T SPI[3] =
{
	[0]=
	{
	.tSPIHandle.Instance 				= SPI1,
	.tSPIHandle.Init.Mode 				= SPI_MODE_MASTER,
	.tSPIHandle.Init.Direction 			= SPI_DIRECTION_2LINES,
	.tSPIHandle.Init.DataSize 			= SPI_DATASIZE_8BIT,
	.tSPIHandle.Init.CLKPolarity 		= SPI_POLARITY_LOW,
	.tSPIHandle.Init.CLKPhase 			= SPI_PHASE_1EDGE,
	.tSPIHandle.Init.NSS 				= SPI_NSS_SOFT,
	.tSPIHandle.Init.BaudRatePrescaler  = SPI_BAUDRATEPRESCALER_64,
	.tSPIHandle.Init.FirstBit 			= SPI_FIRSTBIT_MSB,
	.tSPIHandle.Init.TIMode 			= SPI_TIMODE_DISABLE,
	.tSPIHandle.Init.CRCCalculation 	= SPI_CRCCALCULATION_DISABLE,
	.tSPIHandle.Init.CRCPolynomial 		= 10,	
#if defined (STM32L4_SGA_ENABLE)
	.tSPIHandle.Init.CRCLength 		= SPI_CRC_LENGTH_DATASIZE,
	.tSPIHandle.Init.NSSPMode 			= SPI_NSS_PULSE_ENABLE,	
#endif
    /**SPI1 GPIO Configuration
    PA5     ------> SPI1_SCK
    PA6     ------> SPI1_MISO
    PA7     ------> SPI1_MOSI
	PC5     ------> SPI1_NSS
    */
    .tGPIO[0].tGPIOInit.Pin		= GPIO_PIN_5,
	.tGPIO[0].tGPIOInit.Mode 	= GPIO_MODE_AF_PP,
	.tGPIO[0].tGPIOInit.Speed 	= GPIO_SPEED_FREQ_HIGH,
	.tGPIO[0].tGPIOPort			= GPIOA,
	.tGPIO[0].AFMode			= NO_REMAP,

	.tGPIO[1].tGPIOInit.Pin 	= GPIO_PIN_6,
	.tGPIO[1].tGPIOInit.Mode 	= GPIO_MODE_AF_PP,
	.tGPIO[1].tGPIOInit.Pull 	= GPIO_NOPULL,
	.tGPIO[1].tGPIOPort			= GPIOA,
	.tGPIO[1].AFMode			= NO_REMAP,

	.tGPIO[2].tGPIOInit.Pin		= GPIO_PIN_7,
	.tGPIO[2].tGPIOInit.Mode 	= GPIO_MODE_AF_PP,
	.tGPIO[2].tGPIOInit.Speed 	= GPIO_SPEED_FREQ_HIGH,
	.tGPIO[2].tGPIOPort			= GPIOA,
	.tGPIO[2].AFMode			= NO_REMAP,
	
	.tGPIO[3].tGPIOInit.Pin		= GPIO_PIN_5,
	.tGPIO[3].tGPIOInit.Mode 	= GPIO_MODE_OUTPUT_PP,
	.tGPIO[3].tGPIOInit.Speed 	= GPIO_SPEED_FREQ_HIGH,
	.tGPIO[3].tGPIOPort			= GPIOC,
	.tGPIO[3].AFMode			= NO_REMAP,
	
	},
	[1]=
	{
	.tSPIHandle.Instance 				= SPI2,
	.tSPIHandle.Init.Mode 				= SPI_MODE_MASTER,
	.tSPIHandle.Init.Direction 			= SPI_DIRECTION_2LINES,
	.tSPIHandle.Init.DataSize 			= SPI_DATASIZE_8BIT,
	.tSPIHandle.Init.CLKPolarity 		= SPI_POLARITY_LOW,
	.tSPIHandle.Init.CLKPhase 			= SPI_PHASE_1EDGE,
	.tSPIHandle.Init.NSS 				= SPI_NSS_SOFT,
	.tSPIHandle.Init.BaudRatePrescaler  = SPI_BAUDRATEPRESCALER_32,
	.tSPIHandle.Init.FirstBit 			= SPI_FIRSTBIT_MSB,
	.tSPIHandle.Init.TIMode 			= SPI_TIMODE_DISABLE,
	.tSPIHandle.Init.CRCCalculation 	= SPI_CRCCALCULATION_DISABLE,
	.tSPIHandle.Init.CRCPolynomial 		= 10,	
#if defined (STM32L4_SGA_ENABLE)
	.tSPIHandle.Init.CRCLength 		= SPI_CRC_LENGTH_DATASIZE,
	.tSPIHandle.Init.NSSPMode 			= SPI_NSS_PULSE_ENABLE,	
#endif
    /**SPI2 GPIO Configuration
    PB13     ------> SPI2_SCK
    PB14     ------> SPI2_MISO
    PB15     ------> SPI2_MOSI
	PD9     ------> SPI2_NSS
    */
    .tGPIO[0].tGPIOInit.Pin		= GPIO_PIN_13,
	.tGPIO[0].tGPIOInit.Mode 	= GPIO_MODE_AF_PP,
	.tGPIO[0].tGPIOInit.Speed 	= GPIO_SPEED_FREQ_HIGH,
	.tGPIO[0].tGPIOPort			= GPIOB,
	.tGPIO[0].AFMode			= NO_REMAP,

	.tGPIO[1].tGPIOInit.Pin 	= GPIO_PIN_14,
	.tGPIO[1].tGPIOInit.Mode 	= GPIO_MODE_AF_PP,
	.tGPIO[1].tGPIOInit.Pull 	= GPIO_NOPULL,
	.tGPIO[1].tGPIOPort			= GPIOB,
	.tGPIO[1].AFMode			= NO_REMAP,

	.tGPIO[2].tGPIOInit.Pin		= GPIO_PIN_15,
	.tGPIO[2].tGPIOInit.Mode 	= GPIO_MODE_AF_PP,
	.tGPIO[2].tGPIOInit.Speed 	= GPIO_SPEED_FREQ_HIGH,
	.tGPIO[2].tGPIOPort			= GPIOB,
	.tGPIO[2].AFMode			= NO_REMAP,
	
	.tGPIO[3].tGPIOInit.Pin		= GPIO_PIN_9,
	.tGPIO[3].tGPIOInit.Mode 	= GPIO_MODE_OUTPUT_PP,
	.tGPIO[3].tGPIOInit.Speed 	= GPIO_SPEED_FREQ_HIGH,
	.tGPIO[3].tGPIOPort			= GPIOD,
	.tGPIO[3].AFMode			= NO_REMAP,
	
	},
	[2]=
	{
	.tSPIHandle.Instance 				= SPI3,
	.tSPIHandle.Init.Mode 				= SPI_MODE_MASTER,
	.tSPIHandle.Init.Direction 			= SPI_DIRECTION_2LINES,
	.tSPIHandle.Init.DataSize 			= SPI_DATASIZE_8BIT,
	.tSPIHandle.Init.CLKPolarity 		= SPI_POLARITY_LOW,
	.tSPIHandle.Init.CLKPhase 			= SPI_PHASE_1EDGE,
	.tSPIHandle.Init.NSS 				= SPI_NSS_SOFT,
	.tSPIHandle.Init.BaudRatePrescaler  = SPI_BAUDRATEPRESCALER_32,
	.tSPIHandle.Init.FirstBit 			= SPI_FIRSTBIT_MSB,
	.tSPIHandle.Init.TIMode 			= SPI_TIMODE_DISABLE,
	.tSPIHandle.Init.CRCCalculation 	= SPI_CRCCALCULATION_DISABLE,
	.tSPIHandle.Init.CRCPolynomial 		= 10,	
#if defined (STM32L4_SGA_ENABLE)
	.tSPIHandle.Init.CRCLength 		= SPI_CRC_LENGTH_DATASIZE,
	.tSPIHandle.Init.NSSPMode 			= SPI_NSS_PULSE_ENABLE,	
#endif
   /**SPI3 GPIO Configuration
    PB3     ------> SPI3_SCK
    PB4     ------> SPI3_MISO
    PB5     ------> SPI3_MOSI
	PB7     ------> SPI3_NSS
    */
    .tGPIO[0].tGPIOInit.Pin		= GPIO_PIN_3,
	.tGPIO[0].tGPIOInit.Mode 	= GPIO_MODE_AF_PP,
	.tGPIO[0].tGPIOInit.Speed 	= GPIO_SPEED_FREQ_HIGH,
	.tGPIO[0].tGPIOPort			= GPIOB,
	.tGPIO[0].AFMode			= NO_REMAP,

	.tGPIO[1].tGPIOInit.Pin 	= GPIO_PIN_4,
	.tGPIO[1].tGPIOInit.Mode 	= GPIO_MODE_AF_PP,
	.tGPIO[1].tGPIOInit.Pull 	= GPIO_NOPULL,
	.tGPIO[1].tGPIOPort			= GPIOB,
	.tGPIO[1].AFMode			= NO_REMAP,

	.tGPIO[2].tGPIOInit.Pin		= GPIO_PIN_5,
	.tGPIO[2].tGPIOInit.Mode 	= GPIO_MODE_AF_PP,
	.tGPIO[2].tGPIOInit.Speed 	= GPIO_SPEED_FREQ_HIGH,
	.tGPIO[2].tGPIOPort			= GPIOB,
	.tGPIO[2].AFMode			= NO_REMAP,
	
	.tGPIO[3].tGPIOInit.Pin		= GPIO_PIN_7,
	.tGPIO[3].tGPIOInit.Mode 	= GPIO_MODE_OUTPUT_PP,
	.tGPIO[3].tGPIOInit.Speed 	= GPIO_SPEED_FREQ_HIGH,
	.tGPIO[3].tGPIOPort			= GPIOB,
	.tGPIO[3].AFMode			= NO_REMAP,
	},
	
};



