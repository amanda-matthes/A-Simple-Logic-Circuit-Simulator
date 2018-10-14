// A Simple Logic Circuit Simulator
// A project for PHYS 30762 Programming in C++
// Author           :   Amanda Matthes (10241789)
// Handed in on     :   12.May.2018
// This program starts in Main.h

/*
This file contains everything related to creating new grids.
boardCreator() forms the interface when the user creates new grids.
*/

#ifndef BOARD_CREATOR_H
#define BOARD_CREATOR_H

#include "GlobalVariables.h"
#include "Demonstration.h"		// we want to use the printLegend() feature
#include "Grid.h"				// we need to be able to create new grids

void boardCreator();					// acts as a sub menu to navigate board creation
intPair askForTwoInts(string message);	// displays message to ask the user for two numbers firstxsecond and returns them as an intPair (first, second)
type askForType();						// asks the user for a component type and returns it
bool askForBool();						// asks the user for a boolean and returns it

#endif
