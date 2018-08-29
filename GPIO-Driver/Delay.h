#ifndef _DELAY_H_
#define _DELAY_H_

#include "Data_Types.h"

#define clock 1000000
#define error_rate 30

u32 timedelay;

#define DELAY_MS(x) \
			for (timedelay = ((clock / 1000) * x) / 30; timedelay > 0; timedelay--) {\
				__asm("NOP");\
			}
#endif
