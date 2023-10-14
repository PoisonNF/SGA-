#include "usercode.h"		/* usercodeͷ�ļ� */
#include "drv_hal_conf.h"   /* SGA��ͷ�ļ����� */
#include "task_conf.h"      /* task��ͷ�ļ����� */
#include "ocd_conf.h"       /* OCD��ͷ�ļ����� */
#include "dev_conf.h"		/* Dev��ͷ�ļ����� */
#include "algo_conf.h"		/* Algo��ͷ�ļ����� */
#include "config.h"			/* I/O����ͷ�ļ����� */

uint8_t Timeflag_100MS;
uint8_t Timeflag_1000MS;
uint8_t Timeflag_Count;

/* �û��߼����� */
void UserLogic_Code(void)
{
	printf("SGA_DEMO\r\n");

	while(1)
	{
		//����1һֱ��ӡ
		printf("SGA_DEMO\r\n");

		if(Timeflag_100MS)
		{
			//��ɫLED��ת
			Drv_GPIO_Toggle(&demoGPIO[0]);
			//��־λ����
			Timeflag_100MS = 0;
		}

		if(Timeflag_1000MS)
		{
			//��ɫLED��ת
			Drv_GPIO_Toggle(&demoGPIO[2]);
			//��־λ����
			Timeflag_1000MS = 0;
		}
	}
}
