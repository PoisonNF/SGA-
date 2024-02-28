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
	.tUARTHandle.Instance 						= USART1,					/* STM32 �����豸 */
	.tUARTHandle.Init.BaudRate   				= 115200,					/* ���ڲ����� */
	.tUARTHandle.Init.WordLength 				= UART_WORDLENGTH_8B,		/* ����λ���� */
	.tUARTHandle.Init.StopBits   				= UART_STOPBITS_1,			/* ֹͣλ���� */
	.tUARTHandle.Init.Parity     				= UART_PARITY_NONE,			/* У��λ���� */
	.tUARTHandle.Init.HwFlowCtl  				= UART_HWCONTROL_NONE,		/* Ӳ���������� */
	.tUARTHandle.Init.Mode       				= UART_MODE_TX_RX,			/* ����ģʽ */
	.tUARTHandle.Init.OverSampling 				= UART_OVERSAMPLING_16,		/* ������ */

#if defined (STM32L4_SGA_ENABLE)
	.tUARTHandle.Init.OneBitSampling 			= UART_ONE_BIT_SAMPLE_DISABLE,
	.tUARTHandle.AdvancedInit.AdvFeatureInit 	= UART_ADVFEATURE_NO_INIT,
#endif
	
	.ucPriority									= 1,						/* �ж����ȼ� */
	.ucSubPriority								= 3,						/* �ж������ȼ� */
	
	//����DMA���ղ�������
	.tUartDMA.bRxEnable							= true,						/* DMA����ʹ�� */
	.tUartDMA.tDMARx.Instance					= DMA1_Channel5,
	.tUartDMA.tDMARx.Init.Direction				= DMA_PERIPH_TO_MEMORY,
	.tUartDMA.tDMARx.Init.PeriphInc				= DMA_PINC_DISABLE,
	.tUartDMA.tDMARx.Init.MemInc				= DMA_MINC_ENABLE,
	.tUartDMA.tDMARx.Init.PeriphDataAlignment 	= DMA_PDATAALIGN_BYTE,
	.tUartDMA.tDMARx.Init.MemDataAlignment	  	= DMA_MDATAALIGN_BYTE,
	.tUartDMA.tDMARx.Init.Mode					= DMA_CIRCULAR,
	.tUartDMA.tDMARx.Init.Priority				= DMA_PRIORITY_LOW,

	.tRxInfo.usDMARxMAXSize             		= 100,              		/* DMA���ջ�������С ��С������Э����ֽ�*2���ϣ�ȷ�������һ���ܹ��ȶ�����һ������������֡*/

	.tUartDMA.ucDMARxPriority					= 1,						/* DMA�����ж����ȼ� */
	.tUartDMA.ucDMARxSubPriority				= 1,						/* DMA�����ж������ȼ� */
	
	//����DMA���Ͳ�������
	.tUartDMA.bTxEnable							= true,						/* DMA����ʹ�� */
	.tUartDMA.tDMATx.Instance					= DMA1_Channel4,
	.tUartDMA.tDMATx.Init.Direction				= DMA_MEMORY_TO_PERIPH,
	.tUartDMA.tDMATx.Init.PeriphInc				= DMA_PINC_DISABLE,
	.tUartDMA.tDMATx.Init.MemInc				= DMA_MINC_ENABLE,
	.tUartDMA.tDMATx.Init.PeriphDataAlignment	= DMA_PDATAALIGN_BYTE,
	.tUartDMA.tDMATx.Init.MemDataAlignment		= DMA_MDATAALIGN_BYTE,
	.tUartDMA.tDMATx.Init.Mode					= DMA_NORMAL,
	.tUartDMA.tDMATx.Init.Priority				= DMA_PRIORITY_LOW,

	.tTxInfo.usDMATxMAXSize						= 50,						/* DMA���ͻ�������С */
	
	.tUartDMA.ucDMATxPriority					= 1,						/* DMA�����ж����ȼ� */
	.tUartDMA.ucDMATxSubPriority				= 1,						/* DMA�����ж������ȼ� */

	//����GPIO����
	.tGPIO[0].tGPIOInit.Pin 					= GPIO_PIN_9,				/* GPIO���� */
	.tGPIO[0].tGPIOInit.Mode 					= GPIO_MODE_AF_PP,			/* GPIOģʽ */
	.tGPIO[0].tGPIOInit.Pull 					= GPIO_NOPULL,				/* GPIO���������ã��Ƿ���Ҫ��������Ӳ�� */
	.tGPIO[0].tGPIOInit.Speed 					= GPIO_SPEED_FREQ_HIGH,		/* GPIO�ٶ� */	
	.tGPIO[0].tGPIOPort 						= GPIOA,					/* GPIO���� */
	.tGPIO[0].ucAFMode							= NO_REMAP,					/* GPIO��ӳ�� */
	
	.tGPIO[1].tGPIOInit.Pin 					= GPIO_PIN_10,				/* GPIO���� */
	.tGPIO[1].tGPIOInit.Mode 					= GPIO_MODE_INPUT,			/* GPIOģʽ */
	.tGPIO[1].tGPIOInit.Pull 					= GPIO_NOPULL,				/* GPIO���������ã��Ƿ���Ҫ��������Ӳ�� */
	.tGPIO[1].tGPIOInit.Speed 					= GPIO_SPEED_FREQ_HIGH,		/* GPIO�ٶ� */	
	.tGPIO[1].tGPIOPort 						= GPIOA,					/* GPIO���� */
	.tGPIO[1].ucAFMode							= NO_REMAP,					/* GPIO��ӳ�� */
};


tagCAN_T CAN =
{
	/* CAN���� */
	.tCANHandle.Instance = CAN1,
	.tCANHandle.Init.Prescaler = 4,									/* ��Ƶϵ�� */
	.tCANHandle.Init.Mode = CAN_MODE_LOOPBACK,						/* ģʽ���� */
	.tCANHandle.Init.SyncJumpWidth = CAN_SJW_1TQ,					/* ����ͬ����Ծ��� */
	.tCANHandle.Init.TimeSeg1 = CAN_BS1_9TQ,						/* Tbs1 */
	.tCANHandle.Init.TimeSeg2 = CAN_BS2_8TQ,						/* Tbs2 */
	.tCANHandle.Init.TimeTriggeredMode = DISABLE,					/* ��ʱ�䴥��ͨ��ģʽ */
	.tCANHandle.Init.AutoBusOff = DISABLE,							/* ����Զ����߹��� */
	.tCANHandle.Init.AutoRetransmission = DISABLE,					/* ˯��ģʽͨ��������� */
	.tCANHandle.Init.AutoWakeUp = DISABLE,							/* ��ֹ�����Զ����� */
	.tCANHandle.Init.ReceiveFifoLocked = DISABLE,					/* ���Ĳ�����,�µĸ��Ǿɵ� */
	.tCANHandle.Init.TransmitFifoPriority = DISABLE,				/* ���ȼ��ɱ��ı�ʶ������ */

	/* CAN���������� */
	.tCANFilter.FilterBank = 0,										/* ������0 */
	.tCANFilter.FilterMode = CAN_FILTERMODE_IDMASK,					/* ������ģʽ */
	.tCANFilter.FilterScale = CAN_FILTERSCALE_32BIT,				/* ������λ�� */
	.tCANFilter.FilterIdHigh = 0x0000,
	.tCANFilter.FilterIdLow = 0x0000,
	.tCANFilter.FilterMaskIdHigh = 0x0000,
	.tCANFilter.FilterMaskIdLow = 0x0000,
	.tCANFilter.FilterFIFOAssignment = CAN_RX_FIFO0,				/* ������������FIFO0 */
	.tCANFilter.FilterActivation = ENABLE,							/* ���������0 */
	.tCANFilter.SlaveStartFilterBank = 14,							/* ��CAN��������ʼ */

	/* CAN TX���� */
	.tCANTxHeader.StdId = 0x12,										/* ��׼��ʶ�� */
	.tCANTxHeader.ExtId = 0x12,										/* ��չ��ʶ����29λ�� */
	.tCANTxHeader.IDE = CAN_ID_STD,    								/* ʹ�ñ�׼֡ */
	.tCANTxHeader.RTR = CAN_RTR_DATA,								/* ����֡ */
    
	/* CAN �ж����ȼ����� */
	.ucTxPriority										= 3,							/* ���������ȼ� */
	.ucTxSubPriority									= 1,							/* ���������ȼ� */

	.ucRxPriority										= 2,							/* ���������ȼ� */
	.ucRxSubPriority									= 1,							/* ���������ȼ� */

	/* CAN GPIO���� */
	.tGPIO[0].tGPIOInit.Pin 		= GPIO_PIN_12,				/* GPIO���� */
	.tGPIO[0].tGPIOInit.Mode 		= GPIO_MODE_AF_PP,			/* GPIOģʽ */
	.tGPIO[0].tGPIOInit.Pull 		= GPIO_PULLUP,				/* GPIO���������ã��Ƿ���Ҫ��������Ӳ�� */
	.tGPIO[0].tGPIOInit.Speed 		= GPIO_SPEED_FREQ_HIGH,		/* GPIO�ٶ� */	
	.tGPIO[0].tGPIOPort 			= GPIOA,					/* GPIO���� */			

	.tGPIO[1].tGPIOInit.Pin 		= GPIO_PIN_11,				/* GPIO���� */
	.tGPIO[1].tGPIOInit.Mode 		= GPIO_MODE_AF_INPUT,		/* GPIOģʽ */
	.tGPIO[1].tGPIOInit.Pull 		= GPIO_PULLUP,				/* GPIO���������ã��Ƿ���Ҫ��������Ӳ�� */
	.tGPIO[1].tGPIOInit.Speed 		= GPIO_SPEED_FREQ_HIGH,		/* GPIO�ٶ� */	
	.tGPIO[1].tGPIOPort 			= GPIOA,					/* GPIO���� */			
};

