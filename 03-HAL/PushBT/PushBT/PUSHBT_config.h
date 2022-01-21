/*
 * PUSHBT_config.h
 *
 * Created: 1/20/2022 5:52:42 PM
 *  Author: No. 01
 */ 


#ifndef PUSHBT_CONFIG_H_
#define PUSHBT_CONFIG_H_

#define BUTTON_0 0
#define BUTTON_1 1

#define USED_BUTTON BUTTON_1

#if USED_BUTTON==BUTTON_1

#define PUSH_BUTTON_PORT DIO_PORTB
#define PUSH_BUTTON_PIN DIO_PIN2

#elif USED_BUTTON==BUTTON_0

#define PUSH_BUTTON_PORT DIO_PORTC
#define PUSH_BUTTON_PIN DIO_PIN4

#endif




#endif /* PUSHBT_CONFIG_H_ */