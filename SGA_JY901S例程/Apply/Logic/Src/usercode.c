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
	while(1)
	{
        //������ݻ�ò��Ҵ������
		if(OCD_JY901_DataProcess(&JY901S))
        {
            OCD_JY901_DataConversion(&JY901S);	//����ת��
            OCD_JY901_Printf(&JY901S); 			//���ݴ�ӡ
            printf("\r\n");
        }
	}
}
