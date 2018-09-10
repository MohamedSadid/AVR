#include "LED.h"

void led_init() {
	LED |= (1 << RED);
	LED |= (1 << YELLOW);
	LED |= (1 << GREEN);
}