#include "usercode.h"		/* usercodeͷ�ļ� */
#include "drv_hal_conf.h"   /* SGA��ͷ�ļ����� */
#include "task_conf.h"      /* task��ͷ�ļ����� */
#include "ocd_conf.h"       /* OCD��ͷ�ļ����� */
#include "dev_conf.h"		/* Dev��ͷ�ļ����� */
#include "algo_conf.h"		/* Algo��ͷ�ļ����� */
#include "config.h"			/* I/O����ͷ�ļ����� */


/* �߳���ں��� */

void Task1(void *argument)
{
    while(1)
    {
#ifdef FREERTOS_ENABLE
        osSemaphoreWait(myBinarySem01Handle,0xffff); //�ź�����һ
            printf("�߳�1����ź���\r\n");
#endif

#ifdef RTT_ENABLE
        if(rt_sem_take(sem,RT_WAITING_FOREVER) == RT_EOK)
        {
            printf("�߳�1����ź���\r\n");
            if(rt_mutex_take(mut,RT_WAITING_FOREVER) == RT_EOK)
            {
                printf("�߳�1��û�����\r\n");
#endif

            HAL_UART_Transmit(&demoUart.tUARTHandle,"�߳�1ִ��\r\n",sizeof("�߳�1ִ��\r\n"),1000);
            Drv_Delay_Ms(1000);

#ifdef RTT_ENABLE
                rt_mutex_release(mut);
            }
            rt_sem_release(sem);
        }
#endif

#ifdef FREERTOS_ENABLE
        osSemaphoreRelease(myBinarySem01Handle);

        osThreadYield();
#endif
    }

}

void Task2(void *argument)
{
    while(1)
    {
#ifdef FREERTOS_ENABLE
        osSemaphoreWait(myBinarySem01Handle,0xffff); //�ź�����һ
            printf("�߳�2����ź���\r\n");
        if(osMutexAcquire(myMutexHandle,osWaitForever) == osOK)
        {
            printf("�߳�2��û�����\r\n");
#endif

#ifdef RTT_ENABLE
        if(rt_sem_take(sem,RT_WAITING_FOREVER) == RT_EOK)
        {
            printf("�߳�2����ź���\r\n");
            if(rt_mutex_take(mut,RT_WAITING_FOREVER) == RT_EOK)
            {
                printf("�߳�2��û�����\r\n");
#endif

                HAL_UART_Transmit(&demoUart.tUARTHandle,"�߳�2ִ��\r\n",sizeof("�߳�2ִ��\r\n"),1000);
                Drv_Delay_Ms(1000);

#ifdef RTT_ENABLE
                rt_mutex_release(mut);
            }
            rt_sem_release(sem);
        }
#endif

#ifdef FREERTOS_ENABLE
            osMutexRelease(myMutexHandle);
        }
        osSemaphoreRelease(myBinarySem01Handle);

        osDelay(1);
#endif

    }

}
