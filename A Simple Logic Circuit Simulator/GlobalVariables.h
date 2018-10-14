// A Simple Logic Circuit Simulator
// A project for PHYS 30762 Programming in C++
// Author           :   Amanda Matthes (10241789)
// Handed in on     :   12.May.2018
// This program starts in Main.h

/*
This file contains includes all the standard headers 
that are used in (almost) all files of the project
as well as important simple functions, enums and structs
*/

#ifndef GLOBALVAR_H
#define GLOBALVAR_H

#include <iostream>	
#include <iomanip>	// included to use setw for nicely formatted output
#include <string>	
#include <vector>	// rather than traditional arrays 

using namespace std;

// location is used for the graph search to indicate where the search is coming from:
enum location { UP, DOWN, LEFT, RIGHT, START };			

// type is used to tag objects so that the board can be rendered efficiently:
enum type { INPUT, OUTPUT, AND, OR, NOT, WIRE, EMPTY };							

// intPair is used when the user creates boards to identify locations on the grid or its dimensions
struct intPair { int first; int second; };

char const on = 178;	// symbol used to indicate that an LED is on
char const off = 176;	// symbol used to indicate that an LED is off

bool isGate(type t);				// returns true if t is a gate

void endProgram(string message);	// displays message and ends the program in an endless loop to keep the window open

#endif
