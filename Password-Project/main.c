#include "LCD.h"
#include "keypad.h"
#include "password.h"
#include "EEPROM.h"

int main(void)
{
	lcd_init();
	keypad_init();
	resetPassword();
	startup();
    while(1) {
		
		if (isalpha(eeprom_read(0x06))) {
			passwordFirstEntry();
			scan1();
		} else if (eeprom_read(0x06) == '#') {
			reenterPassword();
			scan2();
			if (eeprom_read(0x0D) == '#') {
				checkPassword();
			}
		} else if (eeprom_read(0x06) != '#') {
			invalid();
		}
		
    }
}

ISR (INT0_vect) {
	lcd_send_cmd(0x01);
	eeprom_init();
	lcd_send_string("Please Restart");
	while(1);
}