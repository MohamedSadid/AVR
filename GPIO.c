#include "GPIO.h"

u8 *GPIO_Ports[] = {&PORTA_R, &PORTB_R, &PORTC_R, &PORTD_R}; 
u8 *GPIO_DDR[] = {&DDRA_R, &DDRB_R, &DDRC_R, &DDRD_R};
u8 *GPIO_Pins[] = {&PINA_R, &PINB_R, &PINC_R, &PIND_R};


// DDR Initialization //
void GPIO_Init(void) {
	// initialize all the ports by default to be input //
	*GPIO_DDR[0] = Init_Direction_default;
	*GPIO_DDR[1] = Init_Direction_default;
	*GPIO_DDR[2] = Init_Direction_default;
	*GPIO_DDR[3] = Init_Direction_default;
}
// DDR Initialization //


// Get Port Index //
u8 Get_Port_Index(u8 Port_Name) {
	int i;
	
	switch(Port_Name) {
		case('A'):
		case('a'):
			i = 0;
			break;
		
		case('B'):
		case('b'):
			i = 1;
			break;
		
		case('C'):
		case('c'):
			i = 2;
			break;
		
		case('D'):
		case('d'):
			i = 3;
	};
	return i;
}
// Get Port Index //


///////////////////////////////////////////////////////////
// CONCERNING PINS //
// Read Pin value //
u8 GPIO_ReadPinValue(u8 pinIndex, u8 *value, u8 portName) {
	
	u8 status; // flag indicating the status if the used entered wrong index //
	
	if (pinIndex > (No_Of_Pins - 1)) {
		status = Error;
	} else {
		
		*value = (((*GPIO_Pins[Get_Port_Index(portName)]) >> pinIndex) & 0x01);
		status = No_Error;
	}
	
	return status;
	
}
// Read Pin value //


// Write Pin Value //
u8 GPIO_WritePinValue(u8 pinIndex, u8 value, u8 portName) {
	u8 status;
	
	if (pinIndex > (No_Of_Pins - 1)) {
		status = Error;
	} else {
		switch(value) {
			case(1):
				*GPIO_Ports[Get_Port_Index(portName)] |= (1 << pinIndex);
				break;
			case(0):
				*GPIO_Ports[Get_Port_Index(portName)] &= ~(1 << pinIndex);
				break;
			default:
				status = No_Error;
		};
	}
	
	return status;
}
// Write Pin Value //


// Write Pin Direction //
u8 GPIO_WritePinDir(u8 pinIndex, u8 value, u8 portName) {
	u8 status;
	
	if (pinIndex > (No_Of_Pins - 1)) {
		status = Error;
	} else {
		switch(value) {
			case(1):
				*GPIO_DDR[Get_Port_Index(portName)] |= (1 << pinIndex);
				break;
			
			case(0):
				*GPIO_DDR[Get_Port_Index(portName)] &= ~(1 << pinIndex);
				break;
			
			default:
				status = Error;
		};
	}
	return status;
}
// Write Pin Direction //


// Read Pin Direction //
u8 GPIO_ReadPinDir(u8 pinIndex, u8 *value, u8 portName) {
	u8 status;
	
	if (pinIndex > (No_Of_Pins - 1)) {
		status = Error;
	} else {
		*value = (((*GPIO_DDR[Get_Port_Index(portName)]) >> pinIndex) & 0x01);
		status = No_Error;
	}
	
	return status;
}
// Read Pin Direction //
// CONCERNING PINS //
///////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////
// CONCERNING PORTS //
// Read Port value //
u8 GPIO_ReadPortValue(u8 *value, u8 portName) {
	
	*value = *GPIO_Pins[Get_Port_Index(portName)];
	return No_Error;
}
// Read Port value //


// Write PORT value //
u8 GPIO_WritePortValue(u8 value, u8 portName) {
	*GPIO_Ports[Get_Port_Index(portName)] = value;
	return No_Error;
}
// Write PORT value //


// Read PORT Direction //
u8 GPIO_ReadPortDir(u8 *value, u8 portName) {
	*value = *GPIO_DDR[Get_Port_Index(portName)];
	return No_Error;
}
// Read PORT Direction //


// Write PORT Direction //
u8 GPIO_WritePortDir(u8 value, u8 portName) {
	*GPIO_DDR[Get_Port_Index(portName)] = value;
	return No_Error;
}
// Write PORT Direction //
// CONCERNING PORTS //
///////////////////////////////////////////////////////////