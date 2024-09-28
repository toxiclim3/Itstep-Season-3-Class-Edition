// HW5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstring>
#include "Components.h"
#include "Laptop.h"
using namespace std;

int main()
{
	laptop thatOne("Asus","Omen","Graphite black","Intel","11th gen i7",6,3.4,"Nvidia","RTX 4060 super (real)",6,4,12,3600,"Kingston","FURY",16,3600,"Smasnug","EVO 870",2048,2000);

	thatOne.display();

	laptop theOtherOne(thatOne);

	theOtherOne.display();
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
