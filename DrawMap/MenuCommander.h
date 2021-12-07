#pragma once

#include <graphics.h>


namespace MapDraw {
	class Commander;
	class MenuCommander//�˵�������
	{
	public:
		MenuCommander(Commander* Cmdptr);//����Commander���͵�ָ��
		void onMouseMessage(const MOUSEMSG& msg);//�����Ϣ
		inline bool isExit() { return m_bExit; };//�Ƿ��˳�
	protected:
		void onLButtondown(const MOUSEMSG&msg);//�������
		void onMousemove(const MOUSEMSG&msg) {}
		void onLButtonup(const MOUSEMSG&msg) {}
		void onRButtonup(const MOUSEMSG&msg) {}

		void onLoad();//����ʾ���ļ�
		void onSave();//�����ļ�
	private:
		bool m_bExit;//�Ƿ��˳��ı�־
		Commander *m_pParentCmder;//Parent Commander ָ������ָ��

	};

}