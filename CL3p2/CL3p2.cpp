// CL3p2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std; 

class fraction
{
    private:
        double numerator;
        double denominator;
    public:
        void setN1(double _n1)
        {
            numerator = _n1;
        };
        void setN2(double _n2)
        {
            denominator = _n2;
        };
        void setFraction(double _n1, double _n2)
        {
            numerator = _n1;
            denominator = _n2;
        }
        void userSetFraction()
        {
            double t1, t2;
            printf("Input the Numerator (Can't be <= 0): ");
            while (t1 <= 0)
            {
                cin >> t1;
            }
            printf("Input the Denominator (Can't be <= 0): ");
            while (t2 <= 0)
            {
                cin >> t2;
            }
        }
};

int main()
{
    std::cout << "Hello World!\n";
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
