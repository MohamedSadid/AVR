#include "Timer0.h"
#include "LED.h"
#include "Button.h"

void timer0_init() {
	TCNT0 = 0x0E;
	TCCR0 = 0x05;
	TIMSK |= (1 << 0);
	sei();
}

unsigned char status = 0;
unsigned char times = 0;
ISR(TIMER0_OVF_vect) {
	
	switch (status) {
		case(0):
			if ((times == 0) || (times == 28)) {
				buttonStatus = 1;
				LITLED &= ~(1 << YELLOW | 1 << GREEN);
				LITLED |= (1 << RED);
				buttonStatus = 0;
				times = 0;
				status = 1;
			}
			break;
			
		case(1):
			if (times == 16) {
				buttonStatus = 1;
				LITLED &= ~(1 << RED | 1 << GREEN);
				LITLED |= (1 << YELLOW);
				buttonStatus = 0;
				times = 0;
				status = 2;
			}
			break;
			
		case(2):
			if (times == 12) {
				LITLED &= ~(1 << RED | 1 << YELLOW);
				LITLED |= (1 << GREEN);
				buttonStatus = 1;
				times = 0;
				status = 0;
			}
			break;
			
		default:
			LITLED |= (1 << RED) | (1 << YELLOW) | (1 << GREEN);
	};
	
	times++;
	TCNT0 = 0x0E;
}