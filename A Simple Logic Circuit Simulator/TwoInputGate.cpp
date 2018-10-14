// A Simple Logic Circuit Simulator
// A project for PHYS 30762 Programming in C++
// Author           :   Amanda Matthes (10241789)
// Handed in on     :   12.May.2018
// This program starts in Main.h

#include "TwoInputGate.h"

bool TwoInputGate::outputDefined() {	// returns true if the output is defined
	if (upperInputSet && lowerInputSet) {
		return true;
	}
	return false;
}
bool TwoInputGate::upperInputDefined() {
	return upperInputSet;
}
bool TwoInputGate::lowerInputDefined() {
	return lowerInputSet;
}
void TwoInputGate::setUpperInput(bool newValue) {
	upperInput = newValue;
	upperInputSet = true;
}
void TwoInputGate::setLowerInput(bool newValue) {
	lowerInput = newValue;
	lowerInputSet = true;
}
void TwoInputGate::resetGate() {	// resets upperInputSet and lowerInputSet
	upperInputSet = false;
	lowerInputSet = false;
}

bool TwoInputGate::getState() const { endProgram("You can't do this with this component"); return false; }
void TwoInputGate::flip() { endProgram("You can't do this with this component"); }
void TwoInputGate::setLED(bool newState) { endProgram("You can't do this with this component"); }