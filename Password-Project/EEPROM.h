#ifndef _EEPROM_H_
#define _EEPROM_H_

#define F_CPU 1000000UL
#include <util/delay.h>

void eeprom_write(unsigned char address, unsigned char data);
unsigned char eeprom_read(unsigned char address);
void eeprom_init();
#endif