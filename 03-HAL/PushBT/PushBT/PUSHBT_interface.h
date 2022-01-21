/*
 * PUSHBT_interface.h
 *
 * Created: 1/20/2022 5:53:05 PM
 *  Author: No. 01
 */ 


#ifndef PUSHBT_INTERFACE_H_
#define PUSHBT_INTERFACE_H_

#if USED_BUTTON==BUTTON_1

#define PUSH_BUTTON_PORT DIO_PORTB
#define PUSH_BUTTON_PIN DIO_PIN2

#elif USED_BUTTON==BUTTON_0

#define PUSH_BUTTON_PORT DIO_PORTC
#define PUSH_BUTTON_PIN DIO_PIN4

#endif

void PUSHBT_init();
void PUSHBT_read(uint8_t *val);



#endif /* PUSHBT_INTERFACE_H_ */