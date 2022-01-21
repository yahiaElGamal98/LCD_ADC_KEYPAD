/*
 * KPD_implementation.c
 *
 * Created: 1/19/2022 12:48:43 AM
 *  Author: No. 01
 */ 


#include "STD_types.h"
#include "Registers.h"
#include "DIO.h"
#include "KPD_config.h"
#include "KPD_Interface.h"

#define KPD_size 6

uint8_t gau8_KPD_keys[3][3]={{'1','2','3'},
{'4','5','6'},
{'7','8','9'}};

void msdelay(unsigned int time)
{
	volatile unsigned int i,j;
	for(i=0;i<time;i++)
	{
		for(j=0; j<450; j++)
		{
			
		}
	}
}
void KPD_init(void)
{
	uint8_t u8_index;
	ST_DIO_config_t ast_KPD_config[KPD_size]={{KPD_PORT,ROW1,OUTPUT},
	{KPD_PORT,ROW2,OUTPUT},
	{KPD_PORT,ROW3,OUTPUT},
	{KPD_PORT,COL1,INPUT},
	{KPD_PORT,COL2,INPUT},
	{KPD_PORT,COL3,INPUT}};
	for(u8_index=0;u8_index<KPD_size;u8_index++)
	{
		DIO_init(ast_KPD_config+u8_index);
		DIO_write(ast_KPD_config[u8_index].PORT,ast_KPD_config[u8_index].Px,HIGH);
	}
}
void KPD_getVal(uint8_t *val)
{
	EN_pins u8_colIndex=0, u8_rowIndex=0;
	uint8_t u8_retVal=0;
	for(u8_rowIndex=ROW1;u8_rowIndex<=ROW3;u8_rowIndex++)
	{
		DIO_write(KPD_PORT,ROW1,HIGH);
		DIO_write(KPD_PORT,ROW2,HIGH);
		DIO_write(KPD_PORT,ROW3,HIGH);
		DIO_write(KPD_PORT,u8_rowIndex,LOW);
		for(u8_colIndex=COL1;u8_colIndex<=COL3;u8_colIndex++)
		{
			DIO_read(KPD_PORT,u8_colIndex,&u8_retVal);
			if(u8_retVal==0)
			{
				msdelay(20);
				while(!u8_retVal)
				{
					DIO_read(KPD_PORT,u8_colIndex,&u8_retVal);
				}
				*val=gau8_KPD_keys[u8_rowIndex-ROW_OFFSET][u8_colIndex-COL_OFFSET];
			}
			
		}
	}
}
