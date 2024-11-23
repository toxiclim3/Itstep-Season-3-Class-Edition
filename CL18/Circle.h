#pragma once

#define _USE_MATH_DEFINES
#include <math.h>;

class circle
{
	protected:
		double radius;
		double diameter;
		double circumference;
	public:
		circle()
		{
			radius = 0;
			diameter = 0;
			circumference = 0;
		}

		circle(double r)
		{
			radius = r;
			diameter = radius * 2;
			circumference = 2 * M_PI * radius;
		}

		double getRadius()
		{
			return radius;
		}

		double getDiameter()
		{
			return diameter;
		}

		double getCircumference()
		{
			return circumference;
		}

		double getArea()
		{
			return M_PI * pow(radius, 2);
		}
};