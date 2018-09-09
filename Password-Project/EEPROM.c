#include "EEPROM.h"
#include <avr/io.h>

void eeprom_init() {
	unsigned char add = 0x00;
	for (int i = 0; i < 15; i++) {
		eeprom_write(add, 'X');
		add++;
	}
}

void eeprom_write(unsigned char address, unsigned char data) {
	while ((EECR & 0x02) == 1);
	
	EEARH = 0x00;
	EEARL = address;
	EEDR = data;
	EECR |= (1 << EEMWE);
	EECR |= (1 << EEWE);
	_delay_ms(5);
}

unsigned char eeprom_read(unsigned char address) {
	while ((EECR & EEWE) == 1);
	
	EEARH = 0x00;
	EEARL = address;
	
	EECR |= (1 << EERE);
	
	return EEDR;
}