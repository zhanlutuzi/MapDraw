#pragma once

#include "Shape.h"
#include "Point.h"
#include <vector>


namespace MapDraw {
	class Line : public Shape
	{
	public:
		Line();
		Line(const POINT* pts, int n);//n->�������
		Line(const vector<POINT>& pts);//����vector����ʼ��m_nodes
		Line(const initializer_list<POINT>& pts);//����initializer_list����ʼ��m_nodes
		~Line();
		friend ostream &operator<<(ostream &os, const Line &shp);//�������������
		friend istream &operator>>(istream &is, Line &shp);//�������������
		void Draw() override;//����
		void Move(int dx, int dy) override;//�ƶ�

	protected:
		bool write(ostream& os) const override;//д���ļ�
		bool read(istream& is) override;//��ȡ�ļ�

	private:
		vector<POINT>	m_nodes;//�洢����vector������
		//�����POINT����(windef.h)
	};
	 ostream &operator<<(ostream &os, const Line &shp);//�������������
	 istream &operator>>(istream &is, Line &shp);//�������������
}
