#ifndef _GPIO_H_
#define _GPIO_H_

#include "Data_types.h"
#include "Delay.h"

// GPIO Registers //
#define PINA_R				(*((volatile unsigned char * const)0x39))
#define DDRA_R				(*((volatile unsigned char * const)0x3A))
#define PORTA_R				(*((volatile unsigned char * const)0x3B))
#define PINB_R				(*((volatile unsigned char * const)0x36))
#define DDRB_R				(*((volatile unsigned char * const)0x37))
#define PORTB_R				(*((volatile unsigned char * const)0x38))
#define PINC_R				(*((volatile unsigned char * const)0x33))
#define DDRC_R				(*((volatile unsigned char * const)0x34))
#define PORTC_R				(*((volatile unsigned char * const)0x35))
#define PIND_R				(*((volatile unsigned char * const)0x30))
#define DDRD_R				(*((volatile unsigned char * const)0x31))
#define PORTD_R				(*((volatile unsigned char * const)0x32))
// GPIO Registers //


// Input & Output Directions //
#define u8_Direction_input  0x00
#define u8_Direction_output 0xFF
// Input & Output Directions //


#define Init_Direction_default u8_Direction_input
#define No_Of_Pins 8


// Port Index //
u8 Get_Port_Index(u8);
// Port Index //


// Port Initialization //
void GPIO_Init(void);
// Port Initialization //


///////////////////////////////////////////////////////////
// CONCERNING PINS //
// Write Pin Direction //
u8 GPIO_WritePinDir(u8 pinIndex, u8 value, u8 portName);
// Write Pin Direction //


// Read Pin Direction //
u8 GPIO_ReadPinDir(u8 pinIndex, u8 *value, u8 portName);
// Read Pin Direction //


// Read Pin value //
u8 GPIO_ReadPinValue(u8 pinIndex, u8 *value, u8 portName);
// Read Pin value //


// Write Pin value //
u8 GPIO_WritePinValue(u8 pinIndex, u8 value, u8 portName);
// Write Pin value //
// CONCERNING PINS //
///////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////
// CONCERNING PORTS //
// Read PORT value //
u8 GPIO_ReadPortValue(u8 *value, u8 portName);
// Read PORT value //


// Write PORT value //
u8 GPIO_WritePortValue(u8 value, u8 portName);
// Write PORT value //


// Read PORT Direction //
u8 GPIO_ReadPortDir(u8 *value, u8 portName);
// Read PORT Direction //


// Write PORT Direction //
u8 GPIO_WritePortDir(u8 value, u8 portName);
// Write PORT Direction //
// CONCERNING PORTS //
///////////////////////////////////////////////////////////
#endif