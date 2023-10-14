#include "usercode.h"		/* usercodeͷ�ļ� */
#include "drv_hal_conf.h"   /* SGA��ͷ�ļ����� */
#include "task_conf.h"      /* task��ͷ�ļ����� */
#include "ocd_conf.h"       /* OCD��ͷ�ļ����� */
#include "dev_conf.h"		/* Dev��ͷ�ļ����� */
#include "algo_conf.h"		/* Algo��ͷ�ļ����� */
#include "config.h"			/* I/O����ͷ�ļ����� */

/* ������ʹ������·ADC����·DAC����Ҫʹ�öŰ��������������
    DACͨ��1 PA4 �� ADC1 ͨ��0 PA0
    DACͨ��2 PA5 �� ADC1 ͨ��1 PA1

    DAC�������ֲ�ͬ�������ʽ�������
 */

//��ŵ�ǰ��ѹֵ
float Value1 = 0.0f;
float Value2 = 0.0f;

/* �û��߼����� */
void UserLogic_Code(void)
{
	printf("SGA_DEMO\r\n");

    //ͨ��1��2��ѹ����
    Drv_DAC_SetValue(&demoDAC[0],3);
    Drv_DAC_SetData(&demoDAC[1],2047);

	while(1)
	{
        //ʹ��ADC��ȡ��ѹֵ����ӡ
		Value1 = Drv_ADC_PollGetValue(&demoADC[0]);
		printf("Channel1 :%fV\r\n",Value1);
        Value2 = Drv_ADC_PollGetValue(&demoADC[1]);
        printf("Channel2 :%fV\r\n",Value2);
        printf("\r\n");
              
        Drv_Delay_Ms(500);

	}
}
