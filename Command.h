#pragma once
#include<graphics.h>
#include <conio.h>		//_getch
#include <istream>
#include <ostream>
enum NeededCmd {
	WC_NULL,		//null command ������
	WC_LOADIMAGE,	//Load Image ����ͼƬ
	WC_LOADVECTOR,	//Load Vector ����ʸ��
	WC_NEWVECTOR,	//New Vector �½�ʸ��
	WC_SAVE,		//Save Vector ����ʸ��
	WC_DRAWLINE,	//Draw Line ����
	WC_DRAWPOINT,   //Draw Point ����
	WC_DRAWPOLYGON,  //Draw Polygon �������
	WC_MOVE,			//Move �ƶ�
	WC_DELETE,     //Delete ɾ��
	WC_CHANGEPARAMETER,  //Change Parameter �ı����
	WC_EXIT = 999	//Exit �˳�
};

enum EditType {
	ET_POINT,//��
	ET_LINE,//��
	ET_POLY,//�����
	ET_MOVE,//�ƶ�
	ET_DEL,//ɾ��
	ET_CHANGEPRA,//�ı����
	ET_LAST,//������־
};

//�½�һ���ࣨCommand�����ڴ�������
class Command
{
public:
	Command();
	void run();
protected:
	void onMenuMsg(MOUSEMSG &msg);
	void onViewMsg(MOUSEMSG &msg);
	void onViewLButtonDown(MOUSEMSG &msg);
	void onViewRButtonDown(MOUSEMSG &msg);
	void onViewMouseMove(MOUSEMSG &msg);
	void onMenuLButtonDown(MOUSEMSG &msg);
	void onMenuMouseMove(MOUSEMSG &msg);
	void onMenuRButtonDown(MOUSEMSG &msg);
	bool isExit() { return m_bExit; };//�ж��Ƿ����
private:
	bool m_bExit;
	EditType m_EditType;//���Ƶ�״̬
	bool m_bStartEdit;//�Ƿ�ʼ�༭�ı�־
	POINT m_pointFirst;//�����һ���������
	POINT m_pointLast;//�������һ���������
};

