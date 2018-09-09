#ifndef _BUTTON_H_
#define _BUTTON_H_

#include <avr/io.h>
#include "lightsys.h"

extern unsigned char peopleCount;

void button_init();
void button_check();
void checkButton1();
void checkButton2();
#endif