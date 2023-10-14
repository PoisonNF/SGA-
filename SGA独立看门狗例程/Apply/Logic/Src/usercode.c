#include "usercode.h"		/* usercodeͷ�ļ� */
#include "drv_hal_conf.h"   /* SGA��ͷ�ļ����� */
#include "task_conf.h"      /* task��ͷ�ļ����� */
#include "ocd_conf.h"       /* OCD��ͷ�ļ����� */
#include "dev_conf.h"		/* Dev��ͷ�ļ����� */
#include "algo_conf.h"		/* Algo��ͷ�ļ����� */
#include "config.h"			/* I/O����ͷ�ļ����� */

/*	������ʹ���˶������Ź���
	ͨ���ı�demoIWDG.usResetTime��ȡֵ�������ʱ�䡣������Ĭ��10s��
	���ڹ涨��ι���ι�����������ι���������ʱ��ﵽʱ��������ϵͳ��
*/

//�����Ѿ���ȥ������
uint8_t time = 0;

/* �û��߼����� */
void UserLogic_Code(void)
{
	printf("SGA_DEMO\r\n");

	Drv_IWDG_Feed(&demoIWDG);
	printf("��һ��ι��\r\n");
    
    Drv_Delay_Ms(1000);

	Drv_IWDG_Feed(&demoIWDG);
	printf("�ڶ���ι��\r\n");

	while(1)
	{
		printf("�Ѿ�%dsûι����,%ds��ϵͳ��������\r\n",time,demoIWDG.usResetTime/1000 - time);
        
		//����һ��������ʱ��㣬��ӡϵͳ��������
        if ((time + 1) == demoIWDG.usResetTime/1000)
			printf("ϵͳ����������\r\n\r\n");

		//��ʱ1s,������һ
		Drv_Delay_Ms(1000);
		time += 1;	
	}
}
