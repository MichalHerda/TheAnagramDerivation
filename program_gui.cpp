//------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------PROGRAM GUI--------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------------

#include "program_gui.h"

using namespace std;

//------------------------------------------------------------------------------------------------------------------------------------
	
int ProgramGui::borderWidth = 3;

int ProgramGui::calculateColumnsNo() {
	
        winsize w;
        ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
        int columns = w.ws_col;		    
        return columns;
}

int ProgramGui::calculateRowsNo() {
	
        winsize w;
        ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);	   
        int rows = w.ws_row;	       	   
        return rows;
}

void ProgramGui::createBorderFrame() {

	for (int i = 0; i < ProgramGui::calculateColumnsNo(); i++) {
		cout << "*";
	}				
}
	
void ProgramGui::createEmptyLine() {
	
	ProgramGui::createLeftOrRightBorder();
	for (int i = 0; i < ProgramGui::calculateColumnsNo() - (ProgramGui::borderWidth * 2) ; i++) {
		cout << " ";
	}
	ProgramGui::createLeftOrRightBorder();				
}

void ProgramGui::createLeftOrRightBorder() {
	for (int i = 0; i < ProgramGui::borderWidth; i++) {
		cout << "*";
	}
}	

ProgramGui::ProgramGui(vector<string> guiText) {
	
	cout << "\n";
	ProgramGui::createBorderFrame();
	ProgramGui::createEmptyLine();	
	
	for (int i = 0; i < guiText.size(); i ++) {
		int distanceFromFrame = ( ProgramGui::calculateColumnsNo() - ( ProgramGui::borderWidth * 2 ) - guiText[i].length() ) / 2;
		ProgramGui::createLeftOrRightBorder();
		for (int i = 0; i < distanceFromFrame; i++) {
			cout << " ";				
		}
		if( ( (distanceFromFrame * 2) + ( ProgramGui::borderWidth * 2 ) + ( guiText[i].length() ) ) 
											!= ProgramGui::calculateColumnsNo() ) cout << " ";
		cout << guiText [i];
		for (int i = 0; i < distanceFromFrame; i++) {
			cout << " ";
		}
		ProgramGui::createLeftOrRightBorder();			
		ProgramGui::createEmptyLine();			
	}		
	ProgramGui::createBorderFrame();		
	cout << "\n";												
}

//------------------------------------------------------------------------------------------------------------------------------------

