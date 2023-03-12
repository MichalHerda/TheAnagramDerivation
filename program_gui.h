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
#include <cmath>

using namespace std;

//------------------------------------------------------------------------------------------------------------------------------------
class ProgramGui {

	public:
								
		ProgramGui (int upAndDownBorderWidth, int leftAndRightBorderWidth, char guiSign, 
			    bool isEmptyLineBetween, vector<string> guiText);
	
	
	private: 		
	
		int calculateColumnsNo() ;
		
		int calculateRowsNo() ;
		
		void createUpAndDownBorder(char guiSign, int upAndDownBorderWidth) ;
			
		void createEmptyLine(char guiSign, int leftAndRightBorderWidth) ;
		
		void createLeftAndRightBorder(char guiSign, int leftAndRightBorderWidth) ;
		
		int calculatePagesNo(int upAndDownBorderWidth, bool isEmptyLineBetween, vector<string> guiText) ;
	
};

#endif // PROGRAM_GUI_H
//------------------------------------------------------------------------------------------------------------------------------------

