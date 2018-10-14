// A Simple Logic Circuit Simulator
// A project for PHYS 30762 Programming in C++
// Author           :   Amanda Matthes (10241789)
// Handed in on     :   12.May.2018
// This program starts in Main.h

/*
The OrGate class is derived from TwoInputGate
The output of an OR gate is false iff both inputs are false
The symbol for an OR gate is |
Its componentType is OR
*/

#ifndef ORGATE_H
#define ORGATE_H

#include "TwoInputGate.h"

class OrGate : public TwoInputGate {
public:
	OrGate();
	bool getOutput();
};

#endif