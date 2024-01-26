#include "usercode.h"		/* usercodeͷ�ļ� */
#include "drv_hal_conf.h"   /* SGA��ͷ�ļ����� */
#include "task_conf.h"      /* task��ͷ�ļ����� */
#include "ocd_conf.h"       /* OCD��ͷ�ļ����� */
#include "dev_conf.h"		/* Dev��ͷ�ļ����� */
#include "algo_conf.h"		/* Algo��ͷ�ļ����� */
#include "config.h"			/* I/O����ͷ�ļ����� */

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

/* �û��߼����� */
void UserLogic_Code(void)
{
    //�����ź�������ʼֵΪ1
    myBinarySem01Handle = osSemaphoreCreate(osSemaphore(myBinarySem01), 1);
    //����������
    myMutexHandle = osMutexCreate(osMutex(myMutex));

	task1Handle = osThreadNew(Task1,NULL,&task1_atrributes);
    task2Handle = osThreadNew(Task2,NULL,&task2_atrributes);
    printf("FreeRTOS ���ȿ�ʼ��\r\n");
    
	osKernelStart();
}

