#include "usercode.h"		/* usercodeͷ�ļ� */
#include "drv_hal_conf.h"   /* SGA��ͷ�ļ����� */
#include "task_conf.h"      /* task��ͷ�ļ����� */
#include "ocd_conf.h"       /* OCD��ͷ�ļ����� */
#include "dev_conf.h"		/* Dev��ͷ�ļ����� */
#include "algo_conf.h"		/* Algo��ͷ�ļ����� */
#include "config.h"			/* I/O����ͷ�ļ����� */

/*
	F4 PWM������ʵ�飬ʹ�õ���̽���߿����壬ʹ��PF9��LED��ʵ�ֺ�����Ч��
*/

/* �û��߼����� */
void UserLogic_Code(void)
{
	printf("SGA_DEMO\r\n");

	//PF9��ʼΪ100%
	Drv_PWM_DutyFactorSet(&tPWMDemo[0],100);

	while(1)
	{
		for(uint8_t i = 0; i<100;i++)
		{
			Drv_PWM_DutyFactorSet(&tPWMDemo[0],100 - i);
			Drv_Delay_Ms(10);
		}

		for(uint8_t i = 0; i<100;i++)
		{
			Drv_PWM_DutyFactorSet(&tPWMDemo[0],i);
			Drv_Delay_Ms(10);
		}

	}
}
