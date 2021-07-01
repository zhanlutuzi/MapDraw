#include "Command.h"
#include<graphics.h>


eWndCmd CheckCommandID(int x, int y)//�ж�������Ĺ��ܼ�
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
	

	MOUSEMSG msg;		//������������������Ϣ
	FlushMouseMsgBuffer();// ��������Ϣ��������������Ч�����Ϣ���뵽��ʽ�ж���
	bool	m_bExit = false;	//�Ƿ��˳��ı�־

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