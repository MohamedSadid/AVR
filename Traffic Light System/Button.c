#include "Button.h"

void button_init() {
	GICR |= (1 << 6);
	MCUCR |= (1 << 1);
	MCUCR &= ~(1 << 0);
	sei();
}

unsigned char buttonStatus = 0;
ISR(INT0_vect) {
	if (buttonStatus == 0) {
		status = 2;
		GIFR |= (1 << 6);
		while ((PIND & 0x04) == 0);
		buttonStatus = 1;
	}
}