#include "stm32f10x.h"                  // Device header
#include "stm32f10x_rcc.h"              // Keil::Device:StdPeriph Drivers:RCC
#include "stm32f10x_usart.h"            // Keil::Device:StdPeriph Drivers:USART
#include "uart.h"
#include "flash.h"



int main() 
{
	Information save_str;
//	uint32_t number;
//	Information flash_data_save_str = {"Hello", "HI",1 ,7 ,5 ,2 ,3};
//	uint32_t add = 0x0800FC00;
//	Flash_Unlock();
//	Flash_Erase(add);
//	Flash_WriteStruct(&add, flash_data_save_str );

//	Flash_Lock();
	Usart_Config(USART1, 9600);
  while(1) 
	{
		uint32_t add = 0x0800FC00;
		Flash_ReadStruct(&add, save_str);
		Usart_Send_String((char *)save_str.Name_Player1);
		Usart_Send_String((char *)save_str.Name_Player2);
  }
}

