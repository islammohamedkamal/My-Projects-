/*
 * UART.h
 *
 * Created: 1/26/2017 7:00:58 AM
 *  Author: loma
 */


#ifndef UART_H_
#define UART_H_

// Include Part
#include "Marcos.h"
#include "avr/io.h"
#include "avr/interrupt.h"

//Configuration Part
#define USART_SYNCH_MODE  USART_ASYNCH //USART_SYNC
#define USART_SPEED_MODE/* USART_NORMAL_SPEED */ USART_DOUBLE_SPEED


#define USART_BAUD 9600
#define USART_FOSC 8000000

#define USART_TRANSMIT			USART_ENABLE //USART_DISABLE
#define USART_RECIEVE			USART_ENABLE //USART_DISABLE
#define USART_CHAR_SIZE			USART_8_Bit_CHAR//USART_6_Bit_CHAR,USART_7_Bit_CHAR,USART_5_Bit_CHAR,USART_9_Bit_CHAR
#define USART_PARITY_MODE		USART_NO_PARITY//USART_EVEN_PARITY,USART_ODD_PARITY
#define USART_STOPBIT			USART_1_STOPBIT//USART_2_STOPBIT
#define USART_RECIEVE_INT		/*USART_RECIEVER_ENABLE*/  USART_RECIEVER_DISABLE
#define USART_TRANSMITER_INT	/*USART_TRANSMITER_ENABLE*/USART_TRANSMITER_DISABLE
#define USART_DOUBLE_SPEED	1
#define USART_NORMAL_SPEED	1


//Driver Macros
//***Baud-Rate
#if ((USART_SYNCH_MODE == USART_ASYNCH) && (USART_SPEED_MODE == USART_NORMAL_SPEED))
	#define UBRR_VAL	(u32)((USART_FOSC/(16*USART_BAUD))-1)
#else if USART_SYNCH_MODE == USART_SYNC
	#define UBRR_VAL	(u32)((USART_FOSC/(2*USART_BAUD))-1)
#endif

/********************USART ENABLE/DISABLE TRANSMITER/RECIEVER********************/
#define USART_ENABLE	Enable
#define USART_DISABLE	disable
/*******************USART CHARACTER SIZE********************///Bit 1 and Bit 2 in UCSRC
#define USART_5_Bit_CHAR 		(0b00<<1)
#define USART_6_Bit_CHAR 		(0b01<<1)
#define USART_7_Bit_CHAR	    (0b10<<1)
#define USART_8_Bit_CHAR	    (0b11<<1)
#define USART_9_Bit_CHAR	    (0b11<<1)

/********************USART ASYNCH/SYNCH MODE*********/ //Bit 6 "UMSEL" in UCSRC
#define USART_ASYNCH (0<<6)
#define USART_SYNC   (1<<6)

/********************USART STOP BIT *****************///Bit 3 "USBS" in UCSRC
#define USART_1_STOPBIT	(0<<3)
#define USART_2_STOPBIT (1<<3)
////////////////////Parity///////////////Bit 4 and 5 in UCSRC

#define   USART_NO_PARITY		(0<<4)
#define   USART_EVEN_PARITY		(2<<4)
#define   USART_ODD_PARITY 	    (3<<4)
/********************USART INT ENABLE*********************/
#define USART_RECIEVER_ENABLE 		(1<<7)
#define USART_RECIEVER_DISABLE 		(0<<7)
#define USART_TRANSMITER_ENABLE 	(1<<6)
#define USART_TRANSMITER_DISABLE 	(0<<6)

/***************Global Functions Prototypes***************/
#define okay  1
#define error 0
/////////////////////////////////////////////////

void USART_Init(void);
void USART_FUN_TRANSMIT(u16 data);
u8 USART_FUN_Receive(void);
#endif /* UART_H_ */
