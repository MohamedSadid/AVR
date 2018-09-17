#include "LCD.h"

static unsigned char pointerY = 0;
static unsigned char pointerX = 1;

void LCD_init(void) {
	LCD_DATADIR = 0xFF;
	LCD_CTRDIR |= ((1 << LCD_RS) | (1 << LCD_RW) | (1 << LCD_EN));
	
	LCD_sendCmd(0x38);
	LCD_sendCmd(0x01);
	LCD_sendCmd(0x0F);
	LCD_sendCmd(0x80);
	_delay_ms(15);
}

void LCD_sendCmd(unsigned char cmd) {
	LCD_DATA = cmd;
	
	LCD_CTR	&= ~(1 << LCD_RS);
	LCD_CTR	&= ~(1 << LCD_RW);
	LCD_CTR	|= (1 << LCD_EN);
	_delay_ms(5);
	LCD_CTR	&= ~(1 << LCD_EN);
	_delay_ms(5);
}

void LCD_sendData(unsigned char data) {
	LCD_checkPointer();
	LCD_pointerPosition(pointerX, ++pointerY);
	LCD_DATA = data;
	
	LCD_CTR	|= (1 << LCD_RS);
	LCD_CTR	&= ~(1 << LCD_RW);
	LCD_CTR	|= (1 << LCD_EN);
	_delay_ms(5);
	LCD_CTR	&= ~(1 << LCD_EN);
	_delay_ms(5);
}

void LCD_sendString(unsigned char *str) {
	unsigned char i = 0;
	while (str[i] != '\0') {
		LCD_sendData(str[i]);
		i++;
	}
}

void LCD_pointerPosition(unsigned char x, unsigned char y) {
	unsigned char arr[] = {0x80, 0xC0};
	LCD_sendCmd(arr[x - 1] + y - 1);
}

void LCD_checkPointer(void) {
	if (pointerY == 16) {
		pointerY = 0;
		if (pointerX == 1) {
			pointerX = 2;
		} else if (pointerX == 2) {
			pointerX = 1;
		}
	}
}

void LCD_clear(void) {
	LCD_sendCmd(0x01);
	LCD_pointerPosition(1, 1);
}