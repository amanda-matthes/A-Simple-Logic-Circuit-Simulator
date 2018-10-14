// A Simple Logic Circuit Simulator
// A project for PHYS 30762 Programming in C++
// Author           :   Amanda Matthes (10241789)
// Handed in on     :   12.May.2018
// This program starts in Main.h

#include "Input.h"

Input::Input(bool INPUTstate) {
	componentType = INPUT;
	state = INPUTstate;
	if (state == true) {
		c = '1';
	}
	else {
		c = '0';
	}
}
void Input::setLED(bool newState) { 
	endProgram("You can't do this with this component"); 
}