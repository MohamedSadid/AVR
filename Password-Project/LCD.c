#include "LCD.h"

void lcd_send_cmd(unsigned char cmd) {
	lcdData = cmd;
	
	lcdCtrl &= ~(1 << RS);
	lcdCtrl &= ~(1 << RW);
	lcdCtrl |= (1 << EN);
	_delay_ms(10);
	lcdCtrl &= ~(1 << EN);
	_delay_ms(10);
}

void lcd_send_data(unsigned char data) {
	lcdData = data;
	
	lcdCtrl |= (1 << RS);
	lcdCtrl &= ~(1 << RW);
	lcdCtrl |= (1 << EN);
	_delay_ms(10);
	lcdCtrl &= ~(1 << EN);
	_delay_ms(10);
}

void pointer_position(unsigned char x, unsigned char y) {
	unsigned char arr[] = {0x80, 0xC0};
	lcd_send_cmd(arr[x - 1] + y - 1);
}

void lcd_send_string(unsigned char *str) {
	int i = 0;
	while (str[i] != '\0') {
		lcd_send_data(str[i]);
		i++;
	}
}

void lcd_init() {
	
	DDRA = 0xFF;
	DDRB = 0x07;
	
	lcd_send_cmd(0x38);
	_delay_ms(1);
	
	lcd_send_cmd(0x01);
	_delay_ms(1);
	
	lcd_send_cmd(0x0F);
	_delay_ms(1);
	
	lcd_send_cmd(0x80);
	_delay_ms(1);
	
	_delay_ms(50);
}