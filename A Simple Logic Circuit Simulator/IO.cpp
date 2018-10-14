// A Simple Logic Circuit Simulator
// A project for PHYS 30762 Programming in C++
// Author           :   Amanda Matthes (10241789)
// Handed in on     :   12.May.2018
// This program starts in Main.h

#include "IO.h"

bool IO::getState() const {
	return state;
}
void IO::flip() {
	if (state == true) { state = false; c = '0'; }
	else { state = true; c = '1'; }
}

bool IO::outputDefined() { endProgram("You can't do this with this component"); return false; }
bool IO::getOutput() { endProgram("You can't do this with this component"); return false; }
bool IO::upperInputDefined() { endProgram("You can't do this with this component"); return false; }
bool IO::lowerInputDefined() { endProgram("You can't do this with this component"); return false; }
void IO::setUpperInput(bool newValue) { endProgram("You can't do this with this component"); }
void IO::setLowerInput(bool newValue) { endProgram("You can't do this with this component"); }
void IO::resetGate() { endProgram("You can't do this with this component"); }