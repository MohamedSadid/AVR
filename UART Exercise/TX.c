#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

void LED_init();
void LED_toggle();
void BUT_init();
void BUT_check();
void UART_init();

int main(void)
{	
	LED_init();
	BUT_init();
	UART_init();
	
    while(1)
    {
		BUT_check();
    }
}


void LED_init() {
	DDRB |= (1 << 0);
}



void LED_toggle() {
	PORTB ^= (1 << 0);
}

void BUT_init() {
	DDRB |= (1 << 1);
	DDRB &= ~(1 << 2);
	PORTB |= (1 << 2);
	PORTB &= ~(1 << 1);
}

void BUT_check() {
	unsigned char i;
	unsigned char dataSend[] = {'Y', 'E', 'S'};
	if ((PINB & (1 << 2)) == 0) {
		for (i = 0; i < 3; i++) {
			while ((UCSRA & (1 << UDRE)) == 0);
			UDR = dataSend[i];
		}
		LED_toggle();
		while ((PINB & (1 << 2)) == 0);
	}
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
	UCSRB &= ~(1 << RXEN);		// disabling RX interrupt //
	UCSRB |= (1 << TXEN);		// enabling TX interrupt //
	UCSRB &= ~(1 << UCSZ2);		// sent character size (8bits) //
	// UART Control Status Registers //
}