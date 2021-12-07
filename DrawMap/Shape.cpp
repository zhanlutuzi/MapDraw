#include <iostream>
#include <graphics.h>
#include "Commander.h"
#include "Point.h"
#include "Line.h"
#include "Polygon.h"
#include "ShapeSet.h"
#include "Shape.h"

namespace MapDraw {

	Shape::Shape()
	{
		m_penClr = RED;//画笔颜色
		m_fillClr = GREEN;//填充颜色
		m_nSize = 1;//大小
	}
	//输入输出流分别委托给read 和 write函数
	ostream&operator<<(ostream& os, const Shape& shp)
	{
		shp.write(os);//委托给write函数
		return os;
	}

	istream& operator>>(istream& is, Shape& shp)
	{
		shp.read(is);
		return is;
	}

	Shape* Shape::findClone(istream& is)
	{
		int type;
		Shape*	pshp = nullptr;
		is >> type;
		switch (type)
		{
		case 0:
			pshp = new Point();
			break;
		case 1:
			pshp = new Line();
			break;
		case 2:
			pshp = new Polygon();
			break;
		default:
			pshp = nullptr;
			break;
		}

		if (pshp)
			is >> (*pshp);//输入流调用read函数
		return pshp;

	}

}