#include "lightsys.h"

void light_init() {
	DDRD |= (1 << 7);	
}

void light_it(float dutyCycle) {
	if (dutyCycle >= 0) {
		OCR2 = (dutyCycle / 100.0) * 255.0;
	}
	
	TCCR2 |= (1 << 0) | (1 << 3) | (1 << 5) | (1 << 6);
}
