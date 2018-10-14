// A Simple Logic Circuit Simulator
// A project for PHYS 30762 Programming in C++
// Author           :   Amanda Matthes (10241789)
// Handed in on     :   12.May.2018
// This program starts in Main.h

/*
The AndGate class is derived from TwoInputGate
The output of an AND gate is true iff both inputs are true
The symbol for an AND gate is &
Its componentType is AND
*/

#ifndef ANDGATE_H
#define ANDGATE_H

#include "TwoInputGate.h"

class AndGate : public TwoInputGate {
public:
	AndGate();				
	bool getOutput();		
};

#endif