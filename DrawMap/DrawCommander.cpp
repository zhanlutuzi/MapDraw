
#include <graphics.h>
#include "Commander.h"
#include "Point.h"
#include "Line.h"
#include "Polygon.h"
#include "DrawCommander.h"
using namespace MapDraw;

namespace MapDraw {
	DrawCommander::DrawCommander(Commander* Cmdptr = nullptr) :m_pParentCmder(Cmdptr)
	{
		m_bPressed = false;
		m_bStartTag = false;
	}

	void DrawCommander::onMouseMessage(const MOUSEMSG&msg)
	{
		switch (msg.uMsg)
		{
		case WM_LBUTTONDOWN://左键按下
			onLButtondown(msg);
			break;
		case WM_LBUTTONUP://左键抬起
			onLButtonup(msg);
			break;
		case WM_MOUSEMOVE://鼠标移动
			onMousemove(msg);
			break;
		case WM_RBUTTONUP://右键抬起
			onRButtonup(msg);
			break;
		default:
			Sleep(10);//休眠10ms
			break;
		}
	}

	void DrawCommander::onLButtondown(const MOUSEMSG&msg)
	{
		m_bPressed = true;

		EditType nEditType = m_pParentCmder->getEditType();
		switch (nEditType)
		{
		case ET_POINT:
			m_pParentCmder->getShapeSet().Append(new Point(msg.x, msg.y));
			putpixel(msg.x, msg.y, RED);
			break;
		case ET_LINE:
		case ET_POLY:
			if (!m_bStartTag)//第一次输入开始
			{
				m_bStartTag = true;//标记已经开始输入了
				setcolor(RED);
			}
			else//输入第n(n>1)个节点
			{
				line(m_ptFirst.x, m_ptFirst.y, msg.x, msg.y);
			}

			//记录输入点坐标
			m_ptFirst.x = msg.x;
			m_ptFirst.y = msg.y;
			m_ptLast = m_ptFirst;

			m_ptList.push_back(m_ptFirst);
			break;
		case ET_NULL:
			break;
		default:
			break;
		}
	}

	void DrawCommander::onMousemove(const MOUSEMSG&msg)
	{
		EditType nEditType = m_pParentCmder->getEditType();
		switch (nEditType)
		{

		case ET_POINT:
			break;
		case ET_LINE:
		case ET_POLY:
			if (m_bStartTag)
			{
				int oldmode = getrop2();
				setrop2(R2_NOTXORPEN);//异或线

				line(m_ptFirst.x, m_ptFirst.y, m_ptLast.x, m_ptLast.y);
				line(m_ptFirst.x, m_ptFirst.y, msg.x, msg.y);
				m_ptLast.x = msg.x;
				m_ptLast.y = msg.y;

				setrop2(oldmode);//还原绘制模式
			}
			break;
		default:
			break;
		}
	}
	//鼠标左键抬起
	void DrawCommander::onLButtonup(const MOUSEMSG&msg)
	{
		m_bPressed = false;
	}

	//鼠标右键抬起

	void DrawCommander::onRButtonup(const MOUSEMSG&msg)
	{
		EditType   nEditType = m_pParentCmder->getEditType();
		int    oldmode = getrop2();
		switch (nEditType)
		{
		case ET_LINE:
			setrop2(R2_NOTXORPEN);//异或线
			line(m_ptFirst.x, m_ptFirst.y, msg.x, msg.y);
			setrop2(oldmode);//还原绘制模式

			if (m_ptList.size() > 1)//至少2个节点
				m_pParentCmder->getShapeSet().Append(new Line(m_ptList));
			break;
		case ET_POLY:
			setrop2(R2_NOTXORPEN);//异或线
			line(m_ptFirst.x, m_ptFirst.y, msg.x, msg.y);
			setrop2(oldmode);//还原绘制模式

			if (m_ptList.size() > 2)//至少3个节点
			{
				m_pParentCmder->getShapeSet().Append(new Polygon(m_ptList));
				line(m_ptList.begin()->x, m_ptList.begin()->y, m_ptList.rbegin()->x, m_ptList.rbegin()->y);
			}
			break;
		default:
			break;

		}
		m_bStartTag = false;//代表一条线结束输入
		m_ptList.clear();//清空缓存节点
	}

}