#ifndef _PASSWORD_H_
#define _PASSWORD_H_

#include <avr/interrupt.h>

void startup();
void passwordFirstEntry();
void reenterPassword();
void invalid();
void valid();
void checkPassword();
void resetPassword();
#endif