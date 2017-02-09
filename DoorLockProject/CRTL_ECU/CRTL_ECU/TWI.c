/*
 * TWI.c
 *
 * Created: 1/27/2017 9:49:06 PM
 *  Author: loma
 */ 

#include "TWI.h"


void TWI_init(void)
{
	//Frist : to work scl by 400kps so we put TWBR =0x02 and TWPS Bits in TWSR 00
	TWBR=0x02;
	TWSR=0x00;
	//Second : /* Two Wire Bus address TWAR if any master device want to call me: 0x1 
	TWAR=0x02;// my addres is 0x01 bec 0x02 =b0000001,0 and bit for call recogniton
	
	//Enable TWI
	TWCR=(1<<TWEN);
	
}
void TWI_Start()
{
	//1) CLear TWINT by put 1 on it 2)Put 1 >> TWSTA 3) ENABLE TWI 
TWCR=(1<<TWINT | 1<<TWSTA | 1<<TWEN);
while(!( TWCR & (1<<TWINT) ));	
} 
void TWI_Stop()
{	//1) CLear TWINT by put 1 on it 2)Put 1 >> TWSTO 3) ENABLE TWI 
	TWCR=(1<<TWINT | 1<<TWSTO | 1<<TWEN);

}

void TWI_write(unsigned char data)
{
	TWDR=data;
	TWCR=(1<<TWINT | 1<<TWEN);
	while(!(TWCR & 1<<TWINT	));
	
}

unsigned char TWI_Read_With_Ack(void)
{
	TWCR=(1<<TWINT | 1<< TWEN | 1<<TWEA); //with Ack
	while (!(TWCR & (1<<TWINT)));
	return TWDR;
	}
	
unsigned char TWI_Read_With_NAck(void)
	{
		TWCR=(1<<TWINT | 1<< TWEN ); //without Ack
		while (!(TWCR & (1<<TWINT)));
		return TWDR;
	}
	unsigned char TWI_Get_Status(void)
	{
		unsigned char status;
		status = TWSR & 0xf8; //to mask the 2 bit of prscale and 1 bit reserved in TWSR
		return status;
	}
	