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
		Polygon(const POINT* pts, int n);//用POINT的指针来初始化
		Polygon(const vector<POINT>& pts);//用vector初始化
		Polygon(const initializer_list<POINT>& pts);//用初始化列表初始化
		~Polygon() = default;
		friend ostream &operator<<(ostream &os, const Polygon &shp);//重载输出操作符
		friend istream &operator>>(istream &is, Polygon &shp);//重载输入操作符
		void Draw() override;//画图

	protected:
		bool write(ostream& os) const override;//写入
		bool read(istream& is) override;//读入

	private:

		vector<POINT>	m_nodes;//属于Polygon的点集
		//这里的POINT属于(windef.h)
	};

ostream &operator<<(ostream &os, const Polygon &shp);//重载输出操作符
istream &operator>>(istream &is, Polygon &shp);//重载输入操作符

}

