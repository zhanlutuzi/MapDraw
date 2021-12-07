#pragma once
#include "Shape.h"
#include <iostream>

using namespace std;
namespace MapDraw {
	class Point : public Shape
	{
	public:
		Point(int x=0, int y=0);//初始化点
		~Point() = default;
		void Draw() override;//画图
		void Move(int dx, int dy) override;//移动
		int getx() { return m_x; }//得到x
		int gety() { return m_y; }//得到y

	protected:
		bool write(ostream& os) const override;//写入
		bool read(istream& is) override;//读取
	private:
		int	m_x;//x坐标
		int m_y;//y坐标

	};

}