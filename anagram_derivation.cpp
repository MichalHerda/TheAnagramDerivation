//--------------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------ANAGRAM DERIVATION--------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------
#include <iostream>
#include <ncurses.h>									// for interactive console menu
#include <unistd.h>									// for calculating screen width/height
#include <thread>									// to enable co-existing cout and ncurses								
#include <fstream>									// read source file
#include <filesystem>
#include <vector>
#include <string>
#include "program_gui.h"								// class for creating simple GUI with frames

using namespace std;
namespace fs = std::filesystem;

void externalDictionary(fs::path pathToShow) {

	clear();
	refresh();
	vector<string>directoryNames;								// directoryNames is for reading purposes
	vector<string>directoryNamesNumbered = {"SELECT DIRECTORY NUMBER AND PRESS 'ENTER': "," "};		
												// dnNumbered is for displaying purposes
	int directoryNo = 0;
	int navigateUp = 0;
	int exitProgram = 0;
		
	for (const auto& entry : fs::directory_iterator(pathToShow)) {
        		
		if (entry.is_directory() || fs::path(entry).extension() == ".txt") {
		    directoryNo ++;
	            directoryNamesNumbered.push_back(to_string(directoryNo) + ". " + entry.path().filename().string());
	            directoryNames.push_back(entry.path().filename().string());
		}
    	}
    	
    	navigateUp  = directoryNo + 1;
    	exitProgram = directoryNo + 2;
    	directoryNamesNumbered.push_back(" ");
    	directoryNamesNumbered.push_back(to_string(navigateUp) + ". NAVIGATE UP");
    	directoryNamesNumbered.push_back(to_string(exitProgram) + ". EXIT PROGRAM");
    	
    	int selectPath;	
	ProgramGui ('#',false,{directoryNamesNumbered});
	scanf("%d", &selectPath);
	clear();
	refresh();
	
	if( (selectPath > 0 ) && (selectPath <= directoryNames.size() ) ) {
		ProgramGui ('X',true, {" "," SELECTED PATH IS: "," ", directoryNames[selectPath - 1]," ", " WAIT FOR REDIRECTION"} );
	    	sleep(1);
		pathToShow = pathToShow/directoryNames[selectPath - 1];
		externalDictionary(pathToShow);
	}
	
	if(selectPath == navigateUp) {
		fs::path parentPath = pathToShow.parent_path();		
		externalDictionary(parentPath);
	}
	
	if(selectPath == exitProgram) {
		return;
	}		
}
    

void titlePage() {

	ProgramGui titlePage 
		   ('$',true,{" ",
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
	ProgramGui exitPage ('%',true,{" "," "," "," "," ","PROGRAM EXITED"," "," "," "," "," "});
	sleep(5);
}

void selectSourceMenu() {
	clear();
	refresh();
	printw(" ");
	ProgramGui exitPage ('X',true,{" "," "," ","SELECT SOURCE DICTIONARY:","PRESS 1 - INTERNAL DICTIONARY",
			      "PRESS 2 - EXTERNAL DICTIONARY "," "," "," "});
	
	SELECT:
			      
	char ch = getch();
	
	switch (ch) {
		case '1':
			break;
		case '2':
			externalDictionary("/");
			break;
		default:
			selectSourceMenu();					// 
	}
	
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
										// cause normally ncurses would be waiting for key selected
										// using thread here is caused by co-existing cout					
										// and ncurses in one project
	SELECT: 
	
	char ch = getch();
		
	switch (ch) {
		case 'c':									
			selectSourceMenu();
			break;
		case 'q':
			exitPage();
			break;
		default:
			goto SELECT;						// if getch() != c or !q wait until
										// expected char is selected -  it is reason for using goto
										// and I don't care if you don't like that
										// it is also to avoid recursively calling int main()
	}
		
guiThread.join(); 								// waiting for thread ending
    	
	endwin();
	//close ncurses
	
	return 0;
}
//--------------------------------------------------------------------------------------------------------------------------------------
