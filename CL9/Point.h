#pragma once
class Point
{
	int x;
	int y;
public:
	Point() = default;
	Point(int a, int b);

	void Init(int a, int b);
	void Print() const;

	Point Sum(Point b) const;
	int Sum(int b) const;

	int getX();
	int getY();


	//ѕреобразовуем наши методы в операции
	//Point operator+(Point b);
	int operator+(int b);

	//самосто€тельное
	Point operator-(Point b);
	int operator*(int b);
	Point operator*(Point b);

	//ѕерегрузка унарных операций
	/*Point& operator++();
	Point& operator++(int);

	Point& operator--();
	Point& operator--(int);

	Point& operator-=(int);
	Point& operator*=(int);
	Point& operator/=(int);

	Point& operator-=(Point);
	Point& operator*=(Point);
	Point& operator/=(Point);

	bool operator>(Point);
	bool operator<(Point);

	bool operator>=(Point);
	bool operator<=(Point);

	bool operator==(Point);
	bool operator!=(Point);

	void operator() ();
	int operator() (int a);*/
	//Point operator() (Point other);
};

Point operator+(const Point a, const Point b);

Point& operator+=(Point& a, int b);
Point& operator-=(Point& a, int b);

Point& operator++(Point& a);
Point operator++(Point& a, int);

Point& operator--(Point& a);
Point operator--(Point& a, int);

bool operator==(Point& a, Point& b);
bool operator!=(Point& a, Point& b);

bool operator>(Point& a, Point& b);