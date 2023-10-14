#include "usercode.h"		    /* usercodeͷ�ļ� */
#include "drv_hal_conf.h"   	/* SGA��ͷ�ļ����� */
#include "task_conf.h"      	/* task��ͷ�ļ����� */
#include "ocd_conf.h"       	/* OCD��ͷ�ļ����� */
#include "dev_conf.h"		    /* Dev��ͷ�ļ����� */
#include "algo_conf.h"		  	/* Algo��ͷ�ļ����� */
#include "config.h"			    /* I/O����ͷ�ļ����� */

#ifdef FREERTOS_ENABLE
//�߳�����
osThreadId_t task1Handle;
const osThreadAttr_t task1_atrributes = {
  .name = "task1",
  .stack_size = 128*4,
  .priority = (osPriority_t) osPriorityNormal,
};

osThreadId_t task2Handle;
const osThreadAttr_t task2_atrributes = {
  .name = "task2",
  .stack_size = 128*4,
  .priority = (osPriority_t) osPriorityNormal1,
};

//�ź�������
osSemaphoreId myBinarySem01Handle;
osSemaphoreDef(myBinarySem01);

//����������
osMutexId myMutexHandle;
osMutexDef(myMutex);

#endif

#ifdef RTT_ENABLE
rt_thread_t thread1;
rt_thread_t thread2;

//�ź���
rt_sem_t sem = RT_NULL;
//������
rt_mutex_t mut = RT_NULL;

#endif

/* �û��߼����� */
void UserLogic_Code(void)
{

#ifdef FREERTOS_ENABLE

    //�����ź�������ʼֵΪ1
    myBinarySem01Handle = osSemaphoreCreate(osSemaphore(myBinarySem01), 1);
    //����������
    myMutexHandle = osMutexCreate(osMutex(myMutex));

	task1Handle = osThreadNew(Task1,NULL,&task1_atrributes);
    task2Handle = osThreadNew(Task2,NULL,&task2_atrributes);
    printf("FreeRTOS ���ȿ�ʼ��\r\n");
    
    Drv_Delay_Ms(3000);
    printf("��ʱ3s\r\n");
    
	osKernelStart();

#endif

#ifdef RTT_ENABLE

    //�����ź�������ʼֵΪ1
    sem = rt_sem_create("sem",1,RT_IPC_FLAG_FIFO);

    //����������
    mut = rt_mutex_create("mut",RT_IPC_FLAG_FIFO);

    thread1 = rt_thread_create("task1",Task1,NULL,512,4,20); 
    rt_thread_startup(thread1);
    thread2 = rt_thread_create("task2",Task2,NULL,512,4,20);
    rt_thread_startup(thread2);
  
    printf("RT-Thread ���ȿ�ʼ��\r\n");
    
#endif

#if !defined(RTT_ENABLE) && !defined(FREERTOS_ENABLE)
    while(1)
    {
        printf("SGA Demo!\r\n");
        Drv_Delay_Ms(1000);
    }
#endif

}
