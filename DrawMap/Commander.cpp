#include "Commander.h"

#include <graphics.h>

namespace MapDraw {
	Commander::Commander() :m_menuCmd(this), m_drawCmd(this)//默认构造函数
	{
		m_EditType = ET_NULL;
	}

	void Commander::Run()//监听鼠标信息，是一个循环
	{
		MOUSEMSG msg;		//定义变量，保存鼠标消息
		FlushMouseMsgBuffer();// 清空鼠标消息缓冲区，避免无效鼠标信息带入到正式判断中

		//绘制图形
		m_shapeSet.Draw();

		while (!isExit())	//一直循环
		{

			while (MouseHit())	//检查鼠标消息
			{
				msg = GetMouseMsg();	//鼠标消息状态
				if (msg.x >= 0 && msg.x <= 200)
					m_menuCmd.onMouseMessage(msg);
				else
					m_drawCmd.onMouseMessage(msg);
				if (isExit()) 
					break;	//退出循环

			}
		}

	}

	NeededCmd CheckCommandID(int x, int y)//判断鼠标点击的功能键
	{
		NeededCmd cmd = WC_NULL;

		if (x <= 160 && x >= 40)
		{
			if (y >= 35 && y <= 65)	cmd = WC_LOADIMAGE;
			else if (y >= 80 && y <= 110) cmd = WC_LOADVECTOR;
			else if (y >= 125 && y <= 155) cmd = WC_NEWVECTOR;
			else if (y >= 170 && y <= 200) cmd = WC_SAVE;
			else if (y >= 250 && y <= 280) cmd = WC_DRAWPOINT;
			else if (y >= 293 && y <= 323) cmd = WC_DRAWPOLYGON;
			else if (y >= 337 && y <= 370) cmd = WC_DRAWLINE;
			else if (y >= 417 && y <= 447) cmd = WC_MOVE;
			else if (y >= 461 && y <= 492) cmd = WC_DELETE;
			else if (y >= 507 && y <= 535) cmd = WC_CHANGEPARAMETER;
			else if (y >= 585 && y <= 615) cmd = WC_EXIT;
			else cmd = WC_NULL;
		}

		return cmd;
	}

}