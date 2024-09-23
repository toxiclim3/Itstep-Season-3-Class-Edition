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
	public:
		cpu(char* manuf, char* model, int cores, double frequency):cores(cores),frequency(frequency)
		{
			this->manufacturer = new char[strlen(manuf) + 1];
			strcpy_s(this->manufacturer, strlen(manuf) + 1, manuf);

			this->model = new char[strlen(model) + 1];
			strcpy_s(this->model, strlen(model) + 1, model);
		}
};

class ssd
{
	private:
		char* manufacturer;
		char* model;
		double frequency; //speed
		int size;
	public:
		ssd(char* manuf, char* model, int size, double frequency) : size(size), frequency(frequency)
		{
			this->manufacturer = new char[strlen(manuf) + 1];
			strcpy_s(this->manufacturer, strlen(manuf) + 1, manuf);

			this->model = new char[strlen(model) + 1];
			strcpy_s(this->model, strlen(model) + 1, model);
		}
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
	public:
		graphicsCard(char* manuf, char* model, int cores, double frequency,int vram_size,double vram_freq) : cores(cores), frequency(frequency),vram_size(vram_size),vram_frequency(vram_freq)
		{
			this->manufacturer = new char[strlen(manuf) + 1];
			strcpy_s(this->manufacturer, strlen(manuf) + 1, manuf);

			this->model = new char[strlen(model) + 1];
			strcpy_s(this->model, strlen(model) + 1, model);
		}
};

class ram
{
	private:
		char* manufacturer;
		char* model;
		int size;
		double frequency;
	public:
		ram(char* manuf, char* model, int size, double frequency) : size(size), frequency(frequency)
		{
			this->manufacturer = new char[strlen(manuf) + 1];
			strcpy_s(this->manufacturer, strlen(manuf) + 1, manuf);

			this->model = new char[strlen(model) + 1];
			strcpy_s(this->model, strlen(model) + 1, model);
		}
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
	public:

		laptop(char* manuf, char* model, char* cpu_manuf, char* cpu_model, int cpu_cores, double cpu_frequency, char* gpu_manuf, char* gpu_model, int gpu_cores, double gpu_frequency, int gpu_vram_size, double gpu_vram_freq, char* ram_manuf, char* ram_model, int ram_size, double ram_frequency) : cpu(cpu_manuf,cpu_model,cpu_cores,cpu_frequency), gpu(gpu_manuf,gpu_model,gpu_cores,gpu_frequency,gpu_vram_size,gpu_vram_freq), ram(ram_manuf,ram_model,ram_size,ram_frequency), vram_frequency(vram_freq)
		{
			this->manufacturer = new char[strlen(manuf) + 1];
			strcpy_s(this->manufacturer, strlen(manuf) + 1, manuf);

			this->model = new char[strlen(model) + 1];
			strcpy_s(this->model, strlen(model) + 1, model);
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
