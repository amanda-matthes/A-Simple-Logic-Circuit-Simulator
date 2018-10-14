// A Simple Logic Circuit Simulator
// A project for PHYS 30762 Programming in C++
// Author           :   Amanda Matthes (10241789)
// Handed in on     :   12.May.2018
// This program starts in Main.h

#include "OrGate.h"

OrGate::OrGate() {
	componentType = OR;
	upperInputSet = false;
	lowerInputSet = false;
	c = '|';
}
bool OrGate::getOutput() {
	if (!outputDefined()) {
		endProgram("Gate input is invalid");
	}
	return (upperInput || lowerInput);
}