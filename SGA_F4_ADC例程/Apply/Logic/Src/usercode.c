#include "usercode.h"		/* usercodeͷ�ļ� */
#include "drv_hal_conf.h"   /* SGA��ͷ�ļ����� */
#include "task_conf.h"      /* task��ͷ�ļ����� */
#include "ocd_conf.h"       /* OCD��ͷ�ļ����� */
#include "dev_conf.h"		/* Dev��ͷ�ļ����� */
#include "algo_conf.h"		/* Algo��ͷ�ļ����� */
#include "config.h"			/* I/O����ͷ�ļ����� */

/*
	F4 ADCʵ�飬ʹ�õ���̽���߿����壬ʹ�ô���1����ӡ��ǰADC��������
	��ʹ��DAC�����·��һ·��PA4Ϊ3.3v����һ·��PA5Ϊ2v
	ʹ��ADC1��Channel6��PA6ȥAD��⣬ʹ�öŰ�������PA4����PA5
*/

float Vnum;

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
		Vnum = Drv_ADC_PollGetValue(&demoADC[0]);
		printf("ADC:%f\r\n",Vnum);
		Drv_Delay_Ms(1000);
	}
}
