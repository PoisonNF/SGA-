#include "usercode.h"		/* usercodeͷ�ļ� */
#include "drv_hal_conf.h"   /* SGA��ͷ�ļ����� */
#include "task_conf.h"      /* task��ͷ�ļ����� */
#include "ocd_conf.h"       /* OCD��ͷ�ļ����� */
#include "dev_conf.h"		/* Dev��ͷ�ļ����� */
#include "algo_conf.h"		/* Algo��ͷ�ļ����� */
#include "config.h"			/* I/O����ͷ�ļ����� */

/* 
    ���������CAN�������ݣ����Ҫ��ʾ���ݣ���Ҫʹ��CAN�����ǻ�����һ�������¼SGA_CAN��������
    ʹ�õ���PA11 PA12��ע��ʹ������ԭ�ӿ�������Ҫʹ������ñ������IO�����ӵ�CANоƬ��
    
    ���CAN���գ�����CAN���ݺ�ͨ������1��ʾ
*/

uint8_t ReceBuffer[8];
uint8_t num;

/* �û��߼����� */
void UserLogic_Code(void)
{
	printf("SGA_DEMO\r\n");

	Drv_CAN_ModeConfig(&CAN,CAN_MODE_NORMAL);       //�л�Ϊ����ģʽ

	while(1)
	{
        memset(ReceBuffer,0,8);
		num = Drv_CAN_ReceMsg(&CAN,ReceBuffer);
		if(num != 0)
		{
			printf("num = %d  ReceBuffer = %s\r\n",num,ReceBuffer);
			printf("ID = %x\r\n",CAN.tCANRxHeader.StdId);
		}

		Drv_Delay_Ms(1000);
    }
}
