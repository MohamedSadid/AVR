#include "LED.h"
#include "Button.h"
#include "Timer0.h"

int main(void)
{	
	led_init();
	timer0_init();
	button_init();
    while(1)
    {
        //TODO:: Please write your application code 
    }
}