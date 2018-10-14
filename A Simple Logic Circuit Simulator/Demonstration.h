// A Simple Logic Circuit Simulator
// A project for PHYS 30762 Programming in C++
// Author           :   Amanda Matthes (10241789)
// Handed in on     :   12.May.2018
// This program starts in Main.h

/*
This file contains everything related to examples.
demonstration() is the interface for accessing examples.
All other functions are encapsulations for the various 
examples and get called by demonstration().
*/

#ifndef DEMONSTRATION_H
#define DEMONSTRATION_H

#include "GlobalVariables.h"
#include "Grid.h"
#include "Component.h"


void printLegend();					
void testWiresInputsOutputs();	// example that demonstrates how INPUTS, WIRES and OUTPUTs work
void testGate(type gateType);	// example that demonstrates how AND or OR (depending on gateType) work
void testNot();					// example that demonstrates how NOT works
void elephant();
void demonstration();			// sub menu to navigate examples

#endif