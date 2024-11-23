#pragma once


class square
{
	protected:
		double sideLength;
		double area;
	public:
		square()
		{
			sideLength = 0;
			area = 0;
		}

		square(double l)
		{
			sideLength = l;
			area = sideLength * sideLength;
		}

		double getArea()
		{
			return area;
		}
		double getSideLength()
		{
			return sideLength;
		}

};