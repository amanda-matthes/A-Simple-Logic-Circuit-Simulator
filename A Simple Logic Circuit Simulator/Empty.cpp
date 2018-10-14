// A Simple Logic Circuit Simulator
// A project for PHYS 30762 Programming in C++
// Author           :   Amanda Matthes (10241789)
// Handed in on     :   12.May.2018
// This program starts in Main.h

#include "Empty.h"

Empty::Empty() {
	componentType = EMPTY;
	c = ' ';					// an empty cell is invisible
}
bool Empty::getState() const { endProgram("You can't do this with this component"); return false; }
void Empty::flip() { endProgram("You can't do this with this component"); }
void Empty::setLED(bool newState) { endProgram("You can't do this with this component"); }
bool Empty::outputDefined() { endProgram("You can't do this with this component"); return false; }
bool Empty::getOutput() { endProgram("You can't do this with this component"); return false; }
bool Empty::upperInputDefined() { endProgram("You can't do this with this component"); return false; }
bool Empty::lowerInputDefined() { endProgram("You can't do this with this component"); return false; }
void Empty::setUpperInput(bool newValue) { endProgram("You can't do this with this component"); }
void Empty::setLowerInput(bool newValue) { endProgram("You can't do this with this component"); }
void Empty::resetGate() { endProgram("You can't do this with this component"); }
