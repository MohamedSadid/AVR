#ifndef _LCD_H_
#define _LCD_H_

#include <avr/io.h>
#include <util/delay.h>

#define lcdData PORTA
#define lcdCtrl PORTB

#define RS PINB0
#define RW PINB1
#define EN PINB2

void lcd_send_cmd(unsigned char cmd);
void lcd_send_data(unsigned char data);
void pointer_position(unsigned char x, unsigned char y);
void lcd_send_string(unsigned char *str);
void lcd_init();

#endif