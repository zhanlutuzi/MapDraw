#pragma once
#include "MenuCommander.h"
#include "DrawCommander.h"
#include "ShapeSet.h"
using namespace std;

namespace MapDraw {
	
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
		ET_NULL,//空
		ET_POINT,//点
		ET_LINE,//线
		ET_POLY,//多边形
		ET_MOVE,//移动
		ET_DEL,//删除
		ET_CHANGEPRA,//改变参数
		ET_LAST,//结束标志
	};

	NeededCmd CheckCommandID(int x, int y);//判断鼠标点击的功能键

	class Commander
	{
	public:
		Commander();
		~Commander()=default;
		void Run();//运行
		inline const EditType getEditType()const { return m_EditType; }//得到编辑类型
		inline void setEditType(EditType nEditType = ET_NULL) { m_EditType = nEditType; }//设置编辑类型
		ShapeSet &getShapeSet() { return m_shapeSet; }//得到形状集合
	protected:
		bool isExit() { return m_menuCmd.isExit(); };//判断是否结束
	private:
		MenuCommander  m_menuCmd;//处理左侧菜单栏的消息
		DrawCommander  m_drawCmd;//处理右侧菜单
		EditType m_EditType;//绘制的状态
		ShapeSet m_shapeSet;//存放形状集合

	};

}