#include "usercode.h"		/* usercodeͷ�ļ� */
#include "drv_hal_conf.h"   /* SGA��ͷ�ļ����� */
#include "task_conf.h"      /* task��ͷ�ļ����� */
#include "ocd_conf.h"       /* OCD��ͷ�ļ����� */
#include "dev_conf.h"		/* Dev��ͷ�ļ����� */
#include "algo_conf.h"		/* Algo��ͷ�ļ����� */
#include "config.h"			/* I/O����ͷ�ļ����� */

/*
F4 CAN˫FIFO����ʵ�飬ʹ�õ���̽���߿����壬ʹ��CAN1��ͨ���ⲿ�豸����CAN��Ϣ������ӡ�
            ID��Ϊ0x41��0x42��0x43��fifo0����
            ID��Ϊ0x44��0x45��fifo1����
*/

/* �û��߼����� */
void UserLogic_Code(void)
{
	printf("SGA_DEMO\r\n");

	while(1)
	{
	}
}
