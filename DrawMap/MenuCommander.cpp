
#include "Commander.h"
#include "MenuCommander.h"
#include <graphics.h>
#include <fstream>

namespace MapDraw {
	MenuCommander::MenuCommander(Commander* Cmdptr = nullptr) :m_pParentCmder(Cmdptr)
	{
		m_bExit = false;
	}
	void MenuCommander::onMouseMessage(const MOUSEMSG&msg)
	{
		switch (msg.uMsg)
		{
		case WM_LBUTTONDOWN://左键按下
			onLButtondown(msg);
			break;
		case WM_MOUSEMOVE://鼠标移动
			onMousemove(msg);
			break;
		case WM_RBUTTONUP://右键弹起
			onRButtonup(msg);
			break;
		default:
			Sleep(10);//休眠10ms
			break;
		}
	}

	void MenuCommander::onLButtondown(const MOUSEMSG&msg)
	{
		clearrectangle(20, 640, 100, 660);
		// msg.x, msg.y --> CommandID
		NeededCmd CurrentCMDID;//现行操作命令
		CurrentCMDID = CheckCommandID(msg.x, msg.y);
		switch (CurrentCMDID)
		{
		case WC_EXIT:
			outtextxy(20, 640, "                                           ");
			outtextxy(20, 640, "Exit");
			m_bExit = true;
			break;
		case WC_LOADIMAGE:
			outtextxy(20, 640, "                                           ");
			outtextxy(20, 640, "Load Image");
			break;
		case WC_LOADVECTOR:
			outtextxy(20, 640, "                                           ");
			outtextxy(20, 640, "Load Vector");
			onLoad();
			break;
		case WC_NEWVECTOR:
			outtextxy(20, 640, "                                           ");
			outtextxy(20, 640, "Create a new Vector");
			break;
		case WC_SAVE:
			outtextxy(20, 640, "                                           ");
			outtextxy(20, 640, "Save");
			onSave();
			break;
		case WC_DRAWLINE:
			//m_EditType = ET_LINE;//进入编辑状态，画线
			outtextxy(20, 640, "                                           ");
			outtextxy(20, 640, "Line");
			m_pParentCmder->setEditType(ET_LINE);
			break;
		case WC_DRAWPOINT:
			//m_EditType = ET_POINT;//进入编辑状态，画点
			outtextxy(20, 640, "                                           ");
			outtextxy(20, 640, "Point");
			m_pParentCmder->setEditType(ET_POINT);
			break;
		case WC_DRAWPOLYGON:
			//m_EditType = ET_POINT;//进入编辑状态，画多边形
			outtextxy(20, 640, "                                           ");
			outtextxy(20, 640, "Polygon");
			m_pParentCmder->setEditType(ET_POLY);
			break;
		case WC_MOVE:
			//m_EditType = ET_MOVE;//进入编辑状态，移动
			outtextxy(20, 640, "                                           ");
			outtextxy(20, 640, "Move");
			m_pParentCmder->setEditType(ET_MOVE);
			break;
		case WC_DELETE:
			//m_EditType = ET_DEL;//进入编辑状态，移动
			outtextxy(20, 640, "                                           ");
			outtextxy(20, 640, "Delete");
			m_pParentCmder->setEditType(ET_DEL);
			break;
		case WC_CHANGEPARAMETER:
			//m_EditType = ET_CHANGEPRA;//进入编辑状态，改变参数
			outtextxy(20, 640, "                                           ");
			outtextxy(20, 640, "Change Parameter");
			m_pParentCmder->setEditType(ET_CHANGEPRA);
			break;
		default:
			m_bExit = false;
			break;
		}
	}


	void MenuCommander::onLoad()
	{
		char sShapeFilePath[260] = "";//存放shp文件的路径
		if (!InputBox(sShapeFilePath, 260, "Vector File:", "Input Vector File Path."))
			return;
		ifstream ifs(sShapeFilePath);
		if (!ifs.is_open())
		{
			MessageBox(NULL, "Open File Failed", "Error", MB_ICONERROR);
			return;
		}

		ifs>>m_pParentCmder->getShapeSet();
		ifs.close();

		m_pParentCmder->getShapeSet().Draw();
	}

	void MenuCommander::onSave()
	{
		char	sShapeFilePath[260] = "";
		if (!InputBox(sShapeFilePath, 260, "Vector File:", "Save Vector File Path."))
			return;

		ofstream   ofs(sShapeFilePath);
		if (!ofs.is_open())
		{
			MessageBox(NULL, "Open File Failed", "Error", MB_ICONERROR);
			return;
		}

		ofs << m_pParentCmder->getShapeSet();

		ofs.close();

	}

	/*
	NeededCmd MenuCommander::CheckCommandID(int x, int y)
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
	*/

}