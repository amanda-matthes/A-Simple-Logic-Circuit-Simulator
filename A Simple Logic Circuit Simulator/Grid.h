// A Simple Logic Circuit Simulator
// A project for PHYS 30762 Programming in C++
// Author           :   Amanda Matthes (10241789)
// Handed in on     :   12.May.2018
// This program starts in Main.h

/*
This is the class for grids.
Its most important member variable is the vector of 
Component base class pointers called data, which
holds the information about all the components
on the grid.
The most important member function is render() 
which simulates the behaviour of the grid.
*/

#ifndef GRID_H
#define GRID_H

#include "GlobalVariables.h"
// Grid needs to be able to use all components:
#include "Component.h"
#include "Empty.h"
#include "Wire.h"
#include "IO.h"
#include "Input.h"
#include "Output.h"
#include "TwoInputGate.h"
#include "AndGate.h"
#include "OrGate.h"
#include "NotGate.h"

class Grid {
private:
	int width;
	int height;
	vector <Component*> data;	// holds the components on the grid 
	vector <bool> visited;		// true for cells that have been visited. Needed for the graph search
public:
	Grid();
	Grid(int inputWidth, int inputHeight);
	~Grid();					// neccessary since we are using pointers

	void render();				// calls visit(...) from the INPUTS to determine the state of the OUTPUTS
	void visit(int index, location comingFrom, bool state);	// recursively calls itself in a DFS 

	void add(int row, int column, type t, bool state = false);	// adds component of type t at (row, column) (with state if it's an INPUT) 
	void remove(int row, int column);							// removes component at (row, column)

	// These all access data either by (row, column) tuples or directly via index
	Component & operator()(int row, int column);
	Component & getComponent(int row, int column);
	Component & getComponent(int x);

	// Getters:
	int getWidth() const;
	int getHeight() const;

	friend ostream& operator<<(ostream& os, const Grid &g);		// gives << acces to the private members
};

ostream& operator<<(ostream& os, Grid &g);	// allows the program to use << to display grids

#endif
