/*
  ******************************************************************************
  * @file				flash.h                                                                  *
  * @author	    Nguyen Minh Trung                                                   *
  * @date				00/00/0000                                                         *
  ******************************************************************************
*/
	
#ifndef _FLASH_H
#define _FLASH_H


#ifdef __cplusplus
 extern "C" {
#endif

/******************************************************************************/

#include "stm32f10x_rcc.h"              // Keil::Device:StdPeriph Drivers:RCC
#include "stdio.h"
#include "stm32f10x.h"                  // Device header
#include "string.h"
#include "stdio.h"

/******************************************************************************/

#define START_ADDRESS 0x0800FC00
#define WAIT_BUSY 		while(FLASH->SR & FLASH_SR_BSY);
extern uint8_t arr_data8bit[1000];
extern uint16_t arr_data16bit[1000];
extern uint32_t arr_data32bit[1000];
extern uint64_t arr_data64bit[1000];

typedef struct{
	uint8_t Name_Player1[40];
	uint8_t Name_Player2[40];
	uint8_t		Score1;
	uint8_t		Score2;
	uint8_t 	Point1;
	uint8_t		Point2;
	uint8_t 	Round;
}Information;

/******************************************************************************/	

void Flash_Unlock(void);
void Flash_Lock(void);
void Flash_Erase(uint32_t Address);

void Flash_WriteArray8bit(uint32_t *start_address,uint8_t *arr_data, uint16_t lenght_data);
void  Flash_WriteArray16bit(uint32_t *start_address,uint16_t *arr_data, uint16_t lenght_data);
void  Flash_WriteArray32bit(uint32_t *start_address,uint32_t *arr_data, uint16_t lenght_data);
void  Flash_WriteArray64bit(uint32_t *start_address,uint64_t *arr_data, uint16_t lenght_data);
void Flash_WriteString(uint32_t *start_address,uint8_t *buff, uint16_t lenght_data);
void Flash_WriteStruct(uint32_t *start_address, Information DATA);

void Flash_ReadArray8bit(uint32_t *start_address,uint16_t lenght_data);
void Flash_ReadArray16bit(uint32_t *start_address, uint16_t lenght_data);
void Flash_ReadArray32bit(uint32_t *start_address,uint16_t lenght_data);
void Flash_ReadArray64bit( uint32_t *start_address,uint16_t lenght_data);
void Flash_ReadString( uint32_t *start_address, char *buff);
Information Flash_ReadStruct(uint32_t *start_address, Information save_str );

void  Flash_Write8bit(uint32_t *start_address,uint8_t data);
void  Flash_Write16bit(uint32_t *start_address,uint16_t data);
void  Flash_Write32bit(uint32_t *start_address,uint32_t data);
void  Flash_Write64bit(uint32_t *start_address, uint64_t data);


uint8_t Flash_Read8bit(uint32_t *start_address);
uint16_t Flash_Read16bit(uint32_t *start_address);
uint32_t Flash_Read32bit(uint32_t *start_address);
uint64_t Flash_Read64bit(uint32_t *start_address);
/******************************************************************************/	 
#ifdef __cplusplus
}
#endif

#endif

/********************************* END OF FILE ********************************/
/******************************************************************************/
