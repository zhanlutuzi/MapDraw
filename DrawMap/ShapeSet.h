#pragma once
#include <iostream>
#include <list>
#include "Shape.h"
//#include "Shape.h"

namespace MapDraw {

	class ShapeSet//һ������
	{
		friend ostream &operator<<(ostream &os, const ShapeSet &shpset);
		friend istream &operator>>(istream &is, ShapeSet &shpset);
	public:
		ShapeSet();
		~ShapeSet();

		void Append(Shape *pshp);//��listĩβ�����
		void Del(int x, int y);
		void Del(int x, int y, int w, int h);
		void Modify();
		void Clear();//�ͷŶ�Ӧ�Ŀռ�
		void Draw() const;//����List�����ø��Զ�Ӧ��Draw��������ͼ

	protected:
		void Search(int x, int y);
		void Search(int x, int y, int w, int h);
	private:
		list <Shape*>	m_lstShape;//list����ָ�룬Ϊ�˴�Ż�ϵĶ���ʵ�ֶ�̬
	};

}