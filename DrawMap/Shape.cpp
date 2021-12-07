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
		m_penClr = RED;//������ɫ
		m_fillClr = GREEN;//�����ɫ
		m_nSize = 1;//��С
	}
	//����������ֱ�ί�и�read �� write����
	ostream&operator<<(ostream& os, const Shape& shp)
	{
		shp.write(os);//ί�и�write����
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
			is >> (*pshp);//����������read����
		return pshp;

	}

}