#include "usercode.h"		/* usercodeͷ�ļ� */
#include "drv_hal_conf.h"   /* SGA��ͷ�ļ����� */
#include "task_conf.h"      /* task��ͷ�ļ����� */
#include "ocd_conf.h"       /* OCD��ͷ�ļ����� */
#include "dev_conf.h"		/* Dev��ͷ�ļ����� */
#include "algo_conf.h"		/* Algo��ͷ�ļ����� */
#include "config.h"			/* I/O����ͷ�ļ����� */


/* �û��߼����� */
void UserLogic_Code(void)
{
    uint8_t num;        //���ڼ�¼���յ��������ֽ���
	uint8_t buf[150];   //���ڴ�Ž��յ�������
    
	while(1)
	{
        //���ý��պ��������յ������ݴ���buf�У�ͬʱ����num
        num = Drv_Uart_Receive_DMA(&demoUart,buf);
        
        //�����յ��������ֽ�����Ϊ0����ӡ������PC
        if(num != 0)
            printf("%s",buf);
	}
}