// CL3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class point
{
public:
	void input()
	{
		printf("\nInput the x coordinate:");
		cin >> x;
		printf("\nInput the y coordinate:");
		cin >> y;
	};
	void display()
	{
		printf("\nThis point's coordinates are: %F;%F", x, y);
	};

	double getX()
	{
		return x;
	}
	double getY()
	{
		return y;
	}

	void setX(double _x)
	{
		x = _x;
	}
	void setY(double _y)
	{
		y = _y;
	}

	void setCoords(double _x, double _y)
	{
		x = _x;
		y = _y;
	}

	point combineWithPoint(point b)
	{
		point result;
		result.setX( getX() + b.getX() );
		result.setY( getY() + b.getY() );
		return result;
	}
private:

	double x;
	double y;

};

int main()
{
	point player;
	//player.input();
	//point thing;
	//thing.input();

	//point secretThirdThing;
	//secretThirdThing = player.combineWithPoint(thing);

	player.setCoords(68.45, 7759.645);

	player.display();
	//thing.display();
	//secretThirdThing.display();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
