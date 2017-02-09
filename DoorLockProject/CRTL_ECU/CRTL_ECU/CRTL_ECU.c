/*
 * CRTL_ECU.c
 *
 * Created: 1/28/2017 5:54:07 AM
 *  Author: loma
 */ 


#include <avr/io.h>
#include "UART.h"
#include "LED.h"
#include "Timer_For_Door.h"
#include "TWI.h"
#include "External_EEPROM.h"
#include "avr/delay.h"
int main(void)
{
	unsigned char x,y,z=0,n=0;
	unsigned short i='A' ,Fault='0';
	USART_Init();
	TWI_init();
	
	while (z<2)
	{
		EEPROM_Write_Byte(z,i);
		_delay_ms(10);
		z++;
		i++;
	}
	z=0;
	
	while (1)
	{
		
		while(z<2)
		{
			x=USART_FUN_Receive();
			EEPROM_Read_Byte(z,&y);
			if (x!=y)
			{
				Fault++;
			}
			z++;
		}
		
		z=0;
		//tranmist to HIM-Mircocontroller Two Times 
		USART_FUN_TRANSMIT(Fault);	//One for if( USART_FUN_Receive()>'0')
		USART_FUN_TRANSMIT(Fault); //	one for if(USART_FUN_Receive()=='0')
		
		if (x=='N')
		{
			Led_ON();
		}
		else if (x=='O')
		{
			Led_OFF();
		}
		
		
		while(Fault=='0')
		{
			x=USART_FUN_Receive();
			
			if (x=='A')
			{
				Open_Door();
			}
			else if (x=='B')
			{
				Close_Door();
				break;
			}
			else if (x=='C')
			{
				
				while (n<2)
				{
					x=USART_FUN_Receive();
					//if (x!='D')
					//	{
					EEPROM_Write_Byte(n,x);
					_delay_ms(10);
					//	EEPROM_Read_Byte(n,&y);
					//}
					n++;
				}
				n=0;
			break;
			}
		}
		
		Fault='0';
	}
}
