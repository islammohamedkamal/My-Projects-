/*
 * USART_Driver.c
 *
 * Created: 1/26/2017 3:09:58 AM
 *  Author: loma
 */


#include <avr/io.h>
#include "UART.h"

/*******functions For UART*******/

void USART_Init(void)
{
     sei();//ENABLE GLOBAL INTTERPUT
	 UBRRL = 0x67;
	
	

	
/***SET THE BAUD RATE******/
/*UBRRH = (u8)(UBRR_VAL>>8);
UBRRL = (u8) (UBRR_VAL);*/

/****enable THE TRANSIMTER AND RECEVIER****/

#if USART_TRANSMIT==USART_ENABLE
SetBit(UCSRB,TXEN);
#elif USART_TRANSMIT==USART_DISABLE
ClrBit(UCSRB,TXEN);
#endif
#if USART_RECIEVE==USART_ENABLE
SetBit(UCSRB,RXEN);
#elif USART_RECIEVE==USART_DISABLE
ClrBit(UCSRB,RXEN);
#endif // USART_RECIEVE
/**************SET CHARACTER SIZE********/
#if USART_CHAR_SIZE != USART_9_Bit_CHAR
UCSRC=(1<<URSEL)| (USART_CHAR_SIZE);
#elif USART_CHAR_SIZE == USART_9_Bit_CHAR
UCSRC=(1<<URSEL)| (USART_CHAR_SIZE);
SetBit(UCSRB,2);
#endif // USART_CHAR_SIZE*/


		  /***************SET DOUBLE SPEED******/
           #if (USART_SPEED_MODE== USART_DOUBLE_SPEED)
		    SetBit(UCSRA,U2X);
            #endif // USART_DOUBLE_SPEED
/*
            /**************** Set Parity Bit***************/
		UCSRC |= (1<<URSEL) | USART_PARITY_MODE;
		/**************** Set SYNCH ASYNCH***************/
	UCSRC |= (1<<URSEL) | USART_SYNCH_MODE;
		/**************** Set Stop Bit***************/
	UCSRC |= (1<<URSEL) | USART_STOPBIT;
		/***************RECIEVER INT ENABLE**********/
	UCSRB |= USART_RECIEVE_INT;
		/***************TRANSMITER INT ENABLE**********/
	UCSRB |= USART_TRANSMITER_INT;
}
	/***************************************
* Function Description: USART transmits Data received
* Input: Data
* Prerequisite: USART Init
* Return: None
 ***********************************************/
    void USART_FUN_TRANSMIT(u16 data)
    {	/*//Wait for the UDR to be empty*/
        while(!(UCSRA&(1<<UDRE)));
		 /*****IF THE DATA TRANSMIITED IN 9 BITS MODE SO WE WRITE
        THE MOST BIT FRIST IN THIER PLACE UCSRB***/
        #ifdef USART_CHAR_SIZE==USART_9_Bit_CHAR
        UCSRB|=GetBit(data,8);//THE TXB8 in the frist bit in UCSRB so Getbit wil get single bit only in the frist 
		#endif
		//Put the data the lower 8 bits in UDR	
		
     
	 
	   UDR=(u8)data;
    }

/*************************************************************
 * Function Description: USART Receives Data received
 * Input: Pointer to be filled with data
 * Prerequisite: USART Init
 * Return: Parity check
 ************************************************************/    
u8 USART_FUN_Receive(void)
{
/*	u8 Parity_Error=error;
	*Ptr_To_Val=0; 
	
	/*Wait for data to be received*/
	while(!(UCSRA&(1<<RXC)));
	return UDR;
	
	/*****Check the Parity *******/
	/*if(GetBit(UCSRA,PE)!=1)/*if no parity error do the following */
	/*{
		  #ifdef USART_CHAR_SIZE==USART_9_Bit_CHAR
		  *Ptr_To_Val=GetBit(UCSRB,1)<<8;
		  #endif	
			*Ptr_To_Val=UDR;
			Parity_Error=okay;

	}
	return Parity_Error;
	*/
	
}
/**********Functions to Enable and disable the Interrupt***************/
	 void USART_Rec_Int_Enable(void)
	{
		SetBit(UCSRB,RXCIE);
	}

	 void USART_Rec_Int_Disable(void)
	{
		ClrBit(UCSRB,RXCIE);
	}

	void USART_Trans_Int_Enable(void)
	{
		SetBit(UCSRB,TXCIE);
	}

	 void USART_Trans_Int_Disable(void)
	{
		ClrBit(UCSRB,TXCIE);
	}
/**********Functions to enable and disable the transmiter and receiver ******/// 
	 void USART_Rec_Enable(void)
	{
		SetBit(UCSRB,RXEN);
	}

	 void USART_Rec_Disable(void)
	{
		ClrBit(UCSRB,RXEN);
	}

	void USART_Trans_Enable(void)
	{
		SetBit(UCSRB,TXEN);
	}

	 void USART_Trans_Disable(void)
	{
		ClrBit(UCSRB,TXEN);
	}
