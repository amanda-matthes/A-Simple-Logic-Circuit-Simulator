// A Simple Logic Circuit Simulator
// A project for PHYS 30762 Programming in C++
// Author           :   Amanda Matthes (10241789)
// Handed in on     :   12.May.2018
// This program starts in Main.h

/*
IO is an abstract base class derived from Component.
Input and Output are derived from it.
IO components have the additional member bool state
which holds the logical state of the component.
*/

#ifndef IO_H
#define IO_H

#include "Component.h"

class IO : public Component {
protected:
	bool state;
public:
	bool getState() const;
	void flip();			// flips the state

	virtual void setLED(bool newState) = 0;

	// These should never be called for an IO component and end the program:
	bool outputDefined();
	bool getOutput();
	bool upperInputDefined();
	bool lowerInputDefined();
	void setUpperInput(bool newValue);
	void setLowerInput(bool newValue);
	void resetGate();
};


#endif