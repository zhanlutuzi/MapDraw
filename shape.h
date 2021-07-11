#include<iostream>
#include<vector>
#include <graphics.h>	//EasyX
#include <conio.h>		//_getch
#include <fstream>
#include <istream>
#include <ostream>
#include <list>
using namespace std;

enum shapetype
{
	PNT,//Point
	POLY,//Polygon
	LINE,//Line
};
class Shape
{
	friend ostream& operator<<(ostream& os, const Shape& shp);
	friend istream& operator>>(istream& is, Shape& shp);
public:
	Shape();
	virtual ~Shape() = default;

	virtual void Draw() = 0;
	virtual void Move(int dx, int dy) = 0;

protected:
	virtual bool write(ostream& os) const = 0;
	virtual bool read(istream& is) = 0;

	COLORREF	m_penClr;	//������ɫ
	COLORREF	m_fillClr;	//�����ɫ
	int			m_nSize;	//��С
};

ostream& operator<<(ostream& os, const Shape& shp);
istream& operator>>(istream& is, Shape& shp);

class Point : public Shape
{
public:
	Point(int x , int y );
	~Point() = default;
	void Draw() override;
	void Move(int dx, int dy) override;
	int getx() { return m_x; }
	int gety() { return m_y; }
	int			m_x, m_y;
protected:
	bool write(ostream& os) const override;
	bool read(istream& is) override;


};

class Line : public Shape
{
public:
	Line(Point* const pts , int n);//�����int n ��ʲô�ã�����ʲô��
	Line(const initializer_list<Point>& pts);
	~Line();

	void Draw() override;
	void Move(int dx, int dy) override;

protected:
	bool write(ostream& os) const override;//Ϊʲô��bool���ͣ�
	bool read(istream& is) override;

private:
	vector<Point>	m_nodes;//�洢����vector������
};

class Polygon:public Point
{
public:
	Polygon(Point&p1, Point&p2, Point&p3, Point&p4);
	Polygon(Polygon &poly);
	~Polygon();
	
	void Draw() override;
	void Move(int change_x, int change_y);//x,y�����ϵĸı���
protected:
	//bool write(ostream& os) const override;
	//bool read(istream& is) override;

private:
	
	vector<Point>	m_nodes;//�˵�
};

class ShapeSet
{
	friend ostream& operator<<(ostream& os, const ShapeSet& shpset);
	friend istream& operator>>(istream& is, ShapeSet& shpset);
public:
	ShapeSet();
	~ShapeSet();

	void Append(Shape* pshp);
	void Del(int x, int y);
	void Del(int x, int y, int w, int h);
	void Modify();

	void Draw() const;

protected:
	void Search(int x, int y);
	void Search(int x, int y, int w, int h);
private:
	list<Shape*>	m_lstShape;
};

