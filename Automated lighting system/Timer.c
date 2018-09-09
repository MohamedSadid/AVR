#include "Timer.h"
#include "button.h"

void timer_init() {
	
	TCNT0 = 0x9E;
	TCCR0 = 0x05;
	TIMSK |= (1 << TOIE0);
	sei();
}

void timer1_init() {
	TCNT1L = 0xB0;
	TCNT1H = 0x3C;
	TCCR1A = 0x00;
	TCCR1B = 0x01;
	TIMSK |= (1 << TOIE1);
	sei();
}

unsigned char limit = 0;
ISR(TIMER0_OVF_vect) {
	limit++;
	if (limit < 5) {
		button_check();
	} else if (limit >= 5) {
		limit = 0;
	}
	TCNT0 = 0x9E;
}

ISR(TIMER1_OVF_vect) {
	light_it(peopleCount);
}
