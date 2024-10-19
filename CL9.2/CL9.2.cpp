// CL9.2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "myStr.h"

int main()
{
	//Я каждый блок кода (отделены пустыми комментариями) проверял, все работают нормально, но когда всё вместе, то происходит ошибка доступа в конце программы (после всех деструкторов)
	//Я не понимаю как это работает
	//
	myStr str1("The lazy brown dog jumped over the quick red fox");
	myStr str2("I randomly get a memory exception when destroying objects for some reason");
	myStr temp;
	char c = 'i';

	str1.print();
	str2.print();

	/*

	myStr str_initlist{ 'C', 'o', 'o', 'l', ' ','o','r',' ','n','o','t','?','\0' };
	str_initlist.print();

	printf("\n-------------\n");

	printf("The character %c within str2 is at index %i\n", c, str2.myChr(c));

	str2.myDelChr(c);

	str2.print();

	const char* search = "real";
	const char* search2 = "that";
	printf("The string \"%s\" in str2 is at index %i\n", search, str2.myStrStr(search));
	printf("The string \"%s\" in str2 is at index %i\n", search2, str2.myStrStr(search2));

	str1.myStrCat(str2);
	str1.print();

	//

	printf("\n-------------\n");
	myStr str3a("AAAAA");

	myStr str3b(str3a + c);
	str3b.print();

	myStr str4(c + str3a);
	str3b(str4);
	str3b.print();

	printf("\n-------------\n");
	//

	myStr str5("Cool text");
	myStr str6("Cooler text");

	int index = 5;
	printf("The %i-th character of the text \"%s\" is % c", index, str5.getText(), str5[index]);

	myStr str5res(str5);
	str5res = str5 + 5;
	myStr str6res(str6);
	str6res = 5 + str6;

	str5res.print();
	str6res.print();

	str5res++;
	str5res.print();

	++str6res;
	str6res.print();
	*/

	myStr str1EqualsStr1 = str1;
	str1EqualsStr1.print();

	printf("\nstr1EqualsStr1 after copying str2:\n");

	str1EqualsStr1 = str2;
	str1EqualsStr1 = str1EqualsStr1;

	str1EqualsStr1.print();

	std::cin >> str1EqualsStr1;

	std::cout << "New text: " << str1EqualsStr1 << "\n";

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
