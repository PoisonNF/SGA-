#include "usercode.h"		/* usercodeͷ�ļ� */
#include "drv_hal_conf.h"   /* SGA��ͷ�ļ����� */
#include "task_conf.h"      /* task��ͷ�ļ����� */
#include "ocd_conf.h"       /* OCD��ͷ�ļ����� */
#include "dev_conf.h"		/* Dev��ͷ�ļ����� */
#include "algo_conf.h"		/* Algo��ͷ�ļ����� */
#include "config.h"			/* I/O����ͷ�ļ����� */

/*
	F4 LEDʵ�飬ʹ�õ���̽���߿����壬500ms��תһ�Σ�ʹ�õ���PF9,PF10����LED
*/

/* �û��߼����� */
void UserLogic_Code(void)
{

	while(1)
	{
		Drv_GPIO_Reset(&demoGPIO[0]);
        Drv_GPIO_Reset(&demoGPIO[1]);

		Drv_Delay_Ms(500);
        
        Drv_GPIO_Set(&demoGPIO[0]);
        Drv_GPIO_Set(&demoGPIO[1]);
        
        Drv_Delay_Ms(500);

	}
}
