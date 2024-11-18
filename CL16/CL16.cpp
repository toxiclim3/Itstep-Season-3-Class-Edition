#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"
#include <iostream>
using namespace std;

/*

       ����: ���������� (���������)

       1.�������� �� ������� ����� ���� ���������� �� ����� �������

       ��������: ������ �������� �����

       ��'�������� - ���������� ����� ���� ����� ��������� ���� ����������������� ��� ����������� �������
       ���� ��'�������� - ��'�������� �� ���� ��������� ��������, �� ����� �������������� ��'���� ����������� ��������� (��������� ����������)
       ϳ���� ��'�������� - ��'�������� �� ���� ������ �������� (��������� ����������)

       1.�������������� ������� ����� virtual � �������� ����
       2.C�������� ������ ����� ���� �������

*/

int main()
{
    Circle circle;
    Rectangle rectangle;
    Triangle triangle;

    circle.SetDimension(10.0);
    circle.ShowArea();
    
    rectangle.SetDimension(5.5, 10.0);
    rectangle.ShowArea();

    triangle.SetDimension(5.5, 10.0);
    triangle.ShowArea();

 

   
    return 0;
}