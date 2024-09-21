// HW5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class cpu
{
    private:
        char* manufacturer;
        char* model;
        int cores;
        double frequency;

};

class ssd
{
    private:
        char* manufacturer;
        char* model;
        double frequency; //speed
        int size;
};

class graphicsCard
{
    private:
        char* manufacturer;
        char* model;
        int cores;
        double frequency;
        int vram_size;
        double vram_frequency;
};

class ram
{
    private:
        char* manufacturer;
        char* model;
        int size;
        double frequency;
};

class laptop
{
    private:
        char* manufacturer;
        char* model;

        cpu cpu;
        ssd ssd;
        graphicsCard gpu;
        ram ram;

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
