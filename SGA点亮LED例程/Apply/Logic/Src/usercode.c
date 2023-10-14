#include "usercode.h"		/* usercodeͷ�ļ� */
#include "drv_hal_conf.h"   /* SGA��ͷ�ļ����� */
#include "task_conf.h"      /* task��ͷ�ļ����� */
#include "ocd_conf.h"       /* OCD��ͷ�ļ����� */
#include "dev_conf.h"		/* Dev��ͷ�ļ����� */
#include "algo_conf.h"		/* Algo��ͷ�ļ����� */
#include "config.h"			/* I/O����ͷ�ļ����� */

/* 	demoGPIO[0] PD13 R
	demoGPIO[1] PD14 G
	demoGPIO[2] PD15 B
*/

/* �û��߼����� */
void UserLogic_Code(void)
{
    printf("SGA_DEMO\r\n");

	//LED��ʼϨ��
	Drv_GPIO_Set(&demoGPIO[0]);
	Drv_GPIO_Set(&demoGPIO[1]);
	Drv_GPIO_Set(&demoGPIO[2]);

	while(1)
	{
		//���
		Drv_GPIO_Reset(&demoGPIO[0]);
		Drv_GPIO_Set(&demoGPIO[1]);
		Drv_GPIO_Set(&demoGPIO[2]);

		Drv_Delay_Ms(1000);

		//�̵�
		Drv_GPIO_Set(&demoGPIO[0]);
		Drv_GPIO_Reset(&demoGPIO[1]);
		Drv_GPIO_Set(&demoGPIO[2]);

		Drv_Delay_Ms(1000);

		//����
		Drv_GPIO_Set(&demoGPIO[0]);
		Drv_GPIO_Set(&demoGPIO[1]);
		Drv_GPIO_Reset(&demoGPIO[2]);

		Drv_Delay_Ms(1000);
	}
}
