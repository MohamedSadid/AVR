#ifndef _KEYPAD_H_
#define _KEYPAD_H_


#define padDir DDRC
#define padData PORTC
#define padInp PINC

void keypad_init();
void scan1();
void scan2();
void scanRow1();
void scanRow2();
void scanRow3();
void scanRow4();
#endif