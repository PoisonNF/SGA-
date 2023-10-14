#include "usercode.h"		/* usercodeͷ�ļ� */
#include "drv_hal_conf.h"   /* SGA��ͷ�ļ����� */
#include "task_conf.h"      /* task��ͷ�ļ����� */
#include "ocd_conf.h"       /* OCD��ͷ�ļ����� */
#include "dev_conf.h"		/* Dev��ͷ�ļ����� */
#include "algo_conf.h"		/* Algo��ͷ�ļ����� */
#include "config.h"			/* I/O����ͷ�ļ����� */

/*  ÿ��100ms��ȡһ��ms5837�����ݣ�����ʾ��OLED��
	û��OLED����ͨ������1�ӵ�������ʾ����
*/

/* �û��߼����� */
void UserLogic_Code(void)
{
	printf("SGA_DEMO\r\n");
	OCD_OLED_Clear(&tOLED);

	while(1)
	{
		//��ȡMS5837�¶Ⱥ�ѹ������
		OCD_MS5837_GetData(&MS5837);

		//��ӡ�������
		printf("Temp1:%.2fC Press1:%.2fmBar\r\n",MS5837.fTemp1,MS5837.fPress1);
		printf("Temp:%.2fC Press:%.2fmBar\r\n",MS5837.fTemp2,MS5837.fPress2);
		printf("%.2fcm\r\n",MS5837.fDepth);

		//������OLED����������ʾ
		OCD_OLED_ShowString(&tOLED,0,0,"temp:",8);
		OCD_OLED_ShowFNum(&tOLED,10,1,MS5837.fTemp2,8);
		OCD_OLED_ShowString(&tOLED,50,1,"C",8);

		OCD_OLED_ShowString(&tOLED,0,2,"press:",8);
		OCD_OLED_ShowFNum(&tOLED,10,3,MS5837.fPress2,8);
		OCD_OLED_ShowString(&tOLED,60,3,"mBar",8);

		OCD_OLED_ShowString(&tOLED,0,4,"depth:",8);
		OCD_OLED_ShowFNum(&tOLED,10,5,MS5837.fDepth,8);
		OCD_OLED_ShowString(&tOLED,50,5,"cm",8);

		Drv_Delay_Ms(100);
	}
}
