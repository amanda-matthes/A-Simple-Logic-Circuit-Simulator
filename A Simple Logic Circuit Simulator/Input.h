// A Simple Logic Circuit Simulator
// A project for PHYS 30762 Programming in C++
// Author           :   Amanda Matthes (10241789)
// Handed in on     :   12.May.2018
// This program starts in Main.h

/*
The Input class is derived from IO
Its symbol is 1 or 0 depending on its state
Its componentType is INPUT
*/

#ifndef INPUT_H
#define INPUT_H

#include "IO.h"

class Input : public IO {
public:
	Input(bool INPUTstate);
	void setLED(bool newState);
};

#endif