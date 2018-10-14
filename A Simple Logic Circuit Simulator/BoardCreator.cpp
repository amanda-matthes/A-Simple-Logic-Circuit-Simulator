// A Simple Logic Circuit Simulator
// A project for PHYS 30762 Programming in C++
// Author           :   Amanda Matthes (10241789)
// Handed in on     :   12.May.2018
// This program starts in Main.h

#include "BoardCreator.h"

void boardCreator() { // acts as a sub menu to navigate board creation
	
	// 1. Ask for dimensions
	intPair dimensions = askForTwoInts("How big do you want your board (widthxheight)?");
	int width = dimensions.first;
	int height = dimensions.second;

	// 2. Create grid
	Grid g = Grid(width, height);
	cout << g;

	// 3. Enter menu
	string input;				// temporarily stores the input
	intPair loc;				// temporarily stores a location
	type t;						// temporarily stores a type
	bool state;					// temporarily stores a state
	while (true) {
		cout << endl << "What do you want to do? \n";
		cout << "A: Add a component \n";
		cout << "B: Delete a component \n";
		cout << "C: Flip an input \n";
		cout << "D: Show me the legend again \n";
		cout << "E: Exit to main menu (Deletes the board) \n";
		getline(cin, input);
		if (input != "A" && input != "B" && input != "C" && input != "D" && input != "E") {
			cout << "Invalid input" << "\n";
		}
		// 3a. Add component
		if (input == "A") {
			// 3a 1) Ask for location of component
			loc = askForTwoInts("Where do you want to add it (rowxcolumn)?");
			if (loc.first >= width || loc.second >= height) {	// check that the location lies on the grid
				cout << "Invalid location. The place you entered is not on this board" << endl;
				continue;
			}
			// 3a 2) Ask for component type and state if applicable
			t = askForType();			// returns EMPTY if the user does not want to add a component after all
			bool state = false;			// gets overwritten iff the type is an INPUT that can actually have a set state
			if (t != EMPTY) {			
				if (t == INPUT) {
					state = askForBool();
				}
				// 3a 3) add to grid
				g.add(loc.first, loc.second, t, state);
			}
		}
		// 3b. Remove component
		if (input == "B") {
			// 3b 1) Ask for location of component
			loc = askForTwoInts("Which component to you want to delete (rowxcolumn)?");
			if (loc.first >= width || loc.second >= height) {	// check that the location lies on the grid
				cout << "Invalid location. The place you entered is not on this board" << endl;
				continue;
			}
			// 3b 2) Remove component
			g.remove(loc.first, loc.second);
		}
		// 3c. Flip an INPUT
		if (input == "C") {
			// 3c 1) Ask for location of INPUT
			loc = askForTwoInts("Which input do you want to flip (rowxcolumn)?");
			if (loc.first >= width || loc.second >= height) {	// check that the location lies on the grid
				cout << "Invalid location. The place you entered is not on this board" << endl;
				continue;
			}
			if (g(loc.first, loc.second).getType() != INPUT) {	// check that location contains an INPUT
				cout << "Invalid location. There is no input component at that location" << endl;
				continue;
			}
			// 3d 2) Flip INPUT
			g(loc.first, loc.second).flip();
		}
		// 3d. Print Legend
		if (input == "D") {
			printLegend();
		}
		// 3c. Return to main menu
		if (input == "E") {
			break;
		}
		g.render();		
		cout << g;		
	}
}

intPair askForTwoInts(string message) {		// asks the user for two numbers firstxsecond and returns them as an intPair (first, second)
	
	string input;				// temporarily stores the input

	bool firstSet = false;		// flags if a number has been entered before the x	
	bool xFound = false;		// flags if the x in the middle has been read
	bool errorFlag = false;		// flags if errors are encountered
	int first;					// will store the first integer
	int second;					// will store the second integer
	string current = "";		// temporarily stores a substring of the input to be interpreted
	
	while (true) {
		firstSet = false; xFound = false; current = ""; errorFlag = false;				// reset in case of invalid input

		cout << message << endl;	
		getline(cin, input);
		for (auto letter : input) {	// iterate input
			if ((letter != 'x' && !isdigit(letter)) || (letter == 'x' && !firstSet)) {	// check for invalid input
				errorFlag = true;
				break;
			}
			firstSet = true;			// we need at least one digit before the x
			if (letter == 'x') {
				xFound = true;
				first = stoi(current);	// if the x is reached we can extract the first integer from current
				current = "";			// reset current, so that it can hold the second integer
				continue;
			}
			current += letter;			// push the next character into current
		}
		if (!xFound || current == "") {	// if we have reached the end of the input and no x has been found the input was invalid
			errorFlag = true;
		}
		if (errorFlag) {				// check error flag
			cout << "Invalid Input. Try writing something like 5x4 or 13x7" << endl;
			continue;
		}

		second = stoi(current);			// if there haven't been any errors current will hold the second integer
		break;
	}
	intPair result;
	result.first = first;
	result.second = second;

	return result;
}

type askForType() {				// asks the user for a component type and returns it
	string input;				// temporarily stores the input
	while (true) {									
		cout << "What component do you want to add?\n";
		cout << "A: Input \n";
		cout << "B: Output (LED) \n";
		cout << "C: AND Gate \n";
		cout << "D: OR Gate \n";
		cout << "E: NOT Gate \n";
		cout << "F: Wire \n";
		cout << "G: Show me the legend again \n";
		cout << "H: I don't want to add anything after all \n";
		getline(cin, input);
		if (input != "A" && input != "B" && input != "C" && input != "D" && input != "E" && input != "F" && input != "G" && input != "H") {
			cout << "Invalid input" << "\n";
		}
		if (input == "A") {
			return INPUT;
		}
		if (input == "B") {
			return OUTPUT;
		}
		if (input == "C") {
			return AND;
		}
		if (input == "D") {
			return OR;
		}
		if (input == "E") {
			return NOT;
		}
		if (input == "F") {
			return WIRE;
		}
		if (input == "G") {
			printLegend();
		}
		if (input == "H") {
			return EMPTY;
		}
	}
}

bool askForBool(){				// asks the user for a boolean and returns it
	string input;				// temporarily stores the input
	while (true) {									
		cout << "Do you want it to be on or off? \n";
		cout << "1: on \n";
		cout << "0: off \n";
		getline(cin, input);
		if (input != "1" && input != "0") {
			cout << "Invalid input" << "\n";
		}
		if (input == "1") {
			return true;
		}
		if (input == "0") {
			return false;
		}
	}
}
