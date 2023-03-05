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
	
	ProgramGui(vector<string> guiText) ;								
	
	
	private: 
	
	static int borderWidth;
	
	int calculateColumnsNo() ;
	
	int calculateRowsNo() ;
	
	void createBorderFrame() ;
		
	void createEmptyLine() ;
	
	void createLeftOrRightBorder() ;
	
};
#endif // PROGRAM_GUI_H
//------------------------------------------------------------------------------------------------------------------------------------

