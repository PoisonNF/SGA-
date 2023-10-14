#include "usercode.h"		/* usercodeͷ�ļ� */
#include "drv_hal_conf.h"   /* SGA��ͷ�ļ����� */
#include "task_conf.h"      /* task��ͷ�ļ����� */
#include "ocd_conf.h"       /* OCD��ͷ�ļ����� */
#include "dev_conf.h"		/* Dev��ͷ�ļ����� */
#include "algo_conf.h"		/* Algo��ͷ�ļ����� */
#include "config.h"			/* I/O����ͷ�ļ����� */

//��תLED������numֵΪ��ת����
void LED_Toggle(tagGPIO_T *tGPIO,uint8_t num)
{
	for(int i = 0;i < num;i++)
	{
		Drv_GPIO_Reset(tGPIO);
		Drv_Delay_Ms(500);
		Drv_GPIO_Set(tGPIO);
		Drv_Delay_Ms(500);
	}
}

/* �û��߼����� */
void UserLogic_Code(void)
{

	while(1)
	{
		printf("SGA_DEMO\r\n");

		//�̵Ʒ�ת5��
		LED_Toggle(&demoGPIO[2],5);

		printf("���ڽ���˯��ģʽ\r\n");
        
		Drv_PWR_EnterSleepMode();	//����˯��ģʽ
        
		printf("��˯��ģʽ����\r\n");

		//��Ʒ�ת1��
		LED_Toggle(&demoGPIO[3],1);

		printf("���ڽ���ֹͣģʽ\r\n");
        
        Drv_Delay_Ms(10);	//��ֹδ��ӡ��ɾ�ֹͣ��
		Drv_PWR_EnterStopMode();	//����ֹͣģʽ
        
		printf("��ֹͣģʽ����\r\n");

		//��Ʒ�ת1��
		LED_Toggle(&demoGPIO[3],1);

		printf("���ڽ������ģʽ\r\n");

		Drv_PWR_EnterStandByMode();	//�������ģʽ
        
		//���´��뽫��������
		printf("�ò��ֲ�������\r\n");
		LED_Toggle(&demoGPIO[3],1);
	}
}

