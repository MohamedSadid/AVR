#ifndef _LED_H_
#define _LED_H_

#define LED		DDRC
#define LITLED	PORTC
#define RED		PINC0
#define YELLOW  PINC1
#define GREEN   PINC2

#include <avr/io.h>

void led_init();
#endif