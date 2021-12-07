#pragma once
#include "Shape.h"
#include <iostream>

using namespace std;
namespace MapDraw {
	class Point : public Shape
	{
	public:
		Point(int x=0, int y=0);//��ʼ����
		~Point() = default;
		void Draw() override;//��ͼ
		void Move(int dx, int dy) override;//�ƶ�
		int getx() { return m_x; }//�õ�x
		int gety() { return m_y; }//�õ�y

	protected:
		bool write(ostream& os) const override;//д��
		bool read(istream& is) override;//��ȡ
	private:
		int	m_x;//x����
		int m_y;//y����

	};

}