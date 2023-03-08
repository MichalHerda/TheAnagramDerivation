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

void ProgramGui::createBorderFrame(char guiSign) {

	for (int i = 0; i < ProgramGui::calculateColumnsNo(); i++) {
		cout << guiSign;
	}				
}
	
void ProgramGui::createEmptyLine(char guiSign) {
	
	ProgramGui::createLeftOrRightBorder(guiSign);
	for (int i = 0; i < ProgramGui::calculateColumnsNo() - (ProgramGui::borderWidth * 2) ; i++) {
		cout << " ";
	}
	ProgramGui::createLeftOrRightBorder(guiSign);				
}

void ProgramGui::createLeftOrRightBorder(char guiSign) {
	for (int i = 0; i < ProgramGui::borderWidth; i++) {
		cout << guiSign;
	}
}	
/*
ProgramGui::ProgramGui(char guiSign, vector<string> guiText) {
	
	cout << "\n";
	ProgramGui::createBorderFrame(guiSign);
	ProgramGui::createEmptyLine(guiSign);	
	
	for (int i = 0; i < guiText.size(); i ++) {
		int distanceFromFrame = ( ProgramGui::calculateColumnsNo() - ( ProgramGui::borderWidth * 2 ) - guiText[i].length() ) / 2;
		ProgramGui::createLeftOrRightBorder(guiSign);
		for (int i = 0; i < distanceFromFrame; i++) {
			cout << " ";				
		}
		if( ( (distanceFromFrame * 2) + ( ProgramGui::borderWidth * 2 ) + ( guiText[i].length() ) ) 
											!= ProgramGui::calculateColumnsNo() ) cout << " ";
		cout << guiText [i];
		for (int i = 0; i < distanceFromFrame; i++) {
			cout << " ";
		}
		ProgramGui::createLeftOrRightBorder(guiSign);			
		ProgramGui::createEmptyLine(guiSign);			
	}		
	ProgramGui::createBorderFrame(guiSign);		
	cout << "\n";												
}
*/
ProgramGui::ProgramGui ( char guiSign, bool isEmptyLineBehind, vector<string> guiText ) {
	cout << "\n";
	ProgramGui::createBorderFrame(guiSign);
	ProgramGui::createEmptyLine(guiSign);	
	
	for (int i = 0; i < guiText.size(); i ++) {
		int distanceFromFrame = ( ProgramGui::calculateColumnsNo() - ( ProgramGui::borderWidth * 2 ) - guiText[i].length() ) / 2;
		ProgramGui::createLeftOrRightBorder(guiSign);
		for (int i = 0; i < distanceFromFrame; i++) {
			cout << " ";				
		}
		if( ( (distanceFromFrame * 2) + ( ProgramGui::borderWidth * 2 ) + ( guiText[i].length() ) ) 
											!= ProgramGui::calculateColumnsNo() ) cout << " ";
		cout << guiText [i];
		for (int i = 0; i < distanceFromFrame; i++) {
			cout << " ";
		}
		ProgramGui::createLeftOrRightBorder(guiSign);			
		if(isEmptyLineBehind)ProgramGui::createEmptyLine(guiSign);			
	}	
	ProgramGui::createEmptyLine(guiSign);		
	ProgramGui::createBorderFrame(guiSign);		
	cout << "\n";	
}

//------------------------------------------------------------------------------------------------------------------------------------

