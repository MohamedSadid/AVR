#include "button.h"
#include "Timer.h"
#include "lightsys.h"

int main(void)
{
	DDRC |= (1 << 0);
	light_init();
	button_init();
	timer_init();
	timer1_init();
    while(1)
    {
    }
	
}
