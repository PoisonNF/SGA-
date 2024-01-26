#include "usercode.h"		/* usercodeͷ�ļ� */
#include "drv_hal_conf.h"   /* SGA��ͷ�ļ����� */
#include "task_conf.h"      /* task��ͷ�ļ����� */
#include "ocd_conf.h"       /* OCD��ͷ�ļ����� */
#include "dev_conf.h"		/* Dev��ͷ�ļ����� */
#include "algo_conf.h"		/* Algo��ͷ�ļ����� */
#include "config.h"			/* I/O����ͷ�ļ����� */

/*
	F4 ����DMA����ʵ�飬ʹ�õ���̽���߿����壬ʹ�ô���1�����XCOM����ʲô��STM32����ʲô��������100�ֽ�
*/

uint8_t num;
uint8_t ReceBuffer[50];
uint8_t SendBuffer[50];

/* �û��߼����� */
void UserLogic_Code(void)
{
	printf("SGA_DEMO\r\n");
	while(1)
	{
		memset(ReceBuffer,0,50);

		num = Drv_Uart_Receive_DMA(&demoUart,ReceBuffer);
		if(num)
		{
			
			memcpy(SendBuffer,ReceBuffer,num);						//�ڴ濽��
			Drv_Uart_Transmit_DMA(&demoUart,SendBuffer,num);
			num = 0;
		}
	}
}
