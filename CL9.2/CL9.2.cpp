﻿// CL9.2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "myStr.h"

int main()
{
    myStr str1("The lazy brown dog jumped over the quick red fox");
    myStr str2("Kuva tierlist 2020 real stuff");
    char c = 'i';

    str1.print();
    str2.print();


    /*printf("The character %c within str2 is at index %i\n", c, str2.myChr(c));

    str2.myDelChr(c);
    
    str2.print();

    printf("The string \"real\" in str2 is at index %i\n",str2.myStrStr("real"));

    str1.myStrCat(str2);
    */
    str1.myStrcpy((str1 + c));
    str1.print();
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
