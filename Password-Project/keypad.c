#include "keypad.h"
#include "LCD.h"
#include "EEPROM.h"

void keypad_init() {
	padDir = 0x0F;
}

static unsigned char baseAddress = 0x00;
unsigned char pointerY = 1;

void scan1() {
	if (baseAddress < 0x07) {
		padData = 0xF0;
		
		if (padInp != 0xF0) {
			scanRow1();
			scanRow2();
			scanRow3();
			scanRow4();
		}
	}
	
}

void scan2() {
	if (baseAddress == 0 || baseAddress == 14) {
		baseAddress = 0x07;
		eeprom_write(0x0D, 'X');
	}
	if (baseAddress == 0x07) pointerY = 1;
	padData = 0xF0;
	
	if (padInp != 0xF0) {
		scanRow1();
		scanRow2();
		scanRow3();
		scanRow4();
	}
}

void scanRow1() {
	padData = 0b11111110;
	
	if ((padInp & 0x10) == 0) { // *  //
		pointer_position(2, --pointerY);
		baseAddress--;
		while ((padInp & 0x10) == 0);
	} else if ((padInp & 0x20) == 0) {
		pointer_position(2, pointerY++);
		eeprom_write(baseAddress++, '0');
		while ((padInp & 0x20) == 0);
		lcd_send_string("0");
	} else if ((padInp & 0x40) == 0) {
		pointer_position(2, pointerY++);
		eeprom_write(baseAddress++, '#');
		while ((padInp & 0x40) == 0); // # //
		_delay_ms(50);
		lcd_send_cmd(0x01);
		lcd_send_string("DONE!");
		_delay_ms(2000);
		lcd_send_cmd(0x01);
	}
}

void scanRow2() {
	padData = 0b11111101;
	
	if ((padInp & 0x10) == 0) {
		pointer_position(2, pointerY++);
		eeprom_write(baseAddress++, '7');
		while ((padInp & 0x10) == 0);
		lcd_send_string("7");
	} else if ((padInp & 0x20) == 0) {
		pointer_position(2, pointerY++);
		eeprom_write(baseAddress++, '8');
		while ((padInp & 0x20) == 0);
		lcd_send_string("8");
	} else if ((padInp & 0x40) == 0) {
		pointer_position(2, pointerY++);
		eeprom_write(baseAddress++, '9');
		while ((padInp & 0x40) == 0);
		lcd_send_string("9");
	}
}

void scanRow3() {
	padData = 0b11111011;
	
	if ((padInp & 0x10) == 0) {
		pointer_position(2, pointerY++);
		eeprom_write(baseAddress++, '4');
		while ((padInp & 0x10) == 0);
		lcd_send_string("4");
	} else if ((padInp & 0x20) == 0) {
		pointer_position(2, pointerY++);
		eeprom_write(baseAddress++, '5');
		while ((padInp & 0x20) == 0);
		lcd_send_string("5");
	} else if ((padInp & 0x40) == 0) {
		pointer_position(2, pointerY++);
		eeprom_write(baseAddress++, '6');
		while ((padInp & 0x40) == 0);
		lcd_send_string("6");
	}
}

void scanRow4() {
	padData = 0b11110111;
	
	if ((padInp & 0x10) == 0) {
		pointer_position(2, pointerY++);
		eeprom_write(baseAddress++, '1');
		while ((padInp & 0x10) == 0);
		lcd_send_string("1");
	} else if ((padInp & 0x20) == 0) {
		pointer_position(2, pointerY++);
		eeprom_write(baseAddress++, '2');
		while ((padInp & 0x20) == 0);
		lcd_send_string("2");
	} else if ((padInp & 0x40) == 0) {
		pointer_position(2, pointerY++);
		eeprom_write(baseAddress++, '3');
		while ((padInp & 0x40) == 0);
		lcd_send_string("3");
	}
}