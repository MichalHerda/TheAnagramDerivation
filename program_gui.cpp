//-----------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------PROGRAM GUI----------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------------
#include "program_gui.h"
#include <ncurses.h>
using namespace std;
//-----------------------------------------------------------------------------------------------------------------------------------------
int ProgramGui::calculateColumnsNo() {
	
        winsize w;
        ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
        int columns = w.ws_col;		    
        return columns;
}
//-----------------------------------------------------------------------------------------------------------------------------------------
int ProgramGui::calculateRowsNo() {
	
        winsize w;
        ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);	   
        int rows = w.ws_row;	       	   
        return rows;
}
//-----------------------------------------------------------------------------------------------------------------------------------------
void ProgramGui::createUpAndDownBorder(char guiSign, int upAndDownBorderWidth) {

	for (int x = 0; x < upAndDownBorderWidth; x++) {
		for (int i = 0; i < ProgramGui::calculateColumnsNo(); i++) {
			cout << guiSign;
		}		
	}		
}
//-----------------------------------------------------------------------------------------------------------------------------------------	
void ProgramGui::createEmptyLine(char guiSign, int leftAndRightBorderWidth) {
	
	ProgramGui::createLeftAndRightBorder(guiSign, leftAndRightBorderWidth);
	for (int i = 0; i < ProgramGui::calculateColumnsNo() - (leftAndRightBorderWidth * 2) ; i++) {
		cout << " ";
	}
	ProgramGui::createLeftAndRightBorder(guiSign, leftAndRightBorderWidth);				
}
//-----------------------------------------------------------------------------------------------------------------------------------------
void ProgramGui::createLeftAndRightBorder(char guiSign, int leftAndRightBorderWidth) {
	for (int i = 0; i < leftAndRightBorderWidth; i++) {
		cout << guiSign;
	}
}	
//-----------------------------------------------------------------------------------------------------------------------------------------
int ProgramGui::calculatePagesNo(int upAndDownBorderWidth, bool isEmptyLineBetween, vector<string> guiText) {

	int emptyLinesInGuiElement = 2;					//this is space between up/down border and first string vector item
	int upAndDownEmptySpace = 2;					//this is space on the top and bottom of page 	
	int emptyLinesBetween;   
	isEmptyLineBetween == true ? emptyLinesBetween = guiText.size() : emptyLinesBetween = 0;               					
	double pageHeight = emptyLinesInGuiElement + upAndDownEmptySpace + guiText.size() + emptyLinesBetween;
	
	int pagesNo = ceil(pageHeight/calculateRowsNo());
	cout << "emptylinesB:" << emptyLinesBetween << endl;
	cout << "pageHeight:" << pageHeight << endl;
	cout << "isEmptyLineB:" << isEmptyLineBetween << endl;
	cout << "pagesNo:" << pagesNo << endl;
	sleep(5);
	clear();
	refresh();
	//cout << "pages: " << pagesNo;
	//sleep(3);
	//clear();
	return pagesNo;
}
//-----------------------------------------------------------------------------------------------------------------------------------------
ProgramGui::ProgramGui (int upAndDownBorderWidth, int leftAndRightBorderWidth, char guiSign, bool isEmptyLineBetween, 
			 vector<string> guiText) {
	
	int pagesNo = ProgramGui::calculatePagesNo(upAndDownBorderWidth, isEmptyLineBetween, guiText); ///////////////
	
	if(pagesNo == 1) {		 
		cout << endl;
		ProgramGui::createUpAndDownBorder(guiSign, upAndDownBorderWidth);
		ProgramGui::createEmptyLine(guiSign, leftAndRightBorderWidth);	
		
		for (int i = 0; i < guiText.size(); i ++) {
			int distanceFromFrame = (ProgramGui::calculateColumnsNo() - (leftAndRightBorderWidth * 2) - guiText[i].length()) / 2;
			ProgramGui::createLeftAndRightBorder(guiSign, leftAndRightBorderWidth);
			for (int i = 0; i < distanceFromFrame; i++) {
				cout << " ";				
			}
			if( ( (distanceFromFrame * 2) + ( leftAndRightBorderWidth * 2 ) + ( guiText[i].length() ) ) 
												!= ProgramGui::calculateColumnsNo() ) cout << " ";
			cout << guiText [i];
			for (int i = 0; i < distanceFromFrame; i++) {
				cout << " ";
			}
			ProgramGui::createLeftAndRightBorder(guiSign, leftAndRightBorderWidth);			
			if(isEmptyLineBetween)ProgramGui::createEmptyLine(guiSign, leftAndRightBorderWidth);			
		}	
		ProgramGui::createEmptyLine(guiSign, leftAndRightBorderWidth);		
		ProgramGui::createUpAndDownBorder(guiSign, upAndDownBorderWidth);		
		cout << endl;
	}
	
	if(pagesNo > 1) {
		cout << "PagesNo > 1";
		cout << "I'm in the process of implementing a solution for directories that span multiple pages."
		sleep(10);
		return;
	}			
}
//-----------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------------

