// A Simple Logic Circuit Simulator
// A project for PHYS 30762 Programming in C++
// Author           :   Amanda Matthes (10241789)
// Handed in on     :   12.May.2018
// This program starts in Main.h

/*
Component acts as an abstract base class for components
Its members are bool c (a symbol used to display the component in the console)
and type componentType (which tags the component with its type)
*/

#ifndef COMPONENT_H
#define COMPONENT_H

#include "GlobalVariables.h"

class Component {	// abstract base class
protected:
	char c;					// used to display the component on grids
	type componentType;		// tags the component with its type
public:
	// Getters:
	char getC() const;
	type getType() const;

	// Virtual functions:
	virtual bool getState() const = 0;
	virtual void flip() = 0;
	virtual void setLED(bool newState) = 0;
	virtual bool outputDefined() = 0;
	virtual bool getOutput() = 0;
	virtual bool upperInputDefined() = 0;
	virtual bool lowerInputDefined() = 0;
	virtual void setUpperInput(bool newValue) = 0;
	virtual void setLowerInput(bool newValue) = 0;
	virtual void resetGate() = 0;
};

#endif