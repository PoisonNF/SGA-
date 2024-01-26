#include "task_conf.h"
#include "ocd_conf.h"
#include "config.h"

/* �����ʼ������ */
void Task_UserInit(void)
{
	Drv_GPIO_Init(demoGPIO, 2);

    Drv_Uart_DMAInit(&demoUart);

    Drv_Timer_Init(&tTimer);
    Drv_Timer_Enable(&tTimer);
}
