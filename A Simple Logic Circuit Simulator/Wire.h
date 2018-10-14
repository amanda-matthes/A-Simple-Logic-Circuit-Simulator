// A Simple Logic Circuit Simulator
// A project for PHYS 30762 Programming in C++
// Author           :   Amanda Matthes (10241789)
// Handed in on     :   12.May.2018
// This program starts in Main.h

/*
The Wire class is derived from Component
The symbol for a wire is + 
Its componentType is WIRE
*/

#ifndef WIRE_H
#define WIRE_H

#include "Component.h"

class Wire : public Component {
public:
	Wire();

	// These should never be called and end the program:
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