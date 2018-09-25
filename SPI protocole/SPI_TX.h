#ifndef _SPI_TX_H_
#define _SPI_TX_H_

#include <avr/io.h>
#include <util/delay.h>
#define F_CPU 8000000UL

#define TX_SS		PB4
#define TX_MOSI		PB5
#define TX_MISO		PB6
#define TX_SCK		PB7

void SPI_TX_init();
void SPI_TX_Transmit();
unsigned char SPI_Read();
void SPI_Write(unsigned char data);
int convertBinaryToDecimal(int n);
#endif