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
    
    ���CAN���ͣ�����CAN���ݺ�ͨ������1��ʾ
*/

uint8_t SendBuffer[8] = "qwerasd";

/* �û��߼����� */
void UserLogic_Code(void)
{
	printf("SGA_DEMO\r\n");

	Drv_CAN_ModeConfig(&CAN,CAN_MODE_NORMAL);       //�л�Ϊ����ģʽ
	Drv_CAN_TxIDConfig(&CAN,0x11);                  //����Tx��ID

	while(1)
	{
        //ͨ��CAN��������
		if(Drv_CAN_SendMsg(&CAN,SendBuffer,sizeof(SendBuffer)))
		{
			printf("Send Error\r\n");
		}
		else
		{
			printf("TxID = %x  SendBuffer = %s\r\n",CAN.tCANTxHeader.StdId,SendBuffer);
		}

		Drv_Delay_Ms(1000);
    }
}
