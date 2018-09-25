#include "SPI_TX.h"
int main(void)
{
	SPI_TX_init();
	LCD_init();
	while (1) {
		SPI_TX_Transmit();
	}
}
