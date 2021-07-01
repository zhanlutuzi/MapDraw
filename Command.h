#pragma once
#include<graphics.h>
#include <conio.h>		//_getch
enum eWndCmd {
	WC_NULL,		//null command
	WC_LOADIMAGE,	//Load Image
	WC_LOADVECTOR,	//Load Vector
	WC_NEWVECTOR,	//New Vector
	WC_SAVE,		//Save Vector
	WC_DRAWLINE,	//Draw Line
	WC_DRAWPOINT,   //Draw Point
	WC_DRAWPOLYGON,  //Draw Polygon
	WC_MOVE,			//Move
	WC_DELETE,     //Delete
	WC_CHANGEPARAMETER,  //Change Parameter
	WC_EXIT = 999	//Exit
};



class Command
{
public:
	Command();
	void run();
	void onMenuMsg(MOUSEMSG &msg);
	void onViewMsg(MOUSEMSG &msg);

protected:
	bool isExit() { return m_bExit; };
private:
	bool m_bExit;
	eWndCmd CommandID;

};

