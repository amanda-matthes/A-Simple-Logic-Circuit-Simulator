// A Simple Logic Circuit Simulator
// A project for PHYS 30762 Programming in C++
// Author           :   Amanda Matthes (10241789)
// Handed in on     :   12.May.2018
// This program starts in Main.h

/*
The Empty class is derived from Component.
It formally is a component but its member functions should never be called.
Its componentType is EMPTY
*/

#ifndef EMPTY_H
#define EMPTY_H

#include "Component.h"

class Empty : public Component {
public:
	Empty();

	// These all should never be called and end the program if they are
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