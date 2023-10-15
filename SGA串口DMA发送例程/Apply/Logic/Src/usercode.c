#include "usercode.h"		/* usercodeͷ�ļ� */
#include "drv_hal_conf.h"   /* SGA��ͷ�ļ����� */
#include "task_conf.h"      /* task��ͷ�ļ����� */
#include "ocd_conf.h"       /* OCD��ͷ�ļ����� */
#include "dev_conf.h"		/* Dev��ͷ�ļ����� */
#include "algo_conf.h"		/* Algo��ͷ�ļ����� */
#include "config.h"			/* I/O����ͷ�ļ����� */

/**
 * ������ʵ�ִӴ���1DMA�������ݣ����Ӵ���1ʹ��DMA���͵ķ�ʽ�������ݡ�
 * 
 */

/* �û��߼����� */
void UserLogic_Code(void)
{
	uint8_t num;					//��¼�洢�ֽ���
	uint8_t ReceBuffer[100];		//��������buffer
	uint8_t SendBuffer[200];		//��������buffer

	printf("SGA_DEMO\r\n");

	while(1)
	{
		//�Ӵ���1DMA�������ݣ���ŵ�buffer��
		num = Drv_Uart_Receive_DMA(&demoUart,ReceBuffer);

        //���յ������ݸ�����Ϊ0
		if(num != 0)
		{
			printf("num = %d\r\n",num);
			memcpy(SendBuffer,ReceBuffer,num);						//�ڴ濽��
            Drv_Uart_Transmit_DMA(&demoUart,SendBuffer,num);		//DMA����
        
			num = 0;
		}
	}
}
