#include "usercode.h"		/* usercodeͷ�ļ� */
#include "threadpool.h"		/* threadpoolͷ�ļ� */
#include "drv_hal_conf.h"   /* SGA��ͷ�ļ����� */
#include "task_conf.h"      /* task��ͷ�ļ����� */
#include "ocd_conf.h"       /* OCD��ͷ�ļ����� */
#include "dev_conf.h"		/* Dev��ͷ�ļ����� */
#include "algo_conf.h"		/* Algo��ͷ�ļ����� */
#include "config.h"			/* I/O����ͷ�ļ����� */


/* �߳���ں�����ʹ��������Դ��ļ��� */
void Thread1(void* paramenter)
{
    while(1)
    {
        printf("Thread1\r\n");
        Drv_Delay_Ms(1000);
    }
}

void Thread2(void* paramenter)
{
    while(1)
    {
        printf("Thread2\r\n");
        Drv_Delay_Ms(1000);
    }
}



