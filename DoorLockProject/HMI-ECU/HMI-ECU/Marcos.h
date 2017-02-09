/*
 * Marcos.h
 *
 * Created: 1/25/2017 9:05:16 PM
 *  Author: Islam Mohamed Kamal
 */ 


#ifndef MARCOS_H_
#define MARCOS_H_

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned long u32;
typedef signed long s32;
typedef unsigned long long u64;
typedef float f32;
typedef double f64;


#define GetBit(Reg,BitNo)	((Reg>>BitNo)&1)
#define ClrBit(Reg,BitNo)	(Reg &= ~(1<<(BitNo)))
#define SetBit(Reg,BitNo)	(Reg |=(1<<BitNo))
#define ToggelBit(Reg,BitNo)	(Reg^=(1<<BitNo))

//Port A
#define MyDDRA *((volatile unsigned char* const)0x3A)
#define MyPORTA *((volatile unsigned char* const)0x3B)
#define MyPINA *((volatile unsigned char* const)0x39)
//Port B
#define MyDDRB *((volatile unsigned char* const)0x37)
#define MyPORTB *((volatile unsigned char* const)0x38)
#define MyPINB *((volatile unsigned char* const)0x36)
//Port C
#define MyDDRC *((volatile unsigned char* const)0x34)
#define MyPORTC *((volatile unsigned char* const)0x35)
#define MyPINC *((volatile unsigned char* const)0x33)
//Port D
#define MyDDRD *((volatile unsigned char* const)0x31)
#define MyPORTD *((volatile unsigned char* const)0x32)
#define MyPIND *((volatile unsigned char* const)0x30)




#endif /* MARCOS_H_ */