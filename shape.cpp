#include "shape.h"

Shape::Shape()
{
	m_penClr = RED;	//画笔颜色
	m_fillClr = GREEN;	//填充颜色
	m_nSize = 1;	//大小
}

ostream& operator<<(ostream& os, const Shape& shp)//利用输出流
{
	shp.write(os);
	return os;
}

istream& operator>>(istream& is, Shape& shp)//利用输入流
{
	//shp.read(is);
	return is;
}

Point::Point(int x = 0, int y = 0)//初始化点
{
	m_x = x;
	m_y = y;
}

void Point::Draw()//画点
{
	putpixel(m_x, m_y, m_penClr);
}

void Point::Move(int dx, int dy)
{
	m_x += dx;
	m_y += dy;
}

bool Point::write(ostream& os) const
{
	os << PNT << "\t" << m_x << "\t" << m_y << endl;
	return true;
}

bool Point::read(istream& is)
{
	is >> m_x >> m_y;
	return true;
}

Line::Line(Point* const pts , int n)
{
	m_nodes.push_back(*pts);
}

Line::Line(const initializer_list<Point>& pts)
{
	for (auto it = pts.begin(); it != pts.end(); ++it)
	{
		m_nodes.push_back(*it);
	}
}

Line::~Line()
{
	m_nodes.clear();
}

void Line::Draw()
{
	for (auto it = m_nodes.begin(); it != m_nodes.end(); ++it)
	{
		line(it->getx(), it->gety(), (it+1)->getx(), (it+1)->gety());
	}
	
}

void Line::Move(int dx, int dy)
{
	for (auto it = m_nodes.begin(); it != m_nodes.end(); ++it)
	{
		it->Move(dx, dy);
	}
}

bool Line::write(ostream& os) const
{
	os << LINE << "\t" << m_nodes.size() << "\t";
	for (auto& pt : m_nodes)
		os << pt.m_x << "\t" << pt.m_y;
	os << endl;
	return true;
}

bool Line::read(istream& is)
{

}

Polygon::Polygon(Point&p1, Point&p2, Point&p3, Point&p4)
{
	m_nodes = { p1,p2,p3,p4 };
}

Polygon::Polygon(Polygon &poly)
{
	m_nodes = poly.m_nodes;
}

Polygon::~Polygon()
{
	m_nodes.clear();
}

void Polygon::Draw()
{
	for (int n = 0; n < 5; n++)
	{
		line(m_nodes[n].getx(), m_nodes[n].gety(), m_nodes[n + 1].getx(), m_nodes[n + 1].gety());
	}
}

void Polygon::Move(int change_x, int change_y)
{
	for (int n = 0; n < 5; n++)
	{
		m_nodes[n].m_x += change_x;
		m_nodes[n].m_y += change_y;
	}
}

ShapeSet::~ShapeSet()
{
	while (!m_lstShape.empty())
	{
		delete (*m_lstShape.rbegin());
		m_lstShape.pop_back();
	}
}

void ShapeSet::Append(Shape* pshp)
{
	if (pshp)
		m_lstShape.push_back(pshp);
}

void ShapeSet::Draw() const
{
	for (auto iter = m_lstShape.begin(); iter != m_lstShape.end(); ++iter)
		(*iter)->Draw();
}

ostream& operator<<(ostream& os, const ShapeSet& shpset)
{
	return os;
}

istream& operator>>(istream& is, ShapeSet& shpset)
{
	return is;
}