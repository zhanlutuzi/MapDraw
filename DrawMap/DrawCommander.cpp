
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
		case WM_LBUTTONDOWN://�������
			onLButtondown(msg);
			break;
		case WM_LBUTTONUP://���̧��
			onLButtonup(msg);
			break;
		case WM_MOUSEMOVE://����ƶ�
			onMousemove(msg);
			break;
		case WM_RBUTTONUP://�Ҽ�̧��
			onRButtonup(msg);
			break;
		default:
			Sleep(10);//����10ms
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
			if (!m_bStartTag)//��һ�����뿪ʼ
			{
				m_bStartTag = true;//����Ѿ���ʼ������
				setcolor(RED);
			}
			else//�����n(n>1)���ڵ�
			{
				line(m_ptFirst.x, m_ptFirst.y, msg.x, msg.y);
			}

			//��¼���������
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
				setrop2(R2_NOTXORPEN);//�����

				line(m_ptFirst.x, m_ptFirst.y, m_ptLast.x, m_ptLast.y);
				line(m_ptFirst.x, m_ptFirst.y, msg.x, msg.y);
				m_ptLast.x = msg.x;
				m_ptLast.y = msg.y;

				setrop2(oldmode);//��ԭ����ģʽ
			}
			break;
		default:
			break;
		}
	}
	//������̧��
	void DrawCommander::onLButtonup(const MOUSEMSG&msg)
	{
		m_bPressed = false;
	}

	//����Ҽ�̧��

	void DrawCommander::onRButtonup(const MOUSEMSG&msg)
	{
		EditType   nEditType = m_pParentCmder->getEditType();
		int    oldmode = getrop2();
		switch (nEditType)
		{
		case ET_LINE:
			setrop2(R2_NOTXORPEN);//�����
			line(m_ptFirst.x, m_ptFirst.y, msg.x, msg.y);
			setrop2(oldmode);//��ԭ����ģʽ

			if (m_ptList.size() > 1)//����2���ڵ�
				m_pParentCmder->getShapeSet().Append(new Line(m_ptList));
			break;
		case ET_POLY:
			setrop2(R2_NOTXORPEN);//�����
			line(m_ptFirst.x, m_ptFirst.y, msg.x, msg.y);
			setrop2(oldmode);//��ԭ����ģʽ

			if (m_ptList.size() > 2)//����3���ڵ�
			{
				m_pParentCmder->getShapeSet().Append(new Polygon(m_ptList));
				line(m_ptList.begin()->x, m_ptList.begin()->y, m_ptList.rbegin()->x, m_ptList.rbegin()->y);
			}
			break;
		default:
			break;

		}
		m_bStartTag = false;//����һ���߽�������
		m_ptList.clear();//��ջ���ڵ�
	}

}