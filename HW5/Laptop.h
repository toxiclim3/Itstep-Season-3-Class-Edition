#pragma once

#include "Components.h"

class laptop
{
private:
	char* manufacturer;
	char* model;
	char* color;

	cpu cpu;
	ssd ssd;
	graphicsCard gpu;
	ram ram;
public:

	laptop(const char* manuf, const char* model, const char* color, const char* cpu_manuf, const char* cpu_model, int cpu_cores, double cpu_frequency, const char* gpu_manuf, const char* gpu_model, int gpu_cores, double gpu_frequency, int gpu_vram_size, double gpu_vram_freq, const char* ram_manuf, const char* ram_model, int ram_size, double ram_frequency, const char* ssd_manuf, const char* ssd_model, int ssd_size, double ssd_frequency) : cpu(cpu_manuf, cpu_model, cpu_cores, cpu_frequency), gpu(gpu_manuf, gpu_model, gpu_cores, gpu_frequency, gpu_vram_size, gpu_vram_freq), ram(ram_manuf, ram_model, ram_size, ram_frequency), ssd(ssd_manuf, ssd_model, ssd_size, ssd_frequency)
	{
		this->manufacturer = new char[strlen(manuf) + 1];
		strcpy_s(this->manufacturer, strlen(manuf) + 1, manuf);

		this->model = new char[strlen(model) + 1];
		strcpy_s(this->model, strlen(model) + 1, model);

		this->color = new char[strlen(color) + 1];
		strcpy_s(this->color, strlen(color) + 1, color);
	}
	laptop(char* manuf, char* model, char* color, char* cpu_manuf, char* cpu_model, int cpu_cores, double cpu_frequency, char* gpu_manuf, char* gpu_model, int gpu_cores, double gpu_frequency, int gpu_vram_size, double gpu_vram_freq, char* ram_manuf, char* ram_model, int ram_size, double ram_frequency, char* ssd_manuf, char* ssd_model, int ssd_size, double ssd_frequency) : cpu(cpu_manuf, cpu_model, cpu_cores, cpu_frequency), gpu(gpu_manuf, gpu_model, gpu_cores, gpu_frequency, gpu_vram_size, gpu_vram_freq), ram(ram_manuf, ram_model, ram_size, ram_frequency), ssd(ssd_manuf, ssd_model, ssd_size, ssd_frequency)
	{
		this->manufacturer = new char[strlen(manuf) + 1];
		strcpy_s(this->manufacturer, strlen(manuf) + 1, manuf);

		this->model = new char[strlen(model) + 1];
		strcpy_s(this->model, strlen(model) + 1, model);

		this->color = new char[strlen(color) + 1];
		strcpy_s(this->color, strlen(color) + 1, color);
	}
	laptop(laptop& other) : cpu(other.cpu), gpu(other.gpu), ram(other.ram), ssd(other.ssd)
	{
		printf("\n\nLaptop duplicated!\n\n");

		this->manufacturer = new char[strlen(other.manufacturer) + 1];
		strcpy_s(this->manufacturer, strlen(other.manufacturer) + 1, other.manufacturer);

		this->model = new char[strlen(other.model) + 1];
		strcpy_s(this->model, strlen(other.model) + 1, other.model);

		this->color = new char[strlen(other.color) + 1];
		strcpy_s(this->color, strlen(other.color) + 1, other.color);
	}

	void display()
	{
		printf("Laptop:\n-Manufacturer:%s\n-Model:%s\n-Color:%s\n----", this->manufacturer, this->model, this->color);
		printf("CPU:\n-Manufacturer:%s\n-Model:%s\n-Cores:%i\n-Frequency:%f\n----", this->cpu.getManuf(), this->cpu.getModel(), this->cpu.getCores(), this->cpu.getFrequency());
		printf("GPU:\n-Manufacturer:%s\n-Model:%s\n-Cores:%i\n-Frequency:%f\n-VRAM size:%iGB\n-VRAM frequency:%f\n----", this->gpu.getManuf(), this->gpu.getModel(), this->gpu.getCores(), this->gpu.getFrequency(), this->gpu.getVramSize(), this->gpu.getVramFrequency());
		printf("RAM:\n-Manufacturer:%s\n-Model:%s\n-Size:%iGB\n-Frequency:%f\n----", this->ram.getManuf(), this->ram.getModel(), this->ram.getSize(), this->gpu.getFrequency());
		printf("RAM:\n-Manufacturer:%s\n-Model:%s\n-Capacity:%iGB\n-Max speed:%f\n----", this->ssd.getManuf(), this->ssd.getModel(), this->ssd.getSize(), this->ssd.getFrequency());
	}
};