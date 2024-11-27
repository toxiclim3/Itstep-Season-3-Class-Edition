#pragma once

#include "Components.h"

class laptop
{
private:
	char* manufacturer;
	char* model;
	char* color;

	cpu* cpuP;
	ssd* ssdP;
	gpu* gpuP;
	ram* ramP;
public:
	laptop(const char* manuf, const char* model, const char* color, cpu* cpu, ssd* ssd, gpu* gpu, ram* ram)
	{
		this->manufacturer = new char[strlen(manuf) + 1];
		strcpy_s(this->manufacturer, strlen(manuf) + 1, manuf);

		this->model = new char[strlen(model) + 1];
		strcpy_s(this->model, strlen(model) + 1, model);

		this->color = new char[strlen(color) + 1];
		strcpy_s(this->color, strlen(color) + 1, color);

		this->cpuP = cpu;
		this->ssdP = ssd;
		this->gpuP = gpu;
		this->ramP = ram;
	}

	laptop(char* manuf,char* model,char* color,cpu* cpu,ssd* ssd,gpu* gpu,ram* ram)
	{
		this->manufacturer = new char[strlen(manuf) + 1];
		strcpy_s(this->manufacturer, strlen(manuf) + 1, manuf);

		this->model = new char[strlen(model) + 1];
		strcpy_s(this->model, strlen(model) + 1, model);

		this->color = new char[strlen(color) + 1];
		strcpy_s(this->color, strlen(color) + 1, color);

		this->cpuP = cpu;
		this->ssdP = ssd;
		this->gpuP = gpu;
		this->ramP = ram;
	}

	laptop(laptop& other) : cpuP(other.cpuP), gpuP(other.gpuP), ramP(other.ramP), ssdP(other.ssdP)
	{
		printf("\n\nLaptop duplicated!\n\n");

		this->manufacturer = new char[strlen(other.manufacturer) + 1];
		strcpy_s(this->manufacturer, strlen(other.manufacturer) + 1, other.manufacturer);

		this->model = new char[strlen(other.model) + 1];
		strcpy_s(this->model, strlen(other.model) + 1, other.model);

		this->color = new char[strlen(other.color) + 1];
		strcpy_s(this->color, strlen(other.color) + 1, other.color);
	}

	~laptop()
	{
		if (this->manufacturer != nullptr)
		{
			delete[] this->manufacturer;
			this->manufacturer = nullptr;
		}

		if (this->model != nullptr)
		{
			delete[] this->model;
			this->model = nullptr;
		}

		if (this->color != nullptr)
		{
			delete[] this->color;
			this->color = nullptr;
		}

		if (this->cpuP != nullptr)
		{
			delete[] this->cpuP;
			this->cpuP = nullptr;
		}

		if (this->gpuP != nullptr)
		{
			delete[] this->gpuP;
			this->gpuP = nullptr;
		}
	}

	void display()
	{
		printf("Laptop:\n-Manufacturer:%s\n-Model:%s\n-Color:%s\n----", this->manufacturer, this->model, this->color);
		printf("CPU:\n-Manufacturer:%s\n-Model:%s\n-Cores:%i\n-Frequency:%f\n----", cpuP->getManuf(), cpuP->getModel(), cpuP->getCores(), cpuP->getFrequency());
		printf("GPU:\n-Manufacturer:%s\n-Model:%s\n-Cores:%i\n-Frequency:%f\n-VRAM size:%iGsB\n-VRAM frequency:%f\n----", gpuP->getManuf(), gpuP->getModel(), gpuP->getCores(), gpuP->getFrequency(), gpuP->getVramSize(), gpuP->getVramFrequency());
		printf("RAM:\n-Manufacturer:%s\n-Model:%s\n-Size:%iGB\n-Frequency:%f\n----", ramP->getManuf(), ramP->getModel(), ramP->getSize(), gpuP->getFrequency());
		printf("RAM:\n-Manufacturer:%s\n-Model:%s\n-Capacity:%iGB\n-Max speed:%f\n----\n", ssdP->getManuf(), ssdP->getModel(), ssdP->getSize(), ssdP->getFrequency());
	}
};

