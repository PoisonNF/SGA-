#include "usercode.h"		/* usercode头文件 */
#include "threadpool.h"		/* threadpool头文件 */
#include "drv_hal_conf.h"   /* SGA库头文件配置 */
#include "task_conf.h"      /* task层头文件配置 */
#include "ocd_conf.h"       /* OCD层头文件配置 */
#include "dev_conf.h"		/* Dev层头文件配置 */
#include "algo_conf.h"		/* Algo层头文件配置 */
#include "config.h"			/* I/O配置头文件配置 */


/* 线程入口函数（使用裸机忽略此文件） */
void Thread1(void* paramenter)
{
    while(1)
    {
        printf("Thread1\r\n");
        Drv_Delay_Ms(1000);
    }
}

void Thread2(void* paramenter)
{
    while(1)
    {
        printf("Thread2\r\n");
        Drv_Delay_Ms(1000);
    }
}



