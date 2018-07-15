/*
 * interrupt.h
 *
 * Created: 15-Jul-18 11:25:21 AM
 *  Author: USER
 */ 

#ifndef _INTERRUPT_H_
#define _INTERRUPT_H_

#include <avr/io.h>

#ifndef F_CPU
#define F_CPU 1000000
#endif

#include <util/delay.h>
#include <avr/interrupt.h>

void initializePort();
void task1();
void delay1();

void task2();
void delay2();
#endif