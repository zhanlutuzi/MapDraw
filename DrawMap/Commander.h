#pragma once
#include "MenuCommander.h"
#include "DrawCommander.h"
#include "ShapeSet.h"
using namespace std;

namespace MapDraw {
	
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
		ET_NULL,//��
		ET_POINT,//��
		ET_LINE,//��
		ET_POLY,//�����
		ET_MOVE,//�ƶ�
		ET_DEL,//ɾ��
		ET_CHANGEPRA,//�ı����
		ET_LAST,//������־
	};

	NeededCmd CheckCommandID(int x, int y);//�ж�������Ĺ��ܼ�

	class Commander
	{
	public:
		Commander();
		~Commander()=default;
		void Run();//����
		inline const EditType getEditType()const { return m_EditType; }//�õ��༭����
		inline void setEditType(EditType nEditType = ET_NULL) { m_EditType = nEditType; }//���ñ༭����
		ShapeSet &getShapeSet() { return m_shapeSet; }//�õ���״����
	protected:
		bool isExit() { return m_menuCmd.isExit(); };//�ж��Ƿ����
	private:
		MenuCommander  m_menuCmd;//�������˵�������Ϣ
		DrawCommander  m_drawCmd;//�����Ҳ�˵�
		EditType m_EditType;//���Ƶ�״̬
		ShapeSet m_shapeSet;//�����״����

	};

}