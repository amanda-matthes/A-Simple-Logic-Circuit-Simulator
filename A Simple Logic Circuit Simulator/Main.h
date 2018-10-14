// A Simple Logic Circuit Simulator
// A project for PHYS 30762 Programming in C++
// Author           :   Amanda Matthes (10241789)
// Handed in on     :   12.May.2018
// This program starts in Main.h

/*
This is where the program starts.
main() calls welcome() which displays a welcome message
and then calls menu() which allows the user to navigate
the program features.
*/

#include "GlobalVariables.h"
#include "Demonstration.h"
#include "BoardCreator.h"

int main();			// calls welcome() then menu()
void welcome();		// displays welcome message
void menu();		// menu that allows the user to navigate the program