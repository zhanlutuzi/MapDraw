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

	void ShapeSet::Clear()//�����ͷŶ�̬�ռ䣬��
	{
		while (!m_lstShape.empty())
		{//rbegin���ص���һ��ָ�룬��Ӧ����һ����*�������÷�
			delete(*m_lstShape.rbegin());//List ��rbegin() ����ָ���һ��Ԫ�ص���������� 
			m_lstShape.pop_back();//ɾ�����һ��Ԫ��
		}
	}

	void ShapeSet::Draw()const
	{
		for (auto&pshp : m_lstShape)//����list
		{
			if (pshp)pshp->Draw();
		}
	}

	void ShapeSet::Search(int x, int y, int w, int h)
	{

	}

	void ShapeSet::Search(int x, int y)//������Χ�Ƿ��е㡢�ߡ��ȵȣ��������ǵĵ�ַ
	{

	}

	ostream& operator<<(ostream &os, const ShapeSet &shpset)//�浽�ļ�������������
	{
		for (auto&pshp : shpset.m_lstShape)
			os << (*pshp);//ÿ����״��дҲ����ÿ����״�Լ��ĺ�������
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