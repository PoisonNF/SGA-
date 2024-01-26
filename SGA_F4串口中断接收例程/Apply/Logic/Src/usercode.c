#include "usercode.h"		/* usercodeͷ�ļ� */
#include "drv_hal_conf.h"   /* SGA��ͷ�ļ����� */
#include "task_conf.h"      /* task��ͷ�ļ����� */
#include "ocd_conf.h"       /* OCD��ͷ�ļ����� */
#include "dev_conf.h"		/* Dev��ͷ�ļ����� */
#include "algo_conf.h"		/* Algo��ͷ�ļ����� */
#include "config.h"			/* I/O����ͷ�ļ����� */

/*
	F4 �����жϽ���ʵ�飬ʹ�õ���̽���߿����壬ʹ�ô���1�����XCOM����ʲô��STM32����ʲô��������100�ֽ�
*/

uint8_t num;
uint8_t buffer[20];

/* �û��߼����� */
void UserLogic_Code(void)
{
	printf("SGA_DEMO\r\n");
	while(1)
	{
		memset(buffer,0,20);

		num = Drv_Uart_Receive_IT(&demoUart,buffer);
		if(num)
		{
			printf("%s",buffer);
			num = 0;
		}
	}
}
