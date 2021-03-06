// A Simple Logic Circuit Simulator
// A project for PHYS 30762 Programming in C++
// Author           :   Amanda Matthes (10241789)
// Handed in on     :   12.May.2018
// This program starts in Main.h

#include "Main.h"

int main() {

	try {
		welcome();	// display welcome messages
		menu();		// this acts as a menu from which the rest of the program is navigated
	} catch (...) {	// the program has been tested extensively. No exceptions are expected. This is a failsafe to ensure a smooth exit
		endProgram("An unexpected error occured.");
	}

	endProgram(""); // keeps the window open and displays end message
	return 0;		// never reached but main should return an int
}

void welcome() {				// This is displayed once, at the beginning of the program
	cout << "Welcome to my SIMPLE LOGIC CIRCUIT SIMULATOR" << endl << endl;

	cout << "Please check the font that your console is using." << endl;
	cout << "(Right click on the console window and select properties)" << endl;
	cout << "This program will not work with some fonts." << endl;
	cout << "I recommend Consolas or Courier New in size 20 or more." << endl;
	cout << "Maximise this window for best results." << endl << endl;
}

void menu() {					// This is the core of the program. From here the user can navigate the features
	string input;				// temporarily stores the input
	while (true) {
		// list possiblities:
		cout << endl << "What do you want to do? \n";
		cout << "A: Show me some examples \n";
		cout << "B: Show me the legend \n";
		cout << "C: I want to make my own circuit \n";
		cout << "D: Exit \n";
		getline(cin, input);
		// handle invalid input:
		if (input != "A" && input != "B" && input != "C" && input != "D" && input != "E") {
			cout << "Invalid input" << "\n";
		}
		// call respective parts of the program
		if (input == "A") {
			demonstration();	// in Demonstration.h
		}
		if (input == "B") {
			printLegend();		// in Demonstration.h
		}
		if (input == "C") {
			boardCreator();		// in BoardCreator.h
		}
		if (input == "D") {
			break;
		}
	}
}
