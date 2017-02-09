/*
 * MCAL.h
 *
 * Created: 1/29/2015 3:47:22 PM
 *  Author: Ahmed Mohamed Fathi
 */ 


#ifndef MCAL_H_
#define MCAL_H_

#define F_CPU 8000000ul
#include <avr/io.h>
#include <util/delay.h>

#define PA 0x39
#define DA 0x3A
#define POA 0x3B
#define PB 0x36
#define DB 0x37
#define POB 0x38
#define PC 0x33
#define DC 0x34
#define POC 0x35
#define PD 0x30
#define DD 0x31
#define POD 0x32

void set_Dir_PIN (unsigned char *DDRX,unsigned char Dir,unsigned char PIN);
void Set_PIN (unsigned char *PORTX,unsigned char PIN);
void Clear_PIN (unsigned char *PORTX,unsigned char PIN);
unsigned char Read_PIN(unsigned char *PORTX,unsigned char PIN);


#endif /* MCAL_H_ */