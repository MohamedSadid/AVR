/*
 * interrupts_task.c
 *
 * Created: 15-Jul-18 11:21:16 AM
 *  Author: USER
 */ 

#include "interrupt.h"
int main(void)
{
	initializePort();
	task2();
	
	while (1) {
		task1();
	}
}