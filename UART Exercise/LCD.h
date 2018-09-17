#ifndef _LCD_H_
#define _LCD_H_

#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>

#define LCD_DATADIR		DDRA
#define LCD_CTRDIR		DDRB
#define LCD_DATA		PORTA
#define LCD_CTR			PORTB

#define LCD_RS			PB0
#define LCD_RW			PB1
#define LCD_EN			PB2

void LCD_sendCmd(unsigned char cmd);
void LCD_sendData(unsigned char data);
void LCD_sendString(unsigned char *str);
void LCD_clear(void);
void LCD_checkPointer(void);
void LCD_pointerPosition(unsigned char x, unsigned char y);
void LCD_init(void);
#endif