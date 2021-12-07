#pragma once

#include "Shape.h"
#include "Point.h"
#include <vector>


namespace MapDraw {
	class Line : public Shape
	{
	public:
		Line();
		Line(const POINT* pts, int n);//n->点的数量
		Line(const vector<POINT>& pts);//传入vector来初始化m_nodes
		Line(const initializer_list<POINT>& pts);//传入initializer_list来初始化m_nodes
		~Line();
		friend ostream &operator<<(ostream &os, const Line &shp);//重载输出操作符
		friend istream &operator>>(istream &is, Line &shp);//重载输入操作符
		void Draw() override;//画线
		void Move(int dx, int dy) override;//移动

	protected:
		bool write(ostream& os) const override;//写入文件
		bool read(istream& is) override;//读取文件

	private:
		vector<POINT>	m_nodes;//存储点于vector容器中
		//这里的POINT属于(windef.h)
	};
	 ostream &operator<<(ostream &os, const Line &shp);//重载输出操作符
	 istream &operator>>(istream &is, Line &shp);//重载输入操作符
}
