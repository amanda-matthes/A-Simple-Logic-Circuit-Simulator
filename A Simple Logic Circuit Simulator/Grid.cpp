// A Simple Logic Circuit Simulator
// A project for PHYS 30762 Programming in C++
// Author           :   Amanda Matthes (10241789)
// Handed in on     :   12.May.2018
// This program starts in Main.h

#include "Grid.h"

Grid::Grid() {										// default constructor
	width = 0;
	height = 0;
}
Grid::Grid(int inputWidth, int inputHeight) {		// parameterized constructor
	width = inputWidth;
	height = inputHeight;
	for (int i = 0; i < width*height; i++) {
		data.push_back(new Empty());
	}
	visited.resize(width*height, false);
}
void Grid::render() {							// calls visit(...) from the INPUTS to determine the state of the OUTPUTS
	// reset the board:
	for (int x = 0; x < width*height; x++) {
		visited[x] = false;						// reset the property map
		if (isGate((*(data[x])).getType())) {	// reset gates
			(*(data[x])).resetGate();
		}
		if ((*(data[x])).getType() == OUTPUT) {	// reset LEDs
			(*(data[x])).setLED(false);
		}
	}
	// run a DFS from all inputs:
	for (int x = 0; x < width*height; x++) {
		if ((*(data[x])).getType() == INPUT) {
			if ((*(data[x])).getState() == 1) {
				visit(x, START, true);
			}
			else {
				visit(x, START, false);
			}
		}
	}
}
void Grid::visit(int index, location comingFrom, bool state) {	// recursively calls itself in a DFS 
	int row = index % height;					// to make boundary condition checking easier
	int column = (index - row) / height;

	if (visited[index] == false || isGate(data[index]->getType())) {
		visited[index] = true;
		switch (data[index]->getType()) {
		case OUTPUT:
			(*(data[index])).setLED(state);		// set LED to the correct state
			return;								// LEDs do not conduct electricity here;	
		case EMPTY:
			return;
		case OR:
		case AND:
			if (comingFrom == UP) {				// we are at the upper input
				if (data[index]->upperInputDefined()) {
					endProgram("Gate input is ill defined");
				}
				data[index]->setUpperInput(state);
			}
			else {
				if (comingFrom == DOWN) {		// we are at the lower input
					if (data[index]->lowerInputDefined()) {
						endProgram("Gate input is ill defined");
					}
					data[index]->setLowerInput(state);
				}
				else {
					return;
				}
			}
			if (!data[index]->outputDefined()) {
				return; // if the output is not yet defined, we dont wont to render the ouput cell 
			}
			else {		// if the output is defined continue DFS to the right with the output
				if (column != width - 1) {	// check that we are still on the board
					visit(index + height, LEFT, (*data[index]).getOutput());
				}
			}
			return;
		case NOT:		// flips the state
			if (state == true) { state = false; }
			else { state = true; }
		}
		// check boundary conditions, then visit neighbours
		// UP
		if (row != 0) {
			visit(index - 1, DOWN, state);
		}
		// DOWN
		if (row != height - 1) {
			visit(index + 1, UP, state);
		}
		// LEFT
		if (column != 0) {
			visit(index - height, RIGHT, state);
		}
		// RIGHT
		if (column != width - 1) {
			visit(index + height, LEFT, state);
		}
	}
}


void Grid::add(int row, int column, type t, bool state ) {	// adds component of type t at (row, column) (with state if it's an INPUT)
	data[(column*height) + row] = NULL;	// important, otherwise the compiler will not call the right overriding functions 
	switch (t) {
	case OUTPUT:
		data[(column*height) + row] = new Output();
		return;
	case INPUT:
		data[(column*height) + row] = new Input(state);
		return;
	case AND:
		data[(column*height) + row] = new AndGate();
		return;
	case OR:
		data[(column*height) + row] = new OrGate();
		return;
	case WIRE:
		data[(column*height) + row] = new Wire();
		return;
	case NOT:
		data[(column*height) + row] = new NotGate();
		return;
	}
}

void Grid::remove(int row, int column) {					// removes component at (row, column)
	data[(column*height) + row] = NULL;
	data[(column*height) + row] = new Empty();
}

Component & Grid::operator()(int row, int column) {			// Access data via (row, column) tuple
	return *data[(column*height) + row];
}

Component & Grid::getComponent(int row, int column) {		// Identical to ()
	return *data[(column*height) + row];
}

Component & Grid::getComponent(int x) {
	return *data[x];
}

int Grid::getWidth() const {
	return width;
}
int Grid::getHeight() const {
	return height;
}

Grid::~Grid() {	// Destructor neccessary since we are dealing with pointers
	for (auto element : data) {
		delete element;
	}
	// everything else gets cleaned up automatically when it goes out of scope
}

ostream& operator<<(ostream& os, Grid &g) {	// allows the program to use << to display grids
	double width = 2;	// width of the grid pieces
	os << setw(width) << " ";

	for (int x = 0; x < g.getWidth(); x++) {
		os << setw(width) << x << " ";		// column numbers
	}
	os << endl;
	for (int r = 0; r < g.getHeight(); r++) {
		os << setw(width) << r;				// row numbers
		for (int c = 0; c < g.getWidth(); c++) {
			os << setw(width) << g(r, c).getC() << " ";
		}
		os << endl << endl;
	}
	return os;
}
