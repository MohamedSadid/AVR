/*
 * interrupt.c
 *
 * Created: 15-Jul-18 11:25:10 AM
 *  Author: USER
 */ 

#include "interrupt.h"
void initializePort() {
	DDRC = 0xFF;
	DDRD |= (1 << PIND2);
	PORTD |= (1 << PIND2);
}

void task1() {
	int i;
	PORTC |= (1 << PINC0);
	for (i = 0; i < 8; i++) {
		delay1();
		PORTC = (PORTC << 1);
	}
}

void delay1() {
	int i;
	TCNT0 = 0x00;
	TCCR0 = 0x04;
	
	for (i = 0; i < 6; i++) {
		while ((TIFR & (1 << TOV0)) == 0);
		
		TIFR |= (1 << TOV0);
	}
}

void task2() {
	GICR = (1 << INT0);
	sei();
}

ISR(INT0_vect) {
	int i;
	for (i = 0; i < 5; i++) {
		PORTC = 0xFF;
		delay2();
		PORTC = 0x00;
		delay2();
	}
}


void delay2() {
	int i;
	TCNT0 = 0x00;
	TCCR0 = 0x04;
	
	for (i = 0; i < 8; i++) {
		while ((TIFR & (1 << TOV0)) == 0);
		
		TIFR |= (1 << TOV0);
	}
}