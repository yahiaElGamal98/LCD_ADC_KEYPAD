/*
 * PUSHBT_implementation.c
 *
 * Created: 1/20/2022 5:53:28 PM
 *  Author: No. 01
 */ 
#include "STD_Types"

#include "DIO_interface.h"

#include "PUSHBT_config.h"
#include "PUSHBT_interface.h"

void PUSHBT_init()
{
	 DIO_SETpinDir(PUSH_BUTTON_PORT,PUSH_BUTTON_PIN,DIO_INPUT);
	 DIO_SETpinVal(PUSH_BUTTON_PORT,PUSH_BUTTON_PIN,DIO_LOW);
}
void PUSHBT_read(uint8_t *val)
{
	 DIO_GETpinVal(PUSH_BUTTON_PORT,PUSH_BUTTON_PIN, val);
}