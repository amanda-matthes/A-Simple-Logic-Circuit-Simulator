// A Simple Logic Circuit Simulator
// A project for PHYS 30762 Programming in C++
// Author           :   Amanda Matthes (10241789)
// Handed in on     :   12.May.2018
// This program starts in Main.h

#include "Demonstration.h"

void printLegend() {
	cout << "------------------------------------" << endl;
	cout << "True input:    1" << endl;
	cout << "False input:   0" << endl << endl;
	
	cout << "LED on:    " << on << endl;
	cout << "LED off:   " << off << endl << endl;

	cout << "AND gate:  & (input from above and below, output to the right, see examples)" << endl;
	cout << "OR gate:   | (input from above and below, output to the right, see examples)" << endl << endl;

	cout << "NOT gate:  ! " << endl << endl;

	cout << "Wire:	" << '+' << endl;
	cout << "------------------------------------" << endl;
}

void testWiresInputsOutputs() {	// example that demonstrates how INPUTS, WIRES and OUTPUTs work
	Grid g = Grid(9, 5);

	g.add(1, 2, INPUT, true);
	g.add(1, 3, WIRE);
	g.add(1, 4, WIRE);
	g.add(1, 5, WIRE);
	g.add(1, 6, WIRE);
	g.add(1, 7, OUTPUT);

	g.add(3, 2, INPUT, false);
	g.add(3, 3, WIRE);
	g.add(3, 4, WIRE);
	g.add(3, 5, WIRE);
	g.add(3, 6, WIRE);
	g.add(3, 7, OUTPUT);

	g.render();
	cout << g;
}

void testGate(type gateType) {	// example that demonstrates how AND or OR (depending on gateType) work
	Grid g = Grid(9, 8);

	g.add(1, 1, INPUT, true);
	g.add(3, 1, INPUT, true);
	g.add(2, 1, gateType);
	g.add(2, 2, OUTPUT);

	g.add(5, 1, INPUT, true);
	g.add(7, 1, INPUT, false);
	g.add(6, 1, gateType);
	g.add(6, 2, OUTPUT);

	g.add(1, 5, INPUT, false);
	g.add(3, 5, INPUT, true);
	g.add(2, 5, gateType);
	g.add(2, 6, OUTPUT);

	g.add(5, 5, INPUT, false);
	g.add(7, 5, INPUT, false);
	g.add(6, 5, gateType);
	g.add(6, 6, OUTPUT);

	g.render();
	cout << g;

}

void testNot() {				// example that demonstrates how NOT works
	Grid g = Grid(9, 5);

	g.add(1, 2, INPUT, true);
	g.add(1, 3, WIRE);
	g.add(1, 4, NOT);
	g.add(1, 5, WIRE);
	g.add(1, 6, WIRE);
	g.add(1, 7, OUTPUT);

	g.add(3, 2, INPUT, false);
	g.add(3, 3, WIRE);
	g.add(3, 4, NOT);
	g.add(3, 5, WIRE);
	g.add(3, 6, WIRE);
	g.add(3, 7, OUTPUT);

	g.render();
	cout << g;
}

void elephant() {
	cout << "me too!" << endl;

	Grid g = Grid(12, 8);

	// trunk
	g.add(3, 2, WIRE);
	g.add(4, 2, WIRE);
	g.add(5, 2, INPUT, true);

	// head
	g.add(2, 3, WIRE);
	g.add(3, 3, WIRE);
	g.add(2, 4, WIRE);
	g.add(3, 4, WIRE);

	// body 
	g.add(3, 5, WIRE);
	g.add(4, 5, WIRE);
	g.add(3, 6, WIRE);
	g.add(4, 6, WIRE);
	g.add(3, 7, WIRE);

	// front leg
	g.add(4, 4, WIRE);
	g.add(5, 4, WIRE);
	g.add(6, 4, OUTPUT);

	// back leg
	g.add(4, 7, WIRE);
	g.add(5, 7, WIRE);
	g.add(6, 7, OUTPUT);

	// tail
	g.add(2, 8, WIRE);

	// frame
	for (int i = 0; i < 12; i++) {
		g.add(0, i, OUTPUT);
		g.add(7, i, OUTPUT);
	}
	for (int i = 0; i < 8; i++) {
		g.add(i, 0, OUTPUT);
		g.add(i, 11, OUTPUT);
	}

	g.render();
	cout << g;
}

void demonstration() {			// sub menu to navigate examples
	string input;				// temporarily stores the input
	while (true) {	
		// 1. List possiblities
		cout << endl << "Which example would you like to see?\n";
		cout << "A: Wires, inputs and outputs\n";
		cout << "B: NOT gates \n";
		cout << "C: AND gates \n";
		cout << "D: OR gates \n";
		cout << "E: I like elephants \n";
		cout << "F: Show me the legend \n";
		cout << "G: Back to main menu \n";
		getline(cin, input);
		// 2. Check user input
		if (input != "A" && input != "B" && input != "C" && input != "D" && input != "E" && input != "F" && input != "G") {
			cout << "Invalid input" << "\n";
		}
		// 3. Access examples or exit
		if (input == "A") {	
			cout << "Demonstrating Wires, Inputs and Outputs:" << endl;
			cout << "Inputs can be either true (= current on = logical 1) or false (= current off = logical 0)." << endl;
			cout << "Wires can transport this state to Outputs." << endl;
			cout << "Outputs turn on if the state at that location is 1." << endl;
			testWiresInputsOutputs();
			cout << "Wires do not alway have to be straight. Go crazy! They connect to the cells above, below, left and right of themselves." << endl;
		}
		if (input == "B") { 
			cout << "Demonstrating the NOT gate:" << endl;
			cout << "The NOT gate reverts the input. So a 1 turns into a 0 and vice versa:" << endl;
			testNot();
		}
		if (input == "C") {	
			cout << "Demonstrating the AND gate:" << endl;
			cout << "The output of an AND gate is true if and only if both inputs are 1:" << endl;
			testGate(AND);
		}
		if (input == "D") {
			cout << "Demonstrating the OR gate:" << endl;
			cout << "The output of an OR gate is true if and only if one or both inputs are 1:" << endl;
			testGate(OR);
		}
		if (input == "E") {
			elephant();
		}
		if (input == "F") {
			printLegend();
		}
		if (input == "G") {	// end the function and th program returns back to menu() in Main.h which called it in the first place
			break;
		}
	}
	

	

	

}
