#include "Point.h"
#include <iostream>
using namespace std;

int main()
{
	Point a(2, 2);
	Point b(3, 4);

	Point res(20, 45);
	--res;
	res.Print();
}