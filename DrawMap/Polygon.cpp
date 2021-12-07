
#include "Polygon.h"
namespace MapDraw {
	Polygon::Polygon()
	{

	}
	Polygon::Polygon(const POINT* pts, int n) : Line(pts, n)
	{

	}
	Polygon::Polygon(const vector<POINT>& pts) : Line(pts)
	{
		m_nodes = pts;
	}

	Polygon::Polygon(const initializer_list<POINT>& pts) : Line(pts)
	{
		m_nodes = pts;
	}

	void Polygon::Draw()
	{
		polygon(m_nodes.data(), m_nodes.size());//����esayx�Ŀ⺯��
	}



	bool Polygon::write(ostream &os)const
	{
		os << 2 << "\t" << m_nodes.size() << "\t";
		for (auto &pt : m_nodes)//polygon size=0�ˣ�
			os << pt.x << "\t" << pt.y << "\t";
		os << endl;
		return true;
	}

	bool Polygon::read(istream& is)
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

	ostream &operator<<(ostream &os, const Polygon &shp)//�������������
	{
		shp.write(os);
		return os;
	}
	istream &operator>>(istream &is, Polygon &shp)//�������������
	{
		shp.read(is);
		return is;
	}
	/*
	bool Polygon::read(istream& is)
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
	*/
}