#include "usercode.h"		/* usercodeͷ�ļ� */
#include "drv_hal_conf.h"   /* SGA��ͷ�ļ����� */
#include "task_conf.h"      /* task��ͷ�ļ����� */
#include "ocd_conf.h"       /* OCD��ͷ�ļ����� */
#include "dev_conf.h"		/* Dev��ͷ�ļ����� */
#include "algo_conf.h"		/* Algo��ͷ�ļ����� */
#include "config.h"			/* I/O����ͷ�ļ����� */

/* �߳̾�� */
rt_thread_t thread1 = RT_NULL;
rt_thread_t thread2 = RT_NULL;

/* �û��߼����� */
void UserLogic_Code(void)
{

    /* �����߳� */
	thread1 = rt_thread_create("Thread1",Thread1,NULL,1024,1,20);


	thread2 = rt_thread_create("Thread2",Thread2,NULL,512,4,20);
    
    rt_thread_startup(thread1);		//�߳�1 
	rt_thread_startup(thread2);		//�߳�2 
}
