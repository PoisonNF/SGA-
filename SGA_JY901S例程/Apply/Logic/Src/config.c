#include "config.h"

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

/* JY901Sʾ�� */
tagJY901_T JY901S = 
{
	.tConfig.ucBaud 	= JY901_RXBAUD_9600,
	.tConfig.ucRate		= JY901_RX_1HZ,
	.tConfig.usType		= JY901_OUTPUT_ACCEL | JY901_OUTPUT_GYRO | JY901_OUTPUT_ANGLE | JY901_OUTPUT_MAG | JY901_OUTPUT_GPS,
    .tConfig.ucOrient   = JY901_ORIENT_HORIZONTAL,
    .tConfig.ucAxis     = JY901_AXIS_9,

	.tUART.tUARTHandle.Instance 				= USART2,			/* STM32 �����豸 */
	.tUART.tUARTHandle.Init.BaudRate   			= 9600,				/* ���ڲ����� */
	.tUART.tUARTHandle.Init.WordLength 			= UART_WORDLENGTH_8B,
	.tUART.tUARTHandle.Init.StopBits   			= UART_STOPBITS_1,
	.tUART.tUARTHandle.Init.Parity     			= UART_PARITY_NONE,
	.tUART.tUARTHandle.Init.HwFlowCtl  			= UART_HWCONTROL_NONE,
	.tUART.tUARTHandle.Init.Mode       			= UART_MODE_TX_RX,
	.tUART.tUARTHandle.Init.OverSampling 		= UART_OVERSAMPLING_16,

	.tUART.tRxInfo.usDMARxMAXSize             	= 300,                 /* �������ݳ��� ���ȱ�����Э����ֽ�*2���ϣ�ȷ�������һ���ܹ��ȶ�����һ������������֡*/

#if defined (STM32L4_SGA_ENABLE)
	.tUARTHandle.Init.OneBitSampling 	= UART_ONE_BIT_SAMPLE_DISABLE,
	.tUARTHandle.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT,
#endif
	
	.tUART.ucPriority							= 1,				/* �ж����ȼ� */
	.tUART.ucSubPriority						= 3,				/* �ж������ȼ� */
	
    .tUART.tUartDMA.bRxEnable					    = true,						/* DMA����ʹ�� */
	.tUART.tUartDMA.tDMARx.Instance					= DMA1_Channel6,
	.tUART.tUartDMA.tDMARx.Init.Direction			= DMA_PERIPH_TO_MEMORY,
	.tUART.tUartDMA.tDMARx.Init.PeriphInc			= DMA_PINC_DISABLE,
	.tUART.tUartDMA.tDMARx.Init.MemInc				= DMA_MINC_ENABLE,
	.tUART.tUartDMA.tDMARx.Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE,
	.tUART.tUartDMA.tDMARx.Init.MemDataAlignment	= DMA_MDATAALIGN_BYTE,
	.tUART.tUartDMA.tDMARx.Init.Mode				= DMA_CIRCULAR,
	.tUART.tUartDMA.tDMARx.Init.Priority			= DMA_PRIORITY_LOW,

	.tUART.tUartDMA.ucDMARxPriority				= 1,				/* DMA�ж����ȼ� */
	.tUART.tUartDMA.ucDMARxSubPriority			= 1,				/* DMA�ж������ȼ� */
	
	
	.tUART.tGPIO[0].tGPIOInit.Pin 			= GPIO_PIN_2,				/* GPIO���� */
	.tUART.tGPIO[0].tGPIOInit.Mode 			= GPIO_MODE_AF_PP,			/* GPIOģʽ */
	.tUART.tGPIO[0].tGPIOInit.Pull 			= GPIO_NOPULL,				/* GPIO���������ã��Ƿ���Ҫ��������Ӳ�� */
	.tUART.tGPIO[0].tGPIOInit.Speed 		= GPIO_SPEED_FREQ_HIGH,		/* GPIO�ٶ� */	
	.tUART.tGPIO[0].tGPIOPort 				= GPIOA,					/* GPIO���� */
	.tUART.tGPIO[0].ucAFMode				= NO_REMAP,					/* GPIO��ӳ�� */
	
	.tUART.tGPIO[1].tGPIOInit.Pin 			= GPIO_PIN_3,				/* GPIO���� */
	.tUART.tGPIO[1].tGPIOInit.Mode 			= GPIO_MODE_INPUT,			/* GPIOģʽ */
	.tUART.tGPIO[1].tGPIOInit.Pull 			= GPIO_NOPULL,				/* GPIO���������ã��Ƿ���Ҫ��������Ӳ�� */
	.tUART.tGPIO[1].tGPIOInit.Speed 		= GPIO_SPEED_FREQ_HIGH,		/* GPIO�ٶ� */	
	.tUART.tGPIO[1].tGPIOPort 				= GPIOA,					/* GPIO���� */
	.tUART.tGPIO[1].ucAFMode				= NO_REMAP,					/* GPIO��ӳ�� */
};

