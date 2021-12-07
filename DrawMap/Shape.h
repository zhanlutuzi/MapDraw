#pragma once
#include <iostream>
#include <graphics.h>
using namespace std;

namespace MapDraw {
	class Shape//���麯��
	//�����麯��ʵ�ֶ�̬��֤�ӿڵ�һ����
	{
		friend ostream &operator<<(ostream &os, const Shape &shp);//�������������
		friend istream &operator>>(istream &is, Shape &shp);//�������������
	public:
		Shape();
		virtual ~Shape() = default;

		virtual void Draw() = 0;
		virtual void Move(int dx, int dy) = 0;//�ƶ�

		static Shape* findClone(istream &is);//ͨ���ļ�������б���ţ��ж���Ҫ���Ƶ�ͼ�β��½���Ӧ��ͼ�ζ���

	protected:
		virtual bool write(ostream &os) const = 0;//���麯��
		virtual bool read(istream &is) = 0;//���麯��

		COLORREF	m_penClr;	//������ɫ
		COLORREF	m_fillClr;	//�����ɫ
		int			m_nSize;	//��С
	};
	ostream &operator<<(ostream &os, const Shape &shp);//�������������
	istream &operator>>(istream &is, Shape &shp);//�������������

}