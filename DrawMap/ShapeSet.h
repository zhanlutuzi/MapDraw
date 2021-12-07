#pragma once
#include <iostream>
#include <list>
#include "Shape.h"
//#include "Shape.h"

namespace MapDraw {

	class ShapeSet//一个集合
	{
		friend ostream &operator<<(ostream &os, const ShapeSet &shpset);
		friend istream &operator>>(istream &is, ShapeSet &shpset);
	public:
		ShapeSet();
		~ShapeSet();

		void Append(Shape *pshp);//从list末尾添加类
		void Del(int x, int y);
		void Del(int x, int y, int w, int h);
		void Modify();
		void Clear();//释放对应的空间
		void Draw() const;//遍历List，调用各自对应的Draw函数来绘图

	protected:
		void Search(int x, int y);
		void Search(int x, int y, int w, int h);
	private:
		list <Shape*>	m_lstShape;//list里存放指针，为了存放混合的对象实现多态
	};

}