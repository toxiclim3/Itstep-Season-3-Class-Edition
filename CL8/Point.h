#pragma once
#include <cstdio>
class Point
{
	int x;
	int y;
public:
	Point() = default;
	Point(int a, int b);
	void Init(int a, int b);
	void Print();

	Point operator+(Point& other);
	Point operator-(Point& other);
	Point operator*(Point& other);
	int operator*(int other);

	Point operator--();
	Point operator++();
};

