#include "task_conf.h"
#include "usercode.h"
#include "config.h"


/**
 * @brief �ⲿ�ж�5-9������
 * @retval Null
*/
void EXTI9_5_IRQHandler(void)
{
    //Drv_GPIO_EXTI_IRQHandler(&DS3231_ALARM_IRQ);	/* ����ӣ��������޸� */
}

/**
 * @brief �ⲿ�ж�10-15������
 * @retval Null
*/
void EXTI15_10_IRQHandler(void)
{
    //Drv_GPIO_EXTI_IRQHandler(&tPCUart.tGPIO[1]);	/* ����ӣ��������޸� */
}

/**
 * @brief ����1�жϷ�����
 * @retval Null
*/
void USART1_IRQHandler(void)
{
	/* ʾ�� */
    //Drv_Uart_IRQHandler(&tPCUart);		/* ���貿�� */
    Drv_Uart_IRQHandler(&demoUart);
}

/**
 * @brief ����2�жϷ�����
 * @retval Null
*/
void USART2_IRQHandler(void)
{
	/* ʾ�� */
    //Drv_Uart_IRQHandler(&tJY901B.tUART);		/* ���貿�� */
}

/**
 * @brief ����3�жϷ�����
 * @retval Null
*/
void USART3_IRQHandler(void)
{

}

/**
 * @brief ����4�жϷ�����
 * @retval Null
*/
void UART4_IRQHandler(void)
{

}

/**
 * @brief ����5�жϷ�����
 * @retval Null
*/
void UART5_IRQHandler(void)
{

}

/**
 * @brief ��ʱ��2�жϷ�����
 * @retval Null
*/
void TIM2_IRQHandler(void)
{
	/* ʾ�� */
    //Drv_Timer_IRQHandler(&demoTIM);
}

/**
 * @brief ��ʱ��3�жϷ�����
 * @retval Null
*/
void TIM3_IRQHandler(void)
{
	/* ʾ�� */
    //Drv_Timer_IRQHandler(&demoTIM);
}

/**
 * @brief ��ʱ��4�жϷ�����
 * @retval Null
*/
void TIM4_IRQHandler(void)
{
    /* ʾ�� */
    //Drv_Timer_IRQHandler(&demoTIM);
}

/**
 * @brief ��ʱ��5�жϷ�����
 * @retval Null
*/
void TIM5_IRQHandler(void)
{
    /* ʾ�� */
    //Drv_Timer_IRQHandler(&demoTIM);
}

/**
 * @brief ��ʱ��6�жϷ�����
 * @retval Null
*/
void TIM6_IRQHandler(void)
{
    /* ʾ�� */
    //Drv_Timer_IRQHandler(&demoTIM);
}

/**
 * @brief ��ʱ��7�жϷ�����
 * @retval Null
*/
void TIM7_IRQHandler(void)
{
	/* ʾ�� */
    //Drv_Timer_IRQHandler(&demoTIM);
}

void CAN1_RX0_IRQHandler(void)
{
    Drv_CAN_IRQHandler(&CAN);
}

void CAN1_RX1_IRQHandler(void)
{
    Drv_CAN_IRQHandler(&CAN);
}

void CAN1_TX_IRQHandler(void)
{
    Drv_CAN_IRQHandler(&CAN);
}

uint8_t ReceBuffer0[8];
uint8_t ReceBuffer1[8];
uint8_t num0;
uint8_t num1;

void HAL_CAN_RxFifo0MsgPendingCallback(CAN_HandleTypeDef *hcan1)
{
	num0 = Drv_CAN_ReceMsg(&CAN,ReceBuffer0,CAN_RX_FIFO0);
	if(num0 != 0)
	{
        printf("fifo0 %s\r\n",ReceBuffer0);
	}
}

void HAL_CAN_RxFifo1MsgPendingCallback(CAN_HandleTypeDef *hcan1)
{
	num1 = Drv_CAN_ReceMsg(&CAN,ReceBuffer1,CAN_RX_FIFO1);
    if(num1 != 0)
	{
        printf("fifo1 %s\r\n",ReceBuffer1);
	}
}

void HAL_CAN_RxFifo0FullCallback(CAN_HandleTypeDef *hcan)
{
    printf("FIFO0 FULL\r\n");
}

void HAL_CAN_RxFifo1FullCallback(CAN_HandleTypeDef *hcan)
{
    printf("FIFO1 FULL\r\n");
}
