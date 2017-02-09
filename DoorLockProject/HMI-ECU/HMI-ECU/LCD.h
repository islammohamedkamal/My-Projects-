/*
 * LCD.h
 *
 * Created: 1/25/2017 8:26:54 PM
 *  Author: Islam Mohamed Kamal
 */ 


#ifndef LCD_H_
#define LCD_H_
//Data port for lCD
#define Mr_LCD_PORT			MyPORTC // MyPORTB //MyPORTC //MyPORTD
#define Mr_LCD_PORT_Dir		MyDDRC //MyDDRB //MyDDRC //MyDDRD

//control port for lCD
#define  Mr_LCD_Control		MyPORTA
#define Mr_LCD_Control_Dir	MyDDRA

#define EN 2
#define RS 0
#define RW 1

void LCD_Init(void);
void Send_Command(unsigned char command);
void Send_Character(unsigned char ch);
void Send_String(char* str);
void clear_screen(void);
void lcd_kick(void);
void display_number (int number);
void display_real_number (int number);
void LCD_DisplayString_ATXY(char *str,unsigned char row,unsigned char col);
void LCD_GotoXY(unsigned char row, unsigned char col);
void check_LCD_isbusy(void);
#endif /* LCD_H_ */