/*
 * External_EEPROM_c.c
 *
 * Created: 1/15/2017 2:01:07 AM
 *  Author: loma
 */

#include "External_EEPROM.h"

 void EEPROM_Init(void)
 {
 TWI_init(); // just init the TWI inside The Microcontroller 
 

 }
 
 
 unsigned char EEPROM_Write_Byte(unsigned short u16add,unsigned char u8data)
{
	TWI_Start(); // Frist Send the start bit
	
	
	// Check the status register for the start bit
		if (TWI_Get_Status()!=TW_START)
	return ERROR; 
	
	//EEPROM have 2048 bytes so you need 11 bits to acccess the addres 
	//So frist you send the fixed ID for EEPROM 0b1010=0xA, And R/w bit=0 And A10 And A9 And A8
	
	TWI_write((unsigned char) ((0xA0) | ((u16add & 0x0700)>>7)));
	//check the status register for the slave address and 
	if (TWI_Get_Status()!=TW_MT_SLA_W_ACK)
	return ERROR;
	
	
	//Then send address from A7 to A0
	TWI_write((unsigned char)(u16add));
	if (TWI_Get_Status()!=TW_MT_DATA_ACK)
	return ERROR;
	TWI_write(u8data);
	if (TWI_Get_Status() != TW_MT_DATA_ACK)
	return ERROR;
	
	TWI_Stop(); // in stop bit you dont need to check the status register 
	
	return SUCCESS;

}


unsigned char EEPROM_Read_Byte(unsigned short u16add,unsigned char *u8data)
{
	TWI_Start(); // Frist Send the start bit
	
	// Check the status register for the start bit
	if (TWI_Get_Status()!=TW_START)
	return ERROR;
	
	
	//EEPROM have 2048 bytes so you need 11 bits to access the address
	//So frist you send the fixed ID for EEPROM 0b1010=0xA, And R/w bit=0 for WRITE And A10 And A9 And A8
	TWI_write((unsigned char) (0xA0 | ((u16add & 0x0700)>>7)));
	//check the status register for the slave address and
	if (TWI_Get_Status()!=TW_MT_SLA_W_ACK)
	return ERROR;
	
	//Then send address from A7 to A0
	TWI_write((unsigned char)(u16add));
	if (TWI_Get_Status()!=TW_MT_DATA_ACK)
	return ERROR;
	
	// so we need to Repeat start to start read from eeprom
	TWI_Start();
	if(TWI_Get_Status()!=TW_REP_START)
	return ERROR;

//So first you send the fixed ID for EEPROM 0b1010=0xA, And R/w bit=1 for READ And A10 And A9 And A8
 TWI_write((unsigned char) (0xA0 | ((u16add & 0x0700)>>7)|1));// HOW OR WITH 1?????? 
	if (TWI_Get_Status()!=TW_MT_SLA_R_ACK)
	return ERROR;
	
	*u8data=TWI_Read_With_NAck();
	 if (TWI_Get_Status() != TW_MR_DATA_NACK)
	 return ERROR;
	
	
	TWI_Stop(); // in stop bit you don't need to check the status register
	
	return SUCCESS;

}
 