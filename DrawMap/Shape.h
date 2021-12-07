#pragma once
#include <iostream>
#include <graphics.h>
using namespace std;

namespace MapDraw {
	class Shape//纯虚函数
	//利用虚函数实现多态保证接口的一致性
	{
		friend ostream &operator<<(ostream &os, const Shape &shp);//重载输出操作符
		friend istream &operator>>(istream &is, Shape &shp);//重载输入操作符
	public:
		Shape();
		virtual ~Shape() = default;

		virtual void Draw() = 0;
		virtual void Move(int dx, int dy) = 0;//移动

		static Shape* findClone(istream &is);//通过文件读入的判别符号，判断需要绘制的图形并新建相应的图形对象

	protected:
		virtual bool write(ostream &os) const = 0;//纯虚函数
		virtual bool read(istream &is) = 0;//纯虚函数

		COLORREF	m_penClr;	//画笔颜色
		COLORREF	m_fillClr;	//填充颜色
		int			m_nSize;	//大小
	};
	ostream &operator<<(ostream &os, const Shape &shp);//重载输出操作符
	istream &operator>>(istream &is, Shape &shp);//重载输入操作符

}