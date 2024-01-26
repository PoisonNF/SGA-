#ifndef __DRV_CAN_H_
#define __DRV_CAN_H_

#include "drv_hal_conf.h"

typedef struct
{
    CAN_HandleTypeDef tCANHandle;           /* CAN��� */
    CAN_TxHeaderTypeDef tCANTxHeader;       /* CAN���;�� */
    CAN_RxHeaderTypeDef tCANRxHeader;       /* CAN���վ�� */
    CAN_FilterTypeDef tCANFilter;           /* CAN���������þ�� */
    tagGPIO_T tGPIO[2];                     /* GPIO���� */

}tagCAN_T;

void Drv_CAN_ModeConfig(tagCAN_T *_tCAN,uint32_t _ulMode);
void Drv_CAN_TxIDConfig(tagCAN_T *_tCAN,uint32_t _ulID);
uint8_t Drv_CAN_SendMsg(tagCAN_T *_tCAN,uint8_t *_ucpMsg,uint8_t _ucLen);
uint8_t Drv_CAN_ReceMsg(tagCAN_T *_tCAN,uint8_t *_ucpMsg);
void Drv_CAN_Init(tagCAN_T *_tCAN);

#endif
