#pragma once

class cpu
{
private:
	char* manufacturer;
	char* model;
	int cores;
	double frequency;
public:
	cpu() = default;

	cpu(const char* manuf, const char* model, int cores, double frequency) : cores(cores), frequency(frequency)
	{
		this->manufacturer = new char[strlen(manuf) + 1];
		strcpy_s(this->manufacturer, strlen(manuf) + 1, manuf);

		this->model = new char[strlen(model) + 1];
		strcpy_s(this->model, strlen(model) + 1, model);
	}
	cpu(char* manuf, char* model, int cores, double frequency) : cores(cores), frequency(frequency)
	{
		this->manufacturer = new char[strlen(manuf) + 1];
		strcpy_s(this->manufacturer, strlen(manuf) + 1, manuf);

		this->model = new char[strlen(model) + 1];
		strcpy_s(this->model, strlen(model) + 1, model);
	}
	cpu(cpu& other) : cores(other.cores), frequency(other.frequency)
	{
		this->manufacturer = new char[strlen(other.manufacturer) + 1];
		strcpy_s(this->manufacturer, strlen(other.manufacturer) + 1, other.manufacturer);

		this->model = new char[strlen(other.model) + 1];
		strcpy_s(this->model, strlen(other.model) + 1, other.model);
	}

	char* getManuf()
	{
		return this->manufacturer;
	}
	char* getModel()
	{
		return this->model;
	}
	int getCores()
	{
		return this->cores;
	}
	double getFrequency()
	{
		return this->frequency;
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
	ssd() = default;

	ssd(const char* manuf, const char* model, int size, double frequency) : size(size), frequency(frequency)
	{
		this->manufacturer = new char[strlen(manuf) + 1];
		strcpy_s(this->manufacturer, strlen(manuf) + 1, manuf);

		this->model = new char[strlen(model) + 1];
		strcpy_s(this->model, strlen(model) + 1, model);
	}
	ssd(char* manuf, char* model, int size, double frequency) : size(size), frequency(frequency)
	{
		this->manufacturer = new char[strlen(manuf) + 1];
		strcpy_s(this->manufacturer, strlen(manuf) + 1, manuf);

		this->model = new char[strlen(model) + 1];
		strcpy_s(this->model, strlen(model) + 1, model);
	}
	ssd(ssd& other) : size(other.size), frequency(other.frequency)
	{
		this->manufacturer = new char[strlen(other.manufacturer) + 1];
		strcpy_s(this->manufacturer, strlen(other.manufacturer) + 1, other.manufacturer);

		this->model = new char[strlen(other.model) + 1];
		strcpy_s(this->model, strlen(other.model) + 1, other.model);
	}

	char* getManuf()
	{
		return this->manufacturer;
	}
	char* getModel()
	{
		return this->model;
	}
	double getFrequency()
	{
		return this->frequency;
	}
	int getSize()
	{
		return size;
	}
};

class gpu
{
private:
	char* manufacturer;
	char* model;
	int cores;
	double frequency;
	int vram_size;
	double vram_frequency;
public:
	gpu() = default;

	gpu(const char* manuf, const char* model, int cores, double frequency, int vram_size, double vram_freq) : cores(cores), frequency(frequency), vram_size(vram_size), vram_frequency(vram_freq)
	{
		this->manufacturer = new char[strlen(manuf) + 1];
		strcpy_s(this->manufacturer, strlen(manuf) + 1, manuf);

		this->model = new char[strlen(model) + 1];
		strcpy_s(this->model, strlen(model) + 1, model);
	}
	gpu(char* manuf, char* model, int cores, double frequency, int vram_size, double vram_freq) : cores(cores), frequency(frequency), vram_size(vram_size), vram_frequency(vram_freq)
	{
		this->manufacturer = new char[strlen(manuf) + 1];
		strcpy_s(this->manufacturer, strlen(manuf) + 1, manuf);

		this->model = new char[strlen(model) + 1];
		strcpy_s(this->model, strlen(model) + 1, model);
	}
	gpu(gpu& other) : cores(other.cores), frequency(other.frequency), vram_size(other.vram_size), vram_frequency(other.vram_frequency)
	{
		this->manufacturer = new char[strlen(other.manufacturer) + 1];
		strcpy_s(this->manufacturer, strlen(other.manufacturer) + 1, other.manufacturer);

		this->model = new char[strlen(other.model) + 1];
		strcpy_s(this->model, strlen(other.model) + 1, other.model);
	}

	char* getManuf()
	{
		return this->manufacturer;
	}
	char* getModel()
	{
		return this->model;
	}
	int getCores()
	{
		return this->cores;
	}
	int getVramSize()
	{
		return this->vram_size;
	}
	double getVramFrequency()
	{
		return this->vram_frequency;
	}
	double getFrequency()
	{
		return this->frequency;
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
	ram() = default;

	ram(const char* manuf, const char* model, int size, double frequency) : size(size), frequency(frequency)
	{
		this->manufacturer = new char[strlen(manuf) + 1];
		strcpy_s(this->manufacturer, strlen(manuf) + 1, manuf);

		this->model = new char[strlen(model) + 1];
		strcpy_s(this->model, strlen(model) + 1, model);
	}
	ram(char* manuf, char* model, int size, double frequency) : size(size), frequency(frequency)
	{
		this->manufacturer = new char[strlen(manuf) + 1];
		strcpy_s(this->manufacturer, strlen(manuf) + 1, manuf);

		this->model = new char[strlen(model) + 1];
		strcpy_s(this->model, strlen(model) + 1, model);
	}

	ram(ram& other) : size(other.size), frequency(other.frequency)
	{
		this->manufacturer = new char[strlen(other.manufacturer) + 1];
		strcpy_s(this->manufacturer, strlen(other.manufacturer) + 1, other.manufacturer);

		this->model = new char[strlen(other.model) + 1];
		strcpy_s(this->model, strlen(other.model) + 1, other.model);
	}

	char* getManuf()
	{
		return this->manufacturer;
	}
	char* getModel()
	{
		return this->model;
	}
	int getSize()
	{
		return this->size;
	}
	double getFrequency()
	{
		return this->frequency;
	}
};