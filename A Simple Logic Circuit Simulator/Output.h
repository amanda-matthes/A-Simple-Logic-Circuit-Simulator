// A Simple Logic Circuit Simulator
// A project for PHYS 30762 Programming in C++
// Author           :   Amanda Matthes (10241789)
// Handed in on     :   12.May.2018
// This program starts in Main.h

/*
The OUTPUT class is derived from IO
Its symbol is on or off (Global Varibles.h) 
depending on its state.
Its componentType is OUTPUT
*/

#ifndef OUTPUT_H
#define OUTPUT_H

#include "IO.h"

class Output : public IO {
public:
	Output();
	void setLED(bool newState);
};

#endif
