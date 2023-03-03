//--------------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------ANAGRAM DERIVATION--------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------
#include <iostream>
#include <ncurses.h>
#include "program_gui.h"

using namespace std;

int main() {
	// ncurses initialization
	initscr();
	cbreak();
	noecho();
	
	// it is initialized for next purposes
	// initial commit is for program_gui.h initialization
	
	ProgramGui({" ", " ", " ", " ",
		    "WELCOME TO THE ANAGRAM DERIVATION",
		    "AT THE MOMENT I HAVE CREATED CLASS FOR GUI COMPONENTS", " ",
		    "WRITTING A CONSOLE PROGRAM",
		    "IS MY CONSCIOUS AND DELIBERATE CHOICE :)", " ",
		    "FOR PRACTICE PURPOSES", " ",
		    "THIS IS INITIAL COMMIT",
		    "UPDATES SOON",
		    " ", " ", " ",});
	endwin();
	//close ncurses
	
	return 0;
}
//--------------------------------------------------------------------------------------------------------------------------------------
