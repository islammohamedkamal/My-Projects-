/*
 * External_EEPROM.h
 *
 * Created: 1/15/2017 2:03:14 AM
 *  Author: loma
 */ 



#ifndef EXTERNAL_EEPROM_H_
#define EXTERNAL_EEPROM_H_

#include "TWI.h"

#define ERROR 0
#define SUCCESS -1
void EEPROM_Init(void);
 unsigned char EEPROM_Write_Byte(unsigned short u16add,unsigned char u8data);

#endif /* EXTERNAL_EEPROM_H_ */