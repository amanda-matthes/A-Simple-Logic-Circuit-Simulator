// A Simple Logic Circuit Simulator
// A project for PHYS 30762 Programming in C++
// Author           :   Amanda Matthes (10241789)
// Handed in on     :   12.May.2018
// This program starts in Main.h

#include "NotGate.h"

NotGate::NotGate() {
	componentType = NOT;
	c = '!';
}
bool NotGate::getState() const { endProgram("You can't do this with this component"); return false; }
void NotGate::flip() { endProgram("You can't do this with this component"); }
void NotGate::setLED(bool newState) { endProgram("You can't do this with this component"); }
bool NotGate::outputDefined() { endProgram("You can't do this with this component"); return false; }
bool NotGate::getOutput() { endProgram("You can't do this with this component"); return false; }
bool NotGate::upperInputDefined() { endProgram("You can't do this with this component"); return false; }
bool NotGate::lowerInputDefined() { endProgram("You can't do this with this component"); return false; }
void NotGate::setUpperInput(bool newValue) { endProgram("You can't do this with this component"); }
void NotGate::setLowerInput(bool newValue) { endProgram("You can't do this with this component"); }
void NotGate::resetGate() { endProgram("You can't do this with this component"); }