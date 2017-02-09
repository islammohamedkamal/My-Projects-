/*
 * Keypad.h
 *
 * Created: 1/18/2017 3:41:09 PM
 *  Author: loma
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_
#include <avr/io.h>
#include <util/delay.h>
#define F_CPU 8000000ul


void KeyPad_Init(void);
unsigned char KeyPad_getKey(void);



#endif /* KEYPAD_H_ */