#include "Commander.h"
#include "Point.h"
#include <iostream>
#include <graphics.h>

namespace MapDraw {
	Point::Point(int x, int y) : m_x(x), m_y(y)
	{

	}
	void Point::Draw()
	{
		putpixel(m_x, m_y, RED);
	}

	void Point::Move(int dx, int dy)
	{
		m_x += dx;
		m_y += dy;
	}

	bool Point::write(ostream &os)const
	{
		os << 0 << "\t" << m_x << "\t" << m_y << endl;
		return true;
	}

	bool Point::read(istream &is)
	{
		is >> m_x >> m_y;
		return true;
	}

}