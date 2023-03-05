//--------------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------ANAGRAM DERIVATION--------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------
#include <iostream>
#include <ncurses.h>									// for interactive console menu
#include <unistd.h>									// for calculating screen width/height
#include <thread>									// to enable co-existing cout and ncurses								
#include <fstream>									// read source file
#include "program_gui.h"								// class for creating simple GUI with frames

using namespace std;

void titlePage() {

	ProgramGui titlePage 
		   ({" ", " ",
		    "Welcome to", "THE ANAGRAM DERIVATION", " ",
		    "An anagram derivation is a N-letter word derived from a N-1 letter word",
		    "by adding a letter and rearranging.",	
   		    "For example, here is a derivation of \" aliens \":",
   		    "ail + s = sail + n = nails + e = aliens"," ",
   		    "Application is able to operate on external dictionary - text file where each line is another word",
   		    "User can choose the dictionary at runtime"," ",
		    "PRESS C - CONTINUE",
		    "PRESS Q - QUIT ", " ", " ",});
}

void exitPage() {
	clear();
	refresh();
	printw(" ");
	ProgramGui exitPage ({" "," "," "," "," ","PROGRAM EXITED"," "," "," "," "," "});
	sleep(5);
}

void selectSourceMenu() {
	clear();
	refresh();
	printw(" ");
	ProgramGui exitPage ({" "," "," ","SELECT SOURCE DICTIONARY:","PRESS 1 - INTERNAL DICTIONARY",
			      "PRESS 2 - EXTERNAL DICTIONARY "," "," "," "});
	sleep(5);
}

fstream selectSourceFile(string& filename) {
	fstream file(filename, std::ios::in | std::ios::out);
    if (!file.is_open()) {
        throw runtime_error("Failed to open file");
    }
    return file;
}

int main() {
		
	initscr();									// ncurses initialization
	cbreak();
	noecho();
	curs_set(0);									// set cursor invisible
	
	thread guiThread(titlePage); 							// run thread displaying title page GUI	
    		
	char ch = getch();
	
	//while (true) { 
		switch (ch) {
			case 'c':									
				selectSourceMenu();
				break;
			case 'q':
				exitPage();
				break;
			default:
				main();
		}
	//}
		
	
	guiThread.join(); 								// waiting for thread ending
    	
	endwin();
	//close ncurses
	
	return 0;
}
//--------------------------------------------------------------------------------------------------------------------------------------
