#include "SPI_TX.h"

void SPI_TX_init() {
	DDRC = 0xFF;
	// Master Configurations //
	DDRB |= (1 << TX_SS);			// Slave select is an output //
	DDRB |= (1 << TX_MOSI);			// Master Out Slave In is an output //
	DDRB &= ~(1 << TX_MISO);		// Master In Slave Out  is an input //
	DDRB |= (1 << TX_SCK);			// Serial Clock is an output //
	
	// Important Note >> Follow the sequence (enabling the SPI protocol it the last step) //
	SPCR &= ~(1 << SPIE);			// Disabling SPI protocol Interrupt //
	SPCR &= ~(1 << SPR1);			// Scaling frequency [F(ocs) / 16] //
	SPCR |= (1 << SPR0);			// Scaling frequency [F(ocs) / 16] //
	SPCR &= ~(1 << CPOL);			// Non-inverting clock //
	SPCR |= (1 << CPHA);			// Sampling is on the second clock edge //
	SPCR &= ~(1 << DORD);			// Data Order -> MSB is transmitted first //
	SPCR |= (1 << MSTR);			// Enabling Master Mode //
	SPCR |= (1 << SPE);				// Enabling SPI protocol //
	
	SPSR &= ~(1 << SPIF);				// Scaling frequency [F(ocs) / 16] //
	SPSR &= ~(1 << WCOL);
	SPSR &= ~(1 << SPI2X);
	// Master Configurations //
	
	_delay_ms(200);
}

unsigned char data;

void SPI_TX_Transmit() {
	PORTB |= (1 << TX_SS);
	SPI_Write(0x80);
	
	SPI_Write(0x00);
	PORTB &= ~(1 << TX_SS);
	_delay_ms(200);
	
	PORTB |= (1 << TX_SS);
	SPI_Write(0x02);
	
	SPI_Write(0xFF);
	PORTC = SPI_Read();
	PORTB &= ~(1 << TX_SS);
}

unsigned char SPI_Read() {
	while((SPSR & (1 << SPIF)) == 0);
	return SPDR;
}

void SPI_Write(unsigned char data) {
	SPDR = data;
	while((SPSR & (1 << SPIF)) == 0);
}

int convertBinaryToDecimal(int n) {
	int decimalNumber = 0, i = 0, remainder;
	while (n != 0) {
		remainder = n % 10;
		n /= 10;
		decimalNumber += remainder * pow(2,i);
		i++;
	}
	return decimalNumber;
}
