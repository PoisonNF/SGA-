#include "usercode.h"		/* usercodeͷ�ļ� */
#include "drv_hal_conf.h"   /* SGA��ͷ�ļ����� */
#include "task_conf.h"      /* task��ͷ�ļ����� */
#include "ocd_conf.h"       /* OCD��ͷ�ļ����� */
#include "dev_conf.h"		/* Dev��ͷ�ļ����� */
#include "algo_conf.h"		/* Algo��ͷ�ļ����� */
#include "config.h"			/* I/O����ͷ�ļ����� */

/*
	F4 DACʵ�飬ʹ�õ���̽���߿����壬����PA4���3.3V������PA5���2V
*/

/* �û��߼����� */
void UserLogic_Code(void)
{
	printf("SGA_DEMO\r\n");

	//����PA4���3.3V
	Drv_DAC_SetValue(&demoDAC[0],3.3);

	//����PA5���2V
	Drv_DAC_SetValue(&demoDAC[1],2);

	while(1)
	{


	}
}
