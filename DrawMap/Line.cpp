
#include "Line.h"

using namespace std;

namespace MapDraw {
	Line::Line()
	{

	}

	Line::Line(const initializer_list<POINT>& pts) :m_nodes(pts)
	{
		
	}

	Line::Line(const vector<POINT>& pts) : m_nodes(pts)
	{
	}

	Line::Line(const POINT* pts, int n) : m_nodes(pts, pts+n)
	{
	}

	Line::~Line()
	{
	}

	void Line::Draw()
	{
		polyline(m_nodes.data(), m_nodes.size());//����EasyX�⺯��
	}

	void Line::Move(int dx, int dy)
	{
		return;
	}

	bool Line::write(ostream &os) const
	{
		os << 1 << "\t" << m_nodes.size() << "\t";
		for (auto&pt : m_nodes)
			os << pt.x << "\t" << pt.y << "\t";
		os << endl;
		return true;
	}

	bool Line::read(istream& is)
	{
		size_t ncount;//size_t ����vcruntime.h
		POINT pt;
		is >> ncount;
		for (int i = 0; i < ncount; ++i)
		{
			is >> pt.x >> pt.y;
			m_nodes.push_back(pt);
		}
		return true;

	}
	ostream &operator<<(ostream &os, const Line &shp)//�������������
	{
		shp.write(os);//ί�и�write����
		return os;
	}
	istream &operator>>(istream &is, Line &shp)//�������������
	{
		shp.read(is);
		return is;
	}
}

