#pragma once
#include<graphics.h>
#include <conio.h>		//_getch
#include <istream>
#include <ostream>
enum NeededCmd {
	WC_NULL,		//null command 无命令
	WC_LOADIMAGE,	//Load Image 加载图片
	WC_LOADVECTOR,	//Load Vector 加载矢量
	WC_NEWVECTOR,	//New Vector 新建矢量
	WC_SAVE,		//Save Vector 保存矢量
	WC_DRAWLINE,	//Draw Line 画线
	WC_DRAWPOINT,   //Draw Point 画点
	WC_DRAWPOLYGON,  //Draw Polygon 画多边形
	WC_MOVE,			//Move 移动
	WC_DELETE,     //Delete 删除
	WC_CHANGEPARAMETER,  //Change Parameter 改变参数
	WC_EXIT = 999	//Exit 退出
};

enum EditType {
	ET_POINT,//点
	ET_LINE,//线
	ET_POLY,//多边形
	ET_MOVE,//移动
	ET_DEL,//删除
	ET_CHANGEPRA,//改变参数
	ET_LAST,//结束标志
};

//新建一个类（Command）用于处理命令
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
	bool isExit() { return m_bExit; };//判断是否结束
private:
	bool m_bExit;
	EditType m_EditType;//绘制的状态
	bool m_bStartEdit;//是否开始编辑的标志
	POINT m_pointFirst;//输入第一个点的坐标
	POINT m_pointLast;//输入最后一个点的坐标
};

