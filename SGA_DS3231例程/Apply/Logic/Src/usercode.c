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
    
    tagDS3231Time_T time;
    tagDS3231TimeASCII_T Atime;
   
	while(1)
	{
        //��ʮ�����ƻ�ȡʱ��
        if(OCD_DS3231_TimeGetHex(&tDS3231,&time))
        {
            printf("From Hex time\r\n");
            printf("20%02x��%02x��%02x�� %02xʱ%02x��%02x�� ��%02x\r\n",
                    time.ucYear,time.ucMonth,time.ucDate,
                    time.ucHour,time.ucMinute,time.ucSecond,
                    time.ucWeek);
        }
        //��ASCII��ȡʱ��
        if(OCD_DS3231_TimeGetASCII(&tDS3231,&Atime))
        {
            printf("From ASCII time\r\n");
            printf("20%c%c��%c%c��%c%c�� %c%cʱ%c%c��%c%c�� ��%c%c\r\n",
                     Atime.ucYear[0],Atime.ucYear[1],Atime.ucMonth[0],Atime.ucMonth[1],Atime.ucDate[0],Atime.ucDate[1],
                     Atime.ucHour[0],Atime.ucHour[1],Atime.ucMinute[0],Atime.ucMinute[1],Atime.ucSecond[0],Atime.ucSecond[1],
                     Atime.ucWeek[0],Atime.ucWeek[1]);
        }
        Drv_Delay_Ms(1000);
        printf("\r\n");
	}
}
