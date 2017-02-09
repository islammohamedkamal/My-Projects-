/*
 * TWI.h
 *
 * Created: 1/27/2017 9:49:32 PM
 *  Author: loma
 */ 


#ifndef TWI_H_
#define TWI_H_

#include "avr/io.h"
#include "avr/interrupt.h"

#include<avr/io.h>

#ifndef F_CPU
#define F_CPU 8000000UL
#endif
// from datasheet Atmega32
#define TW_START         0x08 // start has been sent
#define TW_REP_START     0x10 // repeated start
#define TW_MT_SLA_W_ACK  0x18 // Master transmit ( slave address + Write request ) to slave + Ack received from slave
#define TW_MT_SLA_R_ACK  0x40 // Master transmit ( slave address + Read request ) to slave + Ack received from slave
#define TW_MT_DATA_ACK   0x28 // Master transmit data and ACK has been received from Slave.
#define TW_MR_DATA_ACK   0x50 // Master received data and send ACK to slave
#define TW_MR_DATA_NACK  0x58 // Master received data but doesn't send ACK to slave

void TWI_init(void);
void TWI_Start();
void TWI_Stop();
void TWI_write(unsigned char data);
unsigned char TWI_Read_With_Ack(void);
unsigned char TWI_Read_With_NAck(void);
unsigned char TWI_Get_Status(void);

#endif /* TWI_H_ */


