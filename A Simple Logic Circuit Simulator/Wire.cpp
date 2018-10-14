// A Simple Logic Circuit Simulator
// A project for PHYS 30762 Programming in C++
// Author           :   Amanda Matthes (10241789)
// Handed in on     :   12.May.2018
// This program starts in Main.h

#include "Wire.h"

Wire::Wire() {
	componentType = WIRE;
	c = '+';
}
bool Wire::getState() const { endProgram("You can't do this with this component"); return false; }
void Wire::flip() { endProgram("You can't do this with this component"); }
void Wire::setLED(bool newState) { endProgram("You can't do this with this component"); }
bool Wire::outputDefined() { endProgram("You can't do this with this component"); return false; }
bool Wire::getOutput() { endProgram("You can't do this with this component"); return false; }
bool Wire::upperInputDefined() { endProgram("You can't do this with this component"); return false; }
bool Wire::lowerInputDefined() { endProgram("You can't do this with this component"); return false; }
void Wire::setUpperInput(bool newValue) { endProgram("You can't do this with this component"); }
void Wire::setLowerInput(bool newValue) { endProgram("You can't do this with this component"); }
void Wire::resetGate() { endProgram("You can't do this with this component"); }