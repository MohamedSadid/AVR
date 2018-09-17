#define F_CPU 1000000UL

#include "LCD.h"
#include <avr/interrupt.h>

void LED_init();
void LED_toggle();
void UART_init();

int main(void)
{
	LED_init();
	UART_init();
	LCD_init();
	unsigned char recData;
	
	while(1)
	{
		while ((UCSRA & (1 << RXC)) == 0);
		recData = UDR;
		LCD_sendData(recData);
		if (recData == 'S') {
			LED_toggle();
		}
	}
}


void LED_init() {
	DDRB |= (1 << 3);
}

void LED_toggle() {
	PORTB |= (1 << 3);
	_delay_ms(250);
	PORTB &= ~(1 << 3);
	_delay_ms(250);
}




void UART_init() {
	
	// Baud Rate is 9600bps (F_CPU = 8MHZ) //
	UBRRH &= ~(1 << URSEL);
	UBRRH &= ~((1 << 0) | (1 << 1) | (1 << 2));
	UBRRL = 52;
	// Baud Rate is 9600bps (F_CPU = 8MHZ) //
	
	// UART Control Status Registers //
	UCSRC |= (1 << URSEL);		// enable writing to UCSRC //
	UCSRC &= ~(1 << UMSEL);		// mode selection (asynchronous operation) //
	UCSRC &= ~(1 << UPM1);		// disabling parity //
	UCSRC &= ~(1 << UPM0);		// disabling parity //
	UCSRC |= (1 << USBS);		// 2 stop bits //
	UCSRC |= (1 << UCSZ0);		// sent character size (8bits) //
	UCSRC |= (1 << UCSZ1);		// sent character size (8bits) //
	
	UCSRB &= ~(1 << RXCIE);		// disabling RX interrupt //
	UCSRB &= ~(1 << TXCIE);		// disabling TX interrupt //
	UCSRB &= ~(1 << UDRIE);		// disabling UDR interrupt //
	UCSRB |= (1 << RXEN);		// enabling RX interrupt //
	UCSRB &= ~(1 << TXEN);		// disabling TX interrupt //
	UCSRB &= ~(1 << UCSZ2);		// sent character size (8bits) //
	// UART Control Status Registers //
}