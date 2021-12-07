#pragma once

#include <graphics.h>


namespace MapDraw {
	class Commander;
	class MenuCommander//菜单栏命令
	{
	public:
		MenuCommander(Commander* Cmdptr);//传入Commander类型的指针
		void onMouseMessage(const MOUSEMSG& msg);//鼠标信息
		inline bool isExit() { return m_bExit; };//是否退出
	protected:
		void onLButtondown(const MOUSEMSG&msg);//左键按下
		void onMousemove(const MOUSEMSG&msg) {}
		void onLButtonup(const MOUSEMSG&msg) {}
		void onRButtonup(const MOUSEMSG&msg) {}

		void onLoad();//加载示例文件
		void onSave();//保存文件
	private:
		bool m_bExit;//是否退出的标志
		Commander *m_pParentCmder;//Parent Commander 指向基类的指针

	};

}