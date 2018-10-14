// A Simple Logic Circuit Simulator
// A project for PHYS 30762 Programming in C++
// Author           :   Amanda Matthes (10241789)
// Handed in on     :   12.May.2018
// This program starts in Main.h

#include "GlobalVariables.h"

bool isGate(type t) {
	if (t == AND || t == OR) {
		return true;
	}
	return false;
}

void endProgram(string message) {
	cout << "\n" << message << endl << "Program ended. Please close this window. \n";
	while (true) {};	// keeps the window open
}
