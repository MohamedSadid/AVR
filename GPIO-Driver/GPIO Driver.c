#include "GPIO.h"
int main(void)
{
	
	u8 x;
	GPIO_WritePortDir(0x00, 'A');
	GPIO_WritePortDir(0xFF, 'B');
    while(1)
    {
		GPIO_ReadPortValue(&x, 'A');
		GPIO_WritePortValue(x, 'B');
    }
}