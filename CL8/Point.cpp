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
	this->x = a;
	this->y = b;
}

void Point::Print()
{
	printf("X:%i;Y:%i", x, y);
}

Point Point::operator+(Point& other)
{
	Point res(this->x + other.x, this->y + other.y);
	return res;
}

Point Point::operator-(Point& other)
{
	Point res(this->x - other.x, this->y - other.y);
	return res;
};
Point Point::operator*(Point& other)
{
	Point res(this->x * other.x, this->y * other.y);
	return res;
};
int Point::operator*(int other)
{
	return (this->x * this->y * other);
};
Point Point::operator++()
{
	Point res(this->x += 5, this->y += 5);
	return res;
};
Point Point::operator--()
{
	Point res(this->x -= 5, this->y -= 5);
	return res;
};
