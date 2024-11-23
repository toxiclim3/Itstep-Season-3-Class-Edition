// CL18.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Circle.h"
#include "Square.h"


class circleInASquare : public square,public circle
{
	private:

	public:
		circleInASquare():square(),circle()
		{

		}

		circleInASquare(double size):square(size), circle(size/2)
		{
			
		}

		void print()
		{
			std::cout << "Circle:\n";
			std::cout << "Area:" << circle::getArea() << "\n";
			std::cout << "Radius:" << circle::getRadius() << "\n";
			std::cout << "Diameter:" << circle::getDiameter() << "\n";
			std::cout << "Circumference:" << circle::getCircumference() << "\n\n";

			std::cout << "Square:\n";
			std::cout << "Area:" << square::getArea() << "\n";
			std::cout << "Side length:" << square::getSideLength() << "\n";
		}
};

int main()
{
	circleInASquare wow(6.5);

	wow.print();
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
