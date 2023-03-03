//------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------PROGRAM GUI--------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------------
#ifndef PROGRAM_GUI_H
#define PROGRAM_GUI_H

#include <sys/ioctl.h>
#include <unistd.h>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

//------------------------------------------------------------------------------------------------------------------------------------
class ProgramGui {

	public:
	ProgramGui(vector<string> guiText) {
		
		createBorderFrame();
		createEmptyLine();	
		
		for (int i = 0; i < guiText.size(); i ++) {
			int distanceFromFrame = ( calculateColumnsNo() - ( borderWidth * 2 ) - guiText[i].length() ) / 2;
			createLeftOrRightBorder();
			for (int i = 0; i < distanceFromFrame; i++) {
				cout << " ";				
			}
			if( ( (distanceFromFrame * 2) + ( borderWidth * 2 ) + ( guiText[i].length() ) ) 
												!= calculateColumnsNo() ) cout << " ";
			cout << guiText [i];
			for (int i = 0; i < distanceFromFrame; i++) {
				cout << " ";
			}
			createLeftOrRightBorder();			
			createEmptyLine();			
		}		
		createBorderFrame();		
		cout << "\n";												
	}
	
	private: 
	
	int borderWidth = 3;
	
	int calculateColumnsNo() {
		
	        winsize w;
	        ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	        int columns = w.ws_col;		    
	        return columns;
	}
	
	int calculateRowsNo() {
		
	        winsize w;
	        ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);	   
	        int rows = w.ws_row;	       	   
	        return rows;
	}
	
	void createBorderFrame() {

		for (int i = 0; i < calculateColumnsNo(); i++) {
			cout << "*";
		}				
	}
		
	void createEmptyLine() {
		
		createLeftOrRightBorder();
		for (int i = 0; i < calculateColumnsNo() - (borderWidth * 2) ; i++) {
			cout << " ";
		}
		createLeftOrRightBorder();				
	}
	
	void createLeftOrRightBorder() {
		for (int i = 0; i < borderWidth; i++) {
			cout << "*";
		}
	}	
};
#endif // PROGRAM_GUI_H
//------------------------------------------------------------------------------------------------------------------------------------

