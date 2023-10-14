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
	printf("SGA_DEMO\r\n");

	//����ֵΪ150 ��ʼֵΪ50
	float ExpectValue = 50.0f;
	float CurrentValue = 50.0f;

	// �洢���ֵ�������ȶ������ȶ�
	float Buffer[3] = {0};

	//PIDϵ��ֵ
	float PIDparameter[3] = {0.8, 0.25, 0.01};

	//����PIDϵ����Ĭ����ṹ������ͬ
	Algo_PID_Update(&PID,PIDparameter);

	do
	{
		//����PID���㣬����ֵ������ǰֵ
		CurrentValue = Algo_PID_Calculate(&PID,CurrentValue,ExpectValue);
		printf("%d\r\n",(int)CurrentValue);

		//���ݼĴ�
		Buffer[2] = Buffer[1];
		Buffer[1] = Buffer[0];
		Buffer[0] = CurrentValue;

		//��ʱ����۲�
		Drv_Delay_Ms(50);

	} while (!((Buffer[0] == Buffer[1]) 
			&& (Buffer[0] == Buffer[2])
			&& (Buffer[1] == Buffer[2])));	//�����ȶ���������
    
    printf("�ﵽ�ȶ�״̬\r\n");
	return;
}
