#include "Point.h"
#include <iostream>
using namespace std;



int main()
{	
	Point a(1, 2);
	Point b(3, 4);	

	int res = a > b;
	printf("The result is %i\n", res);

	res = a == b;
	printf("The result is %i\n", res);

	res = a != b;
	printf("The result is %i\n", res);

	a--;
	a.Print();

	b -= 2;
	b.Print();
}