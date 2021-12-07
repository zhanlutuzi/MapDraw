#pragma once
#include <vector>
#include <graphics.h>
using namespace std;

namespace MapDraw {
	class Commander;

	class DrawCommander//绘图命令
	{
	public:
		DrawCommander(Commander* Cmdptr);//传入Commander类的指针
		void onMouseMessage(const MOUSEMSG &msg);//鼠标信息

	protected:
		void onLButtondown(const MOUSEMSG &msg);//左键按下
		void onMousemove(const MOUSEMSG &msg);//鼠标移动
		void onLButtonup(const MOUSEMSG &msg);//左键抬起
		void onRButtonup(const MOUSEMSG &msg);//右键抬起
	private:
		bool m_bPressed;//是否按下
		bool m_bStartTag;//一条线是否输入
		Commander *m_pParentCmder;//Parent Commander
		POINT m_ptFirst;//起始点
		POINT m_ptLast;//终点
		vector<POINT> m_ptList;//点的列表
	};

}