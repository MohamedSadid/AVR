#ifndef _TIMER0_H_
#define _TIMER0_H_

#include "avr/interrupt.h"
#define F_CPU 1000000UL

extern unsigned char status;
void timer0_init();
#endif