/*
 * KPD_Interface.h
 *
 * Created: 1/19/2022 12:48:29 AM
 *  Author: No. 01
 */ 


#ifndef KPD_INTERFACE_H_
#define KPD_INTERFACE_H_

void KPD_init(void);  //initialization function
void KPD_getVal(uint8_t *kpdVal); //function to return keypad value into the pointer kpdVal
void KPD_msdelay(uint8_t time); //delay to reduce bouncing




#endif /* KPD_INTERFACE_H_ */