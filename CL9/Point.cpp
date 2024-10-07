#include "Point.h"
#include <iostream>
using namespace std;

Point::Point(int a, int b)
{
	x = a;
	y = b;
}

void Point::Init(int a, int b)
{
	x = a;
	y = b;
}

void Point::Print()const
{
	printf("X: %i;Y: %i\n", this->x, this->y);
}

Point Point::Sum(Point b) const
{
	Point rez;
	rez.x = this->x + b.x;
	rez.y = this->y + b.y;
	return rez;
	//return Point(this->x + b.x, this->y + b.y); // альтернативный короткий синтаксис
}

int Point::Sum(int b) const
{
	return x + y + b;
}

int Point::getX()
{
	return this->x;
}
int Point::getY()
{
	return this->y;
}

//Point Point::operator+(Point b)
//{
//	return Point(this->x + b.x, this->y + b.y);
//}

int Point::operator+(int b)
{
	return x + y + b;
}

//самостоятельное


Point Point::operator-(Point b)
{
	return Point(this->x - b.x, this->y - b.y);
}

int Point::operator*(int b)
{
	return x * y * b;
}

Point Point::operator*(Point b)
{
	return Point(this->x * b.x, this->y * b.y);
}

//Перегрузка унарных операций 
//
//Point& Point::operator--()
//{
//	this->x--;
//	this->y--;
//	return *this;
//}
//Point& Point::operator--(int)
//{
//	Point temp(this->x, this->y);
//	this->x--;
//	this->y--;
//	return temp;
//}
//
//Point& Point::operator++()
//{
//	this->x++;
//	this->y++;
//	return *this;
//}
//
//Point& Point::operator++(int)
//{
//	Point temp(this->x, this->y);
//	this->x++;
//	this->y++;
//	return temp;
//}
//
//Point& Point::operator-=(int a)
//{
//	this->x -= a;
//	this->y -= a;
//	return *this;
//};
//Point& Point::operator*=(int a)
//{
//	this->x *= a;
//	this->y *= a;
//	return *this;
//};
//Point& Point::operator/=(int a)
//{
//	this->x *= a;
//	this->y *= a;
//	return *this;
//};
//
//Point& Point::operator-=(Point a)
//{
//	this->x -= a.x;
//	this->y -= a.y;
//	return *this;
//};
//Point& Point::operator*=(Point a)
//{
//	this->x *= a.x;
//	this->y *= a.y;
//	return *this;
//};
//Point& Point::operator/=(Point a)
//{
//	this->x *= a.x;
//	this->y *= a.y;
//	return *this;
//};
//
//bool Point::operator>(Point a)
//{
//	if ((this->x + this->y) > (a.x + a.y))
//	{
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//};
//bool Point::operator<(Point a)
//{
//	if ((this->x + this->y) > (a.x + a.y))
//	{
//		return false;
//	}
//	else
//	{
//		return true;
//	}
//}
//
//bool Point::operator>=(Point a)
//{
//	if ((this->x + this->y) >= (a.x + a.y))
//	{
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//};
//
//bool Point::operator<=(Point a)
//{
//	if ((this->x + this->y) >= (a.x + a.y))
//	{
//		return false;
//	}
//	else
//	{
//		return true;
//	}
//}
//bool Point::operator==(Point a)
//{
//	if (this->x == a.x && this->y == a.y)
//	{
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//};
//
//bool Point::operator!=(Point a)
//{
//	if (this->x == a.x && this->y == a.y)
//	{
//		return false;
//	}
//	else
//	{
//		return true;
//	}
//};
//
//
//void Point::operator() ()
//{
//	this->Print();
//};
//
//int Point::operator() (int a)
//{
//	return *this + a;
//};

//Point Point::operator() (Point other)
//{
//	return *this + other;
//};

//--------

Point operator+(Point a,Point b)
{
	Point result(a.getX() + b.getX(), a.getY() + b.getY());
	return result;
}

Point& operator+=(Point& a, int b)
{
	a.Init(a.getX() + b, a.getY() + b);

	return a;
};
Point& operator-=(Point& a, int b)
{
	a.Init(a.getX() - b, a.getY() - b);
	return a;
};

Point& operator++(Point& a)
{
	a.Init(a.getX() + 1, a.getY() + 1);
	return a;
};
Point operator++(Point& a, int) 
{
	Point temp(a);
	a.Init(a.getX() + 1, a.getY() + 1);
	return temp;
};

Point& operator--(Point& a)
{
	a.Init(a.getX() - 1, a.getY() - 1);
	return a;
};
Point operator--(Point& a, int)
{
	Point temp(a);
	a.Init(a.getX() - 1, a.getY() - 1);
	return temp;
};

bool operator==(Point& a, Point& b)
{
	if ((a.getX() == b.getX()) && (a.getY() == b.getY()))
	{
		return 1;
	}
	return 0;
};
bool operator!=(Point& a, Point& b)
{
	if ((a.getX() == b.getX()) && (a.getY() == b.getY()))
	{
		return 0;
	}
	return 1;
};

bool operator>(Point& a, Point& b) 
{
	if ((a.getX() > b.getX()) && (a.getY() > b.getY()))
	{
		return 1;
	}
	return 0;
};
