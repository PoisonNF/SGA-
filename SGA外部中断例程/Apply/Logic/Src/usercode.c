#include "usercode.h"		/* usercodeͷ�ļ� */
#include "drv_hal_conf.h"   /* SGA��ͷ�ļ����� */
#include "task_conf.h"      /* task��ͷ�ļ����� */
#include "ocd_conf.h"       /* OCD��ͷ�ļ����� */
#include "config.h"			/* I/O����ͷ�ļ����� */

/* ����ԭ�Ӿ�Ӣ�� PE4 KEY0 �ⲿ�ж�����*/
/* ����KEY0 ʱ �����ڻᷢ��"�жϣ�\r\n" ��"�ص���\r\n" */

/* �û��߼����� */
void UserLogic_Code(void)
{ 
	while(1)
	{
		printf("SGA_DEMO\r\n");
		Drv_Delay_Ms(1000);
	}
}
