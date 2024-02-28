#include "usercode.h"		/* usercodeͷ�ļ� */
#include "drv_hal_conf.h"   /* SGA��ͷ�ļ����� */
#include "task_conf.h"      /* task��ͷ�ļ����� */
#include "ocd_conf.h"       /* OCD��ͷ�ļ����� */
#include "dev_conf.h"		/* Dev��ͷ�ļ����� */
#include "algo_conf.h"		/* Algo��ͷ�ļ����� */
#include "config.h"			/* I/O����ͷ�ļ����� */

/*
	F4 CAN�ػ�ʵ�飬ʹ�õ���̽���߿����壬ʹ��CAN1�����CAN���Է������жϲ��ԣ�����CAN�յ�������ͨ������1����XCOM
*/

uint8_t num;
uint8_t SendBuffer[8] = "1234567";
uint8_t ReceBuffer[8];

/* �û��߼����� */
void UserLogic_Code(void)
{
	printf("SGA_DEMO\r\n");

	while(1)
	{
        memset(ReceBuffer,0,8);

        //CAN��������
		if(Drv_CAN_SendMsg(&CAN,SendBuffer,8))
		{
			printf("Send Error\r\n");
		}

		Drv_Delay_Ms(1000);

        //CAN��������
		// num = Drv_CAN_ReceMsg(&CAN,ReceBuffer);
		// if(num != 0)
		// {
		// 	printf("num = %d  ReceBuffer = %s\r\n",num,ReceBuffer);
		// 	printf("TxID = %x\r\n",CAN.tCANRxHeader.StdId);
		// }

	}
}
