/*
 * Test_Door.c
 *
 * Created: 1/18/2017 5:45:19 PM
 *  Author: loma
 */ 


#include <avr/io.h>
#include "LCD.h"
#include "Keypad.h"
#include "UART.h"
#define F_CPU 8000000ul



int main(void)
{
	unsigned char x,i=0,t;
	unsigned char End=0;
	
	
	LCD_Init();
	USART_Init();
	KeyPad_Init();
	while(1)
	{
		while(t<3) //Five Times Only to enter the right password
		{
			LCD_DisplayString_ATXY("Please Enter pass",0,0);
			while(i<2) //the password will be 2 numbers
			{
				x=KeyPad_getKey();//get key from keypad
				
				if(x!='F') //in keypad_func "if no key is pressed send 'F'
				{
					LCD_GotoXY(3,i);
					Send_Character(x);
					USART_FUN_TRANSMIT(x);///transmit the given password to UC2
					i++;
				}
			}
			i=0;
			
			if( USART_FUN_Receive()>'0')//each receieve function must have tran_function
			{
				clear_screen();
				t++;
				LCD_DisplayString_ATXY("Password is Wrong",0,0);
				_delay_ms(1000);
				clear_screen();
			}
			if(USART_FUN_Receive()=='0')
			{
				clear_screen();
				t=0;
				LCD_DisplayString_ATXY("Password is right",0,0);
				
				End=0;
				while(1 && !End)
				{
					LCD_DisplayString_ATXY("A:Open The Door",1,0);
					LCD_DisplayString_ATXY("B:Close The Door",2,0);
					LCD_DisplayString_ATXY("C:Change Password",3,0);
					
					while(1)
					{
						x=KeyPad_getKey();
						if(x!='F')
						{
							clear_screen();
							if(x=='A')
							{
								USART_FUN_TRANSMIT('A');
								clear_screen();
								LCD_DisplayString_ATXY("Door is Opened",0,0);
								_delay_ms(1000);
								
								break;
							}
							else if(x=='B')
							{
								USART_FUN_TRANSMIT('B');
								clear_screen();
								LCD_DisplayString_ATXY("Door is Closed",0,0);
								_delay_ms(1000);
								End=1;
								break;
							}
							else if(x=='C')
							{
								USART_FUN_TRANSMIT('C');
								clear_screen();
								LCD_DisplayString_ATXY("Enter New Password",0,0);
								while (i<2)
								{
									x=KeyPad_getKey();
									if (x!='F')
									{
										LCD_GotoXY(3,i);
										Send_Character(x);
										USART_FUN_TRANSMIT(x);
										i++;
									}
								
								}
								i=0;
								clear_screen();
								LCD_DisplayString_ATXY("Password Saved",0,0);
								clear_screen();
								_delay_ms(1000);
								End=1;
								break;
							}
						}
						
					}
				}
				
			}
			
		}
		if(t>=3)
		{
			USART_FUN_TRANSMIT('N');
		}
		else
		{
			USART_FUN_TRANSMIT('O');
		}
	}
}