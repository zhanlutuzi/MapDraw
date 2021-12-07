#pragma once
#include <vector>
#include <graphics.h>
using namespace std;

namespace MapDraw {
	class Commander;

	class DrawCommander//��ͼ����
	{
	public:
		DrawCommander(Commander* Cmdptr);//����Commander���ָ��
		void onMouseMessage(const MOUSEMSG &msg);//�����Ϣ

	protected:
		void onLButtondown(const MOUSEMSG &msg);//�������
		void onMousemove(const MOUSEMSG &msg);//����ƶ�
		void onLButtonup(const MOUSEMSG &msg);//���̧��
		void onRButtonup(const MOUSEMSG &msg);//�Ҽ�̧��
	private:
		bool m_bPressed;//�Ƿ���
		bool m_bStartTag;//һ�����Ƿ�����
		Commander *m_pParentCmder;//Parent Commander
		POINT m_ptFirst;//��ʼ��
		POINT m_ptLast;//�յ�
		vector<POINT> m_ptList;//����б�
	};

}