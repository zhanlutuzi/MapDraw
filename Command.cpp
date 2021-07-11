#include "Command.h"
#include<graphics.h>
#include "shape.h"


NeededCmd CheckCommandID(int x, int y)//�ж�������Ĺ��ܼ�
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

Command::Command() //Ĭ�Ϲ��캯��
{
	m_bExit = false;//���ж��Ƿ��˳���������Ϊ��
	m_bStartEdit = false;//��ʼ����ʼ�༭Ϊ��
}

void Command::run()
{
	

	MOUSEMSG msg;		//������������������Ϣ
	FlushMouseMsgBuffer();// ��������Ϣ��������������Ч�����Ϣ���뵽��ʽ�ж���
	//bool	m_bExit = false;	//�Ƿ��˳��ı�־

	while (!m_bExit)	//һֱѭ��
	{
		
		while (MouseHit())	//��������Ϣ
		{
			msg = GetMouseMsg();	//�����Ϣ״̬
			if (msg.x >= 0 && msg.x <= 200)
				onMenuMsg(msg);
			else
				onViewMsg(msg);
			if (m_bExit) break;	//�˳�ѭ��
	
		}
	}


}
/*
bool	bState = true;
bool onCommand(NeededCmd cmd)
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
		//����Ӿ���ʵ�ֺ���
		break;
	case WC_DRAWPOLYGON:
		//����Ӿ���ʵ�ֺ���
		break;
	case WC_MOVE:
		//����Ӿ���ʵ�ֺ���
		break;
	case WC_DELETE:
		//����Ӿ���ʵ�ֺ���
		break;
	case WC_CHANGEPARAMETER:
		//����Ӿ���ʵ�ֺ���
		break;
	default:
		bState = true;
		break;
	}

	return bState;
}
*/
void Command::onMenuLButtonDown(MOUSEMSG &msg)
{
	// msg.x, msg.y --> CommandID
	NeededCmd CurrentCMDID;//���в�������
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
		break;
	case WC_NEWVECTOR:
		outtextxy(20, 640, "                                           ");
		outtextxy(20, 640, "Create a new Vector");
		break;
	case WC_SAVE:
		outtextxy(20, 640, "                                           ");
		outtextxy(20, 640, "Save");
		break;
	case WC_DRAWLINE:
		m_EditType = ET_LINE;//����༭״̬������
		outtextxy(20, 640, "                                           ");
		outtextxy(20, 640, "Line");
		break;
	case WC_DRAWPOINT:
		m_EditType = ET_POINT;//����༭״̬������
		outtextxy(20, 640, "                                           ");
		outtextxy(20, 640, "Point");
		break;
	case WC_DRAWPOLYGON:
		m_EditType = ET_POINT;//����༭״̬���������
		outtextxy(20, 640, "                                           ");
		outtextxy(20, 640, "Polygon");
		break;
	case WC_MOVE:
		m_EditType = ET_MOVE;//����༭״̬���ƶ�
		outtextxy(20, 640, "                                           ");
		outtextxy(20, 640, "Move");
		break;
	case WC_DELETE:
		m_EditType = ET_DEL;//����༭״̬���ƶ�
		outtextxy(20, 640, "                                           ");
		outtextxy(20, 640, "Delete");
		break;
	case WC_CHANGEPARAMETER:
		m_EditType = ET_CHANGEPRA;//����༭״̬���ı����
		outtextxy(20, 640, "                                           ");
		outtextxy(20, 640, "Change Parameter");
		break;
	default:
		m_bExit = false;
		break;
	}
}
void Command::onMenuMsg(MOUSEMSG &msg)
{
	switch (msg.uMsg)
	{
	case WM_LBUTTONDOWN://�������
		onMenuLButtonDown(msg);
		break;
	case WM_MOUSEMOVE://����ƶ�
		onMenuMouseMove(msg);
		break;
	case WM_RBUTTONDOWN://�Ҽ�����
		onMenuRButtonDown(msg);
		break;
	default:
		break;
	}
}

void Command::onMenuMouseMove(MOUSEMSG &msg)
{

}

void Command::onMenuRButtonDown(MOUSEMSG &msg)
{

}

void Command::onViewMsg(MOUSEMSG &msg)//�Ҳ����
{
	switch (msg.uMsg)
	{
	case WM_LBUTTONDOWN://�������
		onViewLButtonDown(msg);
		break;
	case WM_MOUSEMOVE://����ƶ�
		onViewMouseMove(msg);
		break;
	case WM_RBUTTONDOWN://�Ҽ�����
		onViewRButtonDown(msg);
		break;
	default:
		break;
	}
}

void Command::onViewLButtonDown(MOUSEMSG &msg)
{
	switch (m_EditType)
	{
	case ET_LINE:
		if (!m_bStartEdit)//First Node ��һ�����
		{
		m_bStartEdit = true;
		setcolor(RED);
		}
		else//����������㣬����
		{
		line(m_pointFirst.x, m_pointFirst.y, msg.x, msg.y);
		}
		m_pointFirst.x = msg.x;//������һ����
		m_pointFirst.y = msg.y;
		m_pointLast = m_pointFirst;
		break;
	case ET_POINT:
		m_bStartEdit = true;
	{Point m_pt(msg.x, msg.y);
	m_pt.Draw(); }
		break;
	case ET_MOVE:
		break;
	case ET_DEL:
		break;
	case ET_CHANGEPRA:
		break;
	default:
		break;
	}
	
}
void Command::onViewRButtonDown(MOUSEMSG &msg)
{
	switch (m_EditType)
	{
	case ET_LINE:
		m_bStartEdit = false;
		{
			int oldmode = getrop2();
			setrop2(R2_NOTXORPEN);//�����
			line(m_pointFirst.x, m_pointFirst.y, m_pointLast.x, m_pointLast.y);
			setrop2(oldmode);//��ԭ����ģʽ

		}
		break;
	case ET_POINT:
		break;
	case ET_MOVE:
		break;
	case ET_DEL:
		break;
	case ET_CHANGEPRA:
		break;
	default:
		break;
	}
}
void Command::onViewMouseMove(MOUSEMSG &msg)
{
	switch (m_EditType)
	{
	case ET_LINE:
		if (m_bStartEdit)
		{
			int oldmode = getrop2();
			setrop2(R2_NOTXORPEN);//�����

			line(m_pointFirst.x, m_pointFirst.y, m_pointLast.x, m_pointLast.y);
			line(m_pointFirst.x, m_pointFirst.y, msg.x, msg.y);
			m_pointLast.x = msg.x;
			m_pointLast.y = msg.y;
			setrop2(oldmode);//��ԭ����ģʽ

		}
		break;
	case ET_POINT:
		break;
	case ET_MOVE:
		break;
	case ET_DEL:
		break;
	case ET_CHANGEPRA:
		break;
	default:
		break;
	}
}