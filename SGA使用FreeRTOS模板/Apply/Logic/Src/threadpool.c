#include "usercode.h"		/* usercodeͷ�ļ� */
#include "threadpool.h"		/* threadpoolͷ�ļ� */
#include "drv_hal_conf.h"   /* SGA��ͷ�ļ����� */
#include "task_conf.h"      /* task��ͷ�ļ����� */
#include "ocd_conf.h"       /* OCD��ͷ�ļ����� */
#include "dev_conf.h"		/* Dev��ͷ�ļ����� */
#include "algo_conf.h"		/* Algo��ͷ�ļ����� */
#include "config.h"			/* I/O����ͷ�ļ����� */


/* �߳���ں�����ʹ��������Դ��ļ��� */


void Task1(void *argument)
{
    while(1)
    {
        osSemaphoreWait(myBinarySem01Handle,0xffff); //�ź�����һ
        printf("�߳�1����ź���\r\n");

        HAL_UART_Transmit(&demoUart.tUARTHandle,"�߳�1ִ��\r\n",sizeof("�߳�1ִ��\r\n"),1000);
        Drv_Delay_Ms(1000);

        osSemaphoreRelease(myBinarySem01Handle);

        osThreadYield();
    }

}

void Task2(void *argument)
{
    while(1)
    {
        osSemaphoreWait(myBinarySem01Handle,0xffff); //�ź�����һ
        printf("�߳�2����ź���\r\n");
        if(osMutexAcquire(myMutexHandle,osWaitForever) == osOK)
        {
            printf("�߳�2��û�����\r\n");

            HAL_UART_Transmit(&demoUart.tUARTHandle,"�߳�2ִ��\r\n",sizeof("�߳�2ִ��\r\n"),1000);
            Drv_Delay_Ms(1000);

            osMutexRelease(myMutexHandle);
        }
        osSemaphoreRelease(myBinarySem01Handle);

        osDelay(1);

    }

}

