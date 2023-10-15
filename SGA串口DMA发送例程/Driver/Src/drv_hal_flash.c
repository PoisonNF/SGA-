/****************************************************************************

* Sigma�Ŷ�

* �ļ���: drv_hal_flash.c

* ���ݼ�����Flash�����ļ�

* �ļ���ʷ��

* �汾��	   ����		  ����		  ˵��
*   	 	2023-09-22	�����		�������ļ�

****************************************************************************/
#include "drv_hal_conf.h"

#ifdef DRV_HAL_FLASH_ENABLE

#ifdef STM32F1_SGA_ENABLE

/**
 * @brief Flash����ҳ��F1ϵ�У�
 * 
 * @param ulPageAddr ��ʼ��ַ
 * @param ulNum ������ҳ��
 * @return int 0 �ɹ� -1 ʧ��
 */
int Drv_Flash_Erase_Page(uint32_t ulPageAddr,uint32_t ulNum)
{
    /* ����Flash */
	HAL_FLASH_Unlock();

    /* ����Flash*/
	FLASH_EraseInitTypeDef FlashSet;
	FlashSet.TypeErase = FLASH_TYPEERASE_PAGES;
	FlashSet.PageAddress = ulPageAddr;
	FlashSet.NbPages = ulNum;

    /*����PageError�����ò�������*/
	uint32_t PageError = 0;
	if(HAL_FLASHEx_Erase(&FlashSet, &PageError) == HAL_ERROR)
    {
        /* ����flash */
	    HAL_FLASH_Lock();
        return -1;
    }

    /* ����flash */
	HAL_FLASH_Lock();

    return 0;
}
#endif

#ifdef STM32F4_SGA_ENABLE

/**
 * @brief ��ȡ��ַ���ڵ�sector
 * @param ulAddress  ��ʼ��ַ	
 * @return uint32_t ulSector ������
 */
static uint32_t S_Flash_Get_Sector(uint32_t ulAddress)
{
    uint32_t ulSector = 0;

	(ulAddress <= 0x080FFFFF && ulAddress >= 0x080E0000)? ulSector = 11:
	(ulAddress >= 0x080C0000)? ulSector = 10:
	(ulAddress >= 0x080A0000)? ulSector = 9:
	(ulAddress >= 0x08080000)? ulSector = 8:
	(ulAddress >= 0x08060000)? ulSector = 7:
	(ulAddress >= 0x08040000)? ulSector = 6:
	(ulAddress >= 0x08020000)? ulSector = 5:
	(ulAddress >= 0x08010000)? ulSector = 4:
	(ulAddress >= 0x0800C000)? ulSector = 3:
	(ulAddress >= 0x08008000)? ulSector = 2:
	(ulAddress >= 0x08006000)? ulSector = 1:
	(ulAddress >= 0x08004000)? ulSector = 1:0;
	
    return ulSector;
}

/**
 * @brief Flash����Sector��F4ϵ�У�
 * @param ulStart_Addr  ��ʼ��ַ	
 * @param ulEnd_Addr    ������ַ
 * @return 0 �ɹ� -1 ʧ��
 */
int Drv_Flash_Erase_Sector(uint32_t ulStart_Addr, uint32_t ulEnd_Addr)
{
	uint32_t UserStartSector;
	uint32_t SectorError = 0;
	FLASH_EraseInitTypeDef FlashSet;

	/* ����flash */
	HAL_FLASH_Unlock();
	
	/* ��ȡ��ʼ��ַ������������FLASH*/
	UserStartSector = S_Flash_Get_Sector(start_addr);

	FlashSet.TypeErase = TYPEERASE_SECTORS;
	FlashSet.Sector = UserStartSector;
	FlashSet.NbSectors = S_Flash_Get_Sector(end_addr) - UserStartSector;
	FlashSet.VoltageRange = VOLTAGE_RANGE_3;
    
	/*���ò�������*/
	if(HAL_FLASHEx_Erase(&FlashSet, &SectorError) == HAL_ERROR)
    {
        /* ����Flash */
	    HAL_FLASH_Lock();
        return -1;
    }
	
	/* ����Flash */
	HAL_FLASH_Lock();
	return 0;
}

#endif

/**
 * @brief Flashд���ɸ�����(word)
 * @param ulAddr      д��ĵ�ַ
 * @param ulpBuf      д�����ݵ���ʼ��ַ
 * @param ulWordSize  ����
 * @return NULL
 */
void Drv_Flash_Write(uint32_t ulAddr,uint32_t *ulpBuf,uint32_t ulWordSize)
{
	/* ����Flash */
	HAL_FLASH_Unlock();

	/* ��д��ָ����ַ */
	for(uint32_t i = 0;i < ulWordSize;i++)
		HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD,ulAddr + 4*i,ulpBuf[i]);

	/* ����Flash */
	HAL_FLASH_Lock();
    
    return;
}

/**
 * @brief Flash�����ɸ�����(word)
 * @param ulAddr      �����ݵĵ�ַ
 * @param ulpBuf      �������ݵ�����ָ��
 * @param ulWordSize  ����
 * @return NULL
 */
void Drv_Flash_Read(uint32_t ulAddr, uint32_t *ulpBuf,uint32_t ulWordSize)
{
	memcpy(ulpBuf, (uint32_t*) ulAddr, ulWordSize * sizeof(uint32_t));
}

#endif
