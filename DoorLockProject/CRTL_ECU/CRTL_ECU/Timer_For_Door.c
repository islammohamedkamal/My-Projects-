/*
 * Timer_For_Door.c
 *
 * Created: 1/28/2017 6:01:23 AM
 *  Author: loma

 */ 
#include<avr/io.h>
void Open_Door(){
	
	
	TCCR1A|=(1<<COM1A1)|(1<<COM1B1)|(1<<WGM11);
	TCCR1B|=(1<<WGM13)|(1<<WGM12)|(1<<CS11);
	ICR1=19999;
	DDRD|=(1<<PD5);
	OCR1A =1238;
}
void Close_Door(){
	
	
	TCCR1A|=(1<<COM1A1)|(1<<COM1B1)|(1<<WGM11);
	TCCR1B|=(1<<WGM13)|(1<<WGM12)|(1<<CS11);
	ICR1=19999;
	DDRD|=(1<<PD5);
	OCR1A =337;
}