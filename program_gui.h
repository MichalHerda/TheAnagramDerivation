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
	
	//ProgramGui(char guiSign, vector<string> guiText) ;								
	
	ProgramGui(char guiSign, bool isEmptyLineBehind, vector<string> guiText);
	
	
	private: 
	
	static int borderWidth;
	
	int calculateColumnsNo() ;
	
	int calculateRowsNo() ;
	
	void createBorderFrame(char guiSign) ;
		
	void createEmptyLine(char guiSign) ;
	
	void createLeftOrRightBorder(char guiSign) ;
	
};
#endif // PROGRAM_GUI_H
//------------------------------------------------------------------------------------------------------------------------------------

