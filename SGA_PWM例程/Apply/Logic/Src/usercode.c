#include "usercode.h"		/* usercodeͷ�ļ� */
#include "drv_hal_conf.h"   /* SGA��ͷ�ļ����� */
#include "task_conf.h"      /* task��ͷ�ļ����� */
#include "ocd_conf.h"       /* OCD��ͷ�ļ����� */
#include "dev_conf.h"		/* Dev��ͷ�ļ����� */
#include "algo_conf.h"		/* Algo��ͷ�ļ����� */
#include "config.h"			/* I/O����ͷ�ļ����� */

/* �û��߼����� */
void UserLogic_Code(void)
{
	printf("SGA_DEMO\r\n");

	//PA6��ʼΪ0% PA7Ϊ100%
	Drv_PWM_DutyFactorSet(&tPWMDemo[0],0);
    Drv_PWM_DutyFactorSet(&tPWMDemo[1],100);

	Drv_Delay_Ms(2000);

	//2s��PA6��Ϊ7.5% PA7��Ϊ7.5%
	Drv_PWM_HighLvTimeSet(&tPWMDemo[0],1500);	//�ߵ�ƽʱ��Ϊ1.5ms������ɰٷֱȾ���7.5
	Drv_PWM_DutyFactorSet(&tPWMDemo[1],7.5);

	while(1)
	{

	}
}
