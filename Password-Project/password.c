#include "password.h"
#include "LCD.h"

// startup Welcome message //
unsigned char welcomeFlag = 0;
void startup() {
	if (welcomeFlag == 0) {
		pointer_position(1, 6);
		lcd_send_string("Welcome");
		_delay_ms(2000);
		lcd_send_cmd(0x01);
		welcomeFlag = 1;
	}
}
// startup Welcome message //


// 1st password is entered //
unsigned char passFlag = 0;
void passwordFirstEntry() {
	if (passFlag == 0) {
		lcd_send_string("Enter Password:");
		passFlag = 1;
	}
}
// 1st password is entered //


// reenter password function //
unsigned char reenterPassFlag = 0;
void reenterPassword() {
	if (reenterPassFlag == 0) {
		lcd_send_cmd(0x01);
		lcd_send_string("Reenter Password:");
		reenterPassFlag = 1;
	}
}
// reenter password function //

// Display invalid function //
unsigned char invalidFlag = 0;
void invalid() {
	if (invalidFlag == 0) {
		lcd_send_cmd(0x01);
		lcd_send_string("Invalid !");
		invalidFlag = 1;
	}
}
// Display invalid function //

// Check Password function //
void checkPassword() {
	unsigned char j = 0x00;
	unsigned char i;
	unsigned char count = 0;
	for (i = 0x07; i < 0x0D; i++) {
		
		if (eeprom_read(j) == eeprom_read(i)) {
			count++;
		}
		j++;	
	}
	if (count == 6) {
		valid();
	} else if (count != 6) {
		invalid();
	}
}
// Check Password function //


// valid function //
unsigned char validFlag = 0;
void valid() {
	if (validFlag == 0) {
		lcd_send_cmd(0x01);
		lcd_send_string("Valid Password");
		validFlag = 1;	
	}
}
// valid function //


// Reset Password //
void resetPassword() {
	GICR |= (1 << 6);
	MCUCR |= (1 << 1);
	MCUCR &= ~(1 << 0);
	sei();
}
// Reset Password //
