#include "Commander.h"
#include "ShapeSet.h"
#include "Shape.h"
#include <iostream>

namespace MapDraw {
	ShapeSet::ShapeSet()
	{

	}

	ShapeSet::~ShapeSet()
	{
		Clear();
	}

	void ShapeSet::Append(Shape* pshp)
	{
		if (pshp)
			m_lstShape.push_back(pshp);
	}

	void ShapeSet::Clear()//用来释放动态空间，在
	{
		while (!m_lstShape.empty())
		{//rbegin返回的是一个指针，故应该用一个“*”解引用符
			delete(*m_lstShape.rbegin());//List 的rbegin() 返回指向第一个元素的逆向迭代器 
			m_lstShape.pop_back();//删除最后一个元素
		}
	}

	void ShapeSet::Draw()const
	{
		for (auto&pshp : m_lstShape)//遍历list
		{
			if (pshp)pshp->Draw();
		}
	}

	void ShapeSet::Search(int x, int y, int w, int h)
	{

	}

	void ShapeSet::Search(int x, int y)//查找周围是否有点、线、等等，返回他们的地址
	{

	}

	ostream& operator<<(ostream &os, const ShapeSet &shpset)//存到文件里，重载输出符号
	{
		for (auto&pshp : shpset.m_lstShape)
			os << (*pshp);//每个形状的写也交给每个形状自己的函数操作
		return os;
	}

	istream& operator>>(istream &is, ShapeSet &shpset)
	{
		while (!is.eof())
		{
			Shape  *pshp = Shape::findClone(is);
			if (pshp)	shpset.Append(pshp);
		}
		return is;
	}

	void ShapeSet::Del(int x, int y, int w, int h)
	{

	}

	void ShapeSet::Del(int x, int y)
	{

	}

	void ShapeSet::Modify()
	{

	}

}