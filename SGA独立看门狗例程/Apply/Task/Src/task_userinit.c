#include "task_conf.h"
#include "ocd_conf.h"
#include "config.h"

void Task_UserInit(void)
{    
    Drv_Uart_ITInit(&demoUart);

    Drv_IWDG_Init(&demoIWDG);
    printf("�������ʱ��Ϊ%dms\r\n",demoIWDG.usResetTime);

}
