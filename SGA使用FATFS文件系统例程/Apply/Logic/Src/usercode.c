#include "usercode.h"		/* usercodeͷ�ļ� */
#include "drv_hal_conf.h"   /* SGA��ͷ�ļ����� */
#include "task_conf.h"      /* task��ͷ�ļ����� */
#include "ocd_conf.h"       /* OCD��ͷ�ļ����� */
#include "dev_conf.h"		/* Dev��ͷ�ļ����� */
#include "algo_conf.h"		/* Algo��ͷ�ļ����� */
#include "config.h"			/* I/O����ͷ�ļ����� */

uint8_t File_Name[] = "/test/example.txt";
uint8_t Path_Name[] = "/test";
uint8_t sendBuffer[100] = "abcdefghijklmnopqrtsuvwxyz";
uint8_t receBuffer[100] = {0};
uint32_t sendNum = 0;
uint32_t receNum = 0;
uint32_t Offset = 0;

int8_t ret;

/* �û��߼����� */
void UserLogic_Code(void)
{
	printf("SGA_DEMO\r\n");
	Drv_Delay_Ms(1000);

    //�����ļ���
	ret = OCD_FATFS_CreateDir(&tFATFS,(char *)Path_Name);
    if(ret == FR_OK)
        printf("�����ļ��гɹ� %s\r\n",Path_Name);
    
    else if(ret == FR_EXIST)
        printf("�ļ����Ѵ��� %s\r\n",Path_Name);
    

	while(1)
	{
        //��ĩβд������
		if(OCD_FATFS_Write_End(&tFATFS, (char *)File_Name, sendBuffer, sizeof("abcdefghijklmnopqrtsuvwxyz") , &sendNum) == FR_OK)
			printf("д��%d���ֽ� ����Ϊ%s\r\n",sendNum,sendBuffer);

		Drv_Delay_Ms(500);

        //���д�����ݳ��Ȳ�Ϊ0
		if(sendNum != 0)
            //��ƫ��������ȡ��ͬ��������
			if(OCD_FATFS_Read_SpecifyIndex(&tFATFS, (char *)File_Name ,receBuffer,sendNum,Offset,&receNum) == FR_OK)
            {
                printf("��ƫ����%d ����%d���ֽ� ����Ϊ%s\r\n",Offset,receNum,receBuffer);
                //ƫ�����ۼ�
                Offset += receNum;
            }
	}
}
