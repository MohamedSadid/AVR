#include "button.h"

void button_init() {
	DDRA |= (1 << 0);
	DDRA |= (1 << 1);
	DDRA &= ~(1 << 2);
	DDRA &= ~(1 << 3);
	
	PORTA &= ~(1 << 0);
	PORTA &= ~(1 << 1);
	PORTA |= (1 << 2);
	PORTA |= (1 << 3);
}

void button_check() {
	if ((PINA & 0x04) == 0) {
		checkButton1();
		while ((PINA & 0x04) == 0);
	} else if ((PINA & 0x08) == 0) {
		checkButton2();
		while ((PINA & 0x08) == 0);
	}
	
}

unsigned char peopleCount = 0;
void checkButton1() {
	peopleCount++;
	if (peopleCount >= 100) peopleCount = 0;
}

void checkButton2() {
	peopleCount--;
	if (peopleCount == 255) {
		peopleCount = 0;
	}
}