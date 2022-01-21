/*
 * LCD.c
 *
 * Created: 1/16/2022 4:58:29 PM
 * Author : No. 01
 */
#define F_CPU 8000000UL
#include <stdlib.h>
#include "STD_types.h" 
#include "Registers.h"
#include "Interface.h"
#include <util/delay.h>
/*

int main(void)
{
	LCD_init();
	uint8_t u8_data='A';
	LCD_sendStr("ElGamal");
    /* Replace with your application code */
  /*  while (1) 
    {
			
    }
}*/
 void ADC_Init()
{
	PORTA_DIR=0x0;			/* Make ADC port as input */
	ADCSRA = 0x87;			/* Enable ADC, fr/128  */
	ADMUX = 0x40;			/* Vref: Avcc, ADC channel: 0 */
	
}

int ADC_Read(char channel)
{
	int Ain,AinLow;
	
	ADMUX=ADMUX|(channel & 0x0f);	/* Set input channel to read */

	ADCSRA |= (1<<6);		/* Start conversion */
	while((ADCSRA&(1<<4))==0);	/* Monitor end of conversion interrupt */
	
	_delay_us(10);
	AinLow = (int)ADCL;		/* Read lower byte*/
	Ain = (int)ADCH*256;		/* Read higher 2 bits and 
					Multiply with weight */
	Ain = Ain + AinLow;				
	return(Ain);			/* Return digital value*/
}

 
int main()
{
	char String[5];
	int value;

	ADC_Init();
	LCD_init();			/* Initialization of LCD */
	LCD_sendStr("ADC value");	/* Write string on 1st line of LCD */
`
	while(1)
	{
	
		LCD_sendCmd(0xc4);	/* LCD16x2 cursor position */
		value=ADC_Read(0);	/* Read ADC channel 0 */
		itoa(value,String,10);	/* Integer to string conversion */ 
		LCD_sendStr(String);						
		LCD_sendStr("  ");			
	}
	return 0;

}