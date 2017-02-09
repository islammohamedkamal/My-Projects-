/*
 * keypadtest.c
 *
 * Created: 1/18/2017 7:10:12 PM
 *  Author: loma
 */ 
#include <avr/io.h>
#include <util/delay.h>

void KeyPad_Init(void)
{
	// Init Input Port
	// Init Output Port
	DDRB = 0xF0;
	PORTB = 0xFF;
}

unsigned char KeyPad_getKey(void)
{
	unsigned char count = 0;
	unsigned char rows_value = 0;
	for(count=4; count<8; count++)
	{
		PORTB = PORTB | 0xF0;
		// Make Col = 0
		PORTB = PORTB & (~(1<<count));
		// To let Col = 0 for small time
		_delay_ms(1);
		rows_value = PINB & 0x0F;
		if(rows_value != 0x0F)
		{
			while((PINB & 0x0F) != 0x0F);
			break;
		}
	}
	if(count == 8)
	{
		return 'F';
	}
	count = count - 4;

	switch(count)
	{
		// Col0
		case 0:
		switch(rows_value)
		{
			case 0x0E:
			return '7';
			break;
			case 0x0D:
			return '4';
			break;
			case 0x0B:
			return '1';
			break;
			case 0x07:
			return '*';
			break;
			default:
			break;
		}
		break;
		// Col1
		case 1:
		switch(rows_value)
		{
			case 0x0E:
			return '8';
			break;
			case 0x0D:
			return '5';
			break;
			case 0x0B:
			return '2';
			break;
			case 0x07:
			return '0';
			break;
			default:
			break;
		}
		break;
		// Col2
		case 2:
		switch(rows_value)
		{
			case 0x0E:
			return '9';
			break;
			case 0x0D:
			return '6';
			break;
			case 0x0B:
			return '3';
			break;
			case 0x07:
			return '#';
			break;
			default:
			break;
		}
		break;
		// Col3
		case 3:
		switch(rows_value)
		{
			case 0x0E:
			return 'A';
			break;
			case 0x0D:
			return 'B';
			break;
			case 0x0B:
			return 'C';
			break;
			case 0x07:
			return 'D';
			break;
			default:
			break;
		}
		break;

		default:
		break;
	}
}
