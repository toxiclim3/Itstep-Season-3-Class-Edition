// HW5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstring>
#include "Components.h"
#include "Laptop.h"
using namespace std;

int main()
{
	cpu _cpu("Intel","Atom",2,1.6);
	gpu _gpu("Invidia","GTX 680",4,2,4,2200);
	ram _ram("Kingston","FURY",8,2200);
	ssd _ssd("Kingston 2", "IDk", 220, 1600);

	cpu* cpuP = new cpu(_cpu);
	gpu* gpuP = new gpu(_gpu);
	ram* ramP = new ram(_ram);
	ssd* ssdP = new ssd(_ssd);



	const char* manufacturer = "Asus";
	const char* model = "Thingamabook";
	const char* color = "Gray";


	laptop* thatOne = new laptop(manufacturer,model,color,cpuP, ssdP, gpuP, ramP);

	thatOne->display();

	delete thatOne;

	//cpuP и gpuP удаляются, но я не знаю как их тут делать автоматически nullptr (если вообще можно)

	//cout << gpuP->getModel() << endl; вызывает исключение как и ожидается

	cpuP = nullptr;
	gpuP = nullptr;

	cout << ramP->getModel() << endl;
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
