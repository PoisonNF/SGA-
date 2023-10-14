#include "usercode.h"		/* usercodeͷ�ļ� */
#include "drv_hal_conf.h"   /* SGA��ͷ�ļ����� */
#include "task_conf.h"      /* task��ͷ�ļ����� */
#include "ocd_conf.h"       /* OCD��ͷ�ļ����� */
#include "dev_conf.h"		/* Dev��ͷ�ļ����� */
#include "algo_conf.h"		/* Algo��ͷ�ļ����� */
#include "config.h"			/* I/O����ͷ�ļ����� */

uint8_t buf[100];
uint16_t ReciveNum;

/* �û��߼����� */
void UserLogic_Code(void)
{
	printf("SGA_DEMO\r\n");
	Drv_Delay_Ms(1000);
    
	while(1)
	{
        /* ���жϽ��յ������ݷ���buf�У����Ҽ�¼ReciveNum */
		if((ReciveNum = Drv_Uart_Receive_IT(&demoUart,buf)) != 0)
		{
			printf("���յ��ĳ���Ϊ%d\r\n",ReciveNum);
			printf("���յ�������Ϊ%s\n",buf);
			memset(buf,0,100);
		}
	}
}
