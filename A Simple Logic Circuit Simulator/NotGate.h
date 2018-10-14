// A Simple Logic Circuit Simulator
// A project for PHYS 30762 Programming in C++
// Author           :   Amanda Matthes (10241789)
// Handed in on     :   12.May.2018
// This program starts in Main.h

/*
The NotGate class is derived from Component
The NOT gate flips the state of the input
The symbol for a NOT gate is !
Its componentType is NOT
*/

#ifndef NOTGATE_H
#define NOTGATE_H

#include "Component.h"

class NotGate : public Component {
public:
	NotGate();

	// These all should never be called and end the program:
	bool getState() const;
	void flip();
	void setLED(bool newState);
	bool outputDefined();
	bool getOutput();
	bool upperInputDefined();
	bool lowerInputDefined();
	void setUpperInput(bool newValue);
	void setLowerInput(bool newValue);
	void resetGate();
};

#endif