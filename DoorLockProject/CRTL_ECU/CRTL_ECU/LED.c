/*
 * LED.c
 *
 * Created: 1/28/2017 5:59:30 AM
 *  Author: loma
 */ 
#include<avr/io.h>

void Led_ON(){
	
	DDRC |= (1<<PC5);
	PORTC |= (1<<PC5);
}
void Led_OFF(){
	
	DDRC |= (1<<PC5);
	PORTC &=(~(1<<PC5));
}