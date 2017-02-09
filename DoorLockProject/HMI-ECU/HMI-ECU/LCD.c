/*
 * LCD.c
 *
 * Created: 1/25/2017 8:26:27 PM
 *  Author: islam mohamed kamal
 */ 
#include "LCD.h"
#include "Marcos.h"
#include "avr/delay.h"
void LCD_Init(void)
{
	//_delay_ms(20);
	
	Mr_LCD_Control_Dir|=(1<<EN | 1<<RS | 1<<RW);//make 3 bits for control output
	Mr_LCD_Control &=(1<<EN | 1<<RS | 1<<RW); // initialize at first =0
	
	Mr_LCD_PORT_Dir=0xFF; //make all ports data to lcd output
	_delay_ms(15);
	
		clear_screen ();
		Send_Command(0x38); // Function Set: 8-bit, 2 Line, 5x7 Dots
	
		Send_Command(0x0E); // Display on Cursor on
		Send_Command(0x06);// increment cursor (Entry Mode)
		Send_Command(0x80);// cursor position
	

}

void Send_Command(unsigned char command)
{
	//check_lcd_isBusy();
	Mr_LCD_PORT=command;
	ClrBit(Mr_LCD_Control,RS);//RS =0 for Command 
	ClrBit(Mr_LCD_Control,RW);// RW =0 for write in screen 
	lcd_kick();
}
void Send_Character(unsigned char ch)
{
	SetBit(Mr_LCD_Control,RS); //RS=1 for Data
	ClrBit(Mr_LCD_Control,RW); // RW=0 For Write
	Mr_LCD_PORT=ch;
	lcd_kick();	
}
void Send_String(char* str)
{
	while(*str != '\0')
	{
		Send_Character(*str);
		str++;
	}

}
void clear_screen(void)
{
	Send_Command(0x01);
}

void lcd_kick(void)
{
	Mr_LCD_Control &= ~(1<<EN);
	
	asm volatile("nop"); //asm volatile to write assembly in C code 
	asm volatile("nop");//nop is no operation 
	_delay_ms(50);
	
	Mr_LCD_Control |=(1<<EN);
}
void LCD_GotoXY(unsigned char row, unsigned char col)
{
	if(row == 0)
	{
		Send_Command(0x80 + col);
	}
	else if(row == 1)
	{
		Send_Command(0xC0 + col);
	}
	else if (row == 2)
	{
		Send_Command(0x94 + col);
	}
	else if (row == 3)
	{
		Send_Command(0xD4 + col);
	}
	
}
void LCD_DisplayString_ATXY(char *str,unsigned char row,unsigned char col)
{	
	LCD_GotoXY(row,col);
	
	Send_String(str); //display the string
	
}
void check_LCD_isbusy(void)
{
	ClrBit(Mr_LCD_PORT_Dir,7);
	SetBit(Mr_LCD_Control,RW);
	while(Mr_LCD_PORT=0x80);

}
void display_number (int number)
{
	char str[7];
	sprintf(str,"%d",number);
	Send_String(str);
}
void display_real_number (int number)
{
	char str[7];
	sprintf(str,"%f",number);
	Send_String(str);
}