#include "usercode.h"		/* usercodeͷ�ļ� */
#include "drv_hal_conf.h"   /* SGA��ͷ�ļ����� */
#include "task_conf.h"      /* task��ͷ�ļ����� */
#include "ocd_conf.h"       /* OCD��ͷ�ļ����� */
#include "config.h"			/* I/O����ͷ�ļ����� */

/* �û��߼����� */
void UserLogic_Code(void)
{
	printf("work!\r\n");
	int num = 0;

	while(1)
	{
 		num = rand()%100+1;
		printf("@VSD220216,T122308,E117.85623,N78.65935,LX+123.34,LY0078.93,LZ0005.34,AX+%d,AY-35,AZ256,VX+2.125,VY-0.125,VZ+1.356,OX+20.1,OY+18.1,OZ-05.9,D085.23,A13.57,ABCD,CLAP,OPEN,E22.03,P277.89,LL\r\n",num);
		//printf("AX�����Ϊ%d",num);
		Drv_Delay_Ms(5000);
	}
}
