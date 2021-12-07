#pragma once
#include "Shape.h"
#include <graphics.h>
#include "Line.h"
#include <vector>
using namespace std;

namespace MapDraw {
	class Polygon :public Line
	{
	public:
		Polygon();
		Polygon(const POINT* pts, int n);//��POINT��ָ������ʼ��
		Polygon(const vector<POINT>& pts);//��vector��ʼ��
		Polygon(const initializer_list<POINT>& pts);//�ó�ʼ���б��ʼ��
		~Polygon() = default;
		friend ostream &operator<<(ostream &os, const Polygon &shp);//�������������
		friend istream &operator>>(istream &is, Polygon &shp);//�������������
		void Draw() override;//��ͼ

	protected:
		bool write(ostream& os) const override;//д��
		bool read(istream& is) override;//����

	private:

		vector<POINT>	m_nodes;//����Polygon�ĵ㼯
		//�����POINT����(windef.h)
	};

ostream &operator<<(ostream &os, const Polygon &shp);//�������������
istream &operator>>(istream &is, Polygon &shp);//�������������

}

