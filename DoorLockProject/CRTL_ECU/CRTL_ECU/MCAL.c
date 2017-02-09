/*
 * MCAL.c
 *
 * Created: 1/29/2015 3:46:58 PM
 *  Author: abdelrhman mady ebrahim
 */ 

void set_Dir_PIN (unsigned char *DDRX,unsigned char Dir,unsigned char PIN){
	
	if(Dir == 1)
	
	*DDRX |= (1<< PIN);
	
	else if(Dir == 0)
	
	*DDRX &= (~(1<< PIN));
	
}
void Set_PIN (unsigned char *PORTX,unsigned char PIN){
	
	*PORTX |= (1<< PIN);
}
void Clear_PIN (unsigned char *PORTX,unsigned char PIN){
	
	*PORTX &= (~(1<< PIN));
}
unsigned char Read_PIN(unsigned char *PORTX,unsigned char PIN){
	
	unsigned char value;
	value=*PORTX & (1<<PIN);
	value=value>>6;
	return value;
	
}
