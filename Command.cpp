#include "Command.h"
#include<graphics.h>


eWndCmd CheckCommandID(int x, int y)//判断鼠标点击的功能键
{
	eWndCmd	cmd = WC_NULL;

	if (x <= 160 && x >= 40)
	{
		if (y >= 35 && y <= 65)	cmd = WC_LOADIMAGE;
		else if (y >= 80 && y <= 110) cmd = WC_LOADVECTOR;
		else if (y >= 125 && y <= 155) cmd = WC_NEWVECTOR;
		else if (y >= 170 && y <= 200) cmd = WC_SAVE;
		else if (y >= 585 && y <= 615) cmd = WC_EXIT;
		else cmd = WC_NULL;
	}

	return cmd;
}

Command::Command() 
{
	m_bExit = false;
}

void Command::run()
{
	

	MOUSEMSG msg;		//定义变量，保存鼠标消息
	FlushMouseMsgBuffer();// 清空鼠标消息缓冲区，避免无效鼠标信息带入到正式判断中
	bool	m_bExit = false;	//是否退出的标志

	while (!m_bExit)	//一直循环
	{
		
		while (MouseHit())	//检查鼠标消息
		{
			msg = GetMouseMsg();	//鼠标消息状态
			if (msg.x >= 0 && msg.x <= 200)
				onMenuMsg(msg);
			else
				onViewMsg(msg);
			if (m_bExit) break;	//退出循环
	
		}
	}


}
bool	bState = true;
bool onCommand(eWndCmd cmd)
{

	switch (cmd)
	{
	case WC_EXIT:
		bState = false;
		break;
	case WC_LOADIMAGE:
		MessageBox(NULL, "Load Image.", "Info", MB_ICONINFORMATION);
		break;
	case WC_LOADVECTOR:
		MessageBox(NULL, "Load Vector.", "Info", MB_ICONINFORMATION);
		break;
	case WC_NEWVECTOR:
		MessageBox(NULL, "New Vector.", "Info", MB_ICONINFORMATION);
		break;
	case WC_SAVE:
		MessageBox(NULL, "Save", "Info", MB_ICONINFORMATION);
		break;
	case WC_DRAWPOINT:
		//待添加具体实现函数
		break;
	case WC_DRAWPOLYGON:
		//待添加具体实现函数
		break;
	case WC_MOVE:
		//待添加具体实现函数
		break;
	case WC_DELETE:
		//待添加具体实现函数
		break;
	case WC_CHANGEPARAMETER:
		//待添加具体实现函数
		break;
	default:
		bState = true;
		break;
	}

	return bState;
}

void Command::onMenuMsg(MOUSEMSG &msg)
{
	switch (msg.uMsg)
	{
	case WM_LBUTTONDOWN:
		// msg.x, msg.y --> CMDID
		switch (CheckCommandID(msg.x, msg.y))
		{
		case WC_EXIT:
			m_bExit = true;
			break;
		case WC_DRAWLINE:
			MessageBox(NULL, "line", "Info", MB_ICONINFORMATION);
			break;
		case WC_DRAWPOINT:
			MessageBox(NULL, "point", "Info", MB_ICONINFORMATION);
			break;
		}
		break;
	default:
		break;
	}
}