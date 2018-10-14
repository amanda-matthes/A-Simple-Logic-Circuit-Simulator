// A Simple Logic Circuit Simulator
// A project for PHYS 30762 Programming in C++
// Author           :   Amanda Matthes (10241789)
// Handed in on     :   12.May.2018
// This program starts in Main.h

/*
The abstract TwoInputGate class is derived from Component
AndGate and OrGate are derived from it.
It has the additional members 
upperInputSet, lowerInputSet
(which get set during the rendering of a board and
are true if a input is provided on that side)
and 
upperInput and lowerInput
(which hold the inputs provided by rendering)
*/

#ifndef TWOINPUT_H
#define TWOINPUT_H

#include "Component.h"

class TwoInputGate : public Component { // abstract base class
protected:
	bool upperInputSet;			// is true if the upper input is defined
	bool upperInput;
	bool lowerInputSet;
	bool lowerInput;
public:
	bool outputDefined();			// true if both upperInputSet and lowerInputSet are true
	void resetGate();				// resets upperInputSet and lowerInputSet
	
	// Setters:
	void setUpperInput(bool newValue);
	void setLowerInput(bool newValue);
	
	// Getters:
	bool upperInputDefined();
	bool lowerInputDefined();

	// This depends on the type of gate:
	virtual bool getOutput() = 0;

	// These should never be called and end the program:
	bool getState() const;
	void flip();
	void setLED(bool newState);
};

#endif