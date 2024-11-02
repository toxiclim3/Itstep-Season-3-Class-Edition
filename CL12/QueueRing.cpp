#include <iostream>
#include <random>
#include <string.h>
#include <time.h>
using namespace std;

static std::mt19937 mt{ static_cast<unsigned int>(time(0)) };
std::uniform_real_distribution<> random_real{ 0, 32 };
std::uniform_int_distribution<> random_int{ 0, 8 };



class QueueRing
{
	// Очередь
	int* Wait;
	// Максимальный размер очереди
	int MaxQueueLength;
	// Текущий размер очереди
	int QueueLength;

public:
	// Конструктор
	QueueRing(int m);

	//Деструктор
	~QueueRing();

	// Добавление элемента
	void Add(int c);

	// Извлечение элемента
	bool Extract();

	// Очистка очереди
	void Clear();

	// Проверка существования элементов в очереди
	bool IsEmpty();

	// Проверка на переполнение очереди
	bool IsFull();

	// Количество элементов в очереди
	int GetCount();

	//демонстрация очереди
	void Show();
};

void QueueRing::Show() {
	cout << "\n-------------------------------------\n";
	//демонстрация очереди
	for (int i = 0; i < QueueLength; i++) {
		cout << Wait[i] << " ";
	}
	cout << "\n-------------------------------------\n";
}

QueueRing::~QueueRing()
{
	//удаление очереди
	delete[]Wait;
}

QueueRing::QueueRing(int m)
{
	//получаем размер
	MaxQueueLength = m;
	//создаем очередь
	Wait = new int[MaxQueueLength];
	// Изначально очередь пуста
	QueueLength = 0;
}

void QueueRing::Clear()
{
	// Эффективная "очистка" очереди 
	QueueLength = 0;
}

bool QueueRing::IsEmpty()
{
	// Пуст?
	return QueueLength == 0;
}

bool QueueRing::IsFull()
{
	// Полон?
	return QueueLength == MaxQueueLength;
}

int QueueRing::GetCount()
{
	// Количество присутствующих в стеке элементов
	return QueueLength;
}

void QueueRing::Add(int c)
{
	// Если в очереди есть свободное место, то увеличиваем количество
	// значений и вставляем новый элемент
	if (!IsFull())
		Wait[QueueLength++] = c;
}

bool QueueRing::Extract()
{
	// Если в очереди есть элементы, то возвращаем тот, 
	// который вошел первым и сдвигаем очередь	
	if (!IsEmpty()) {
		//запомнить первый
		int temp = Wait[0];

		//сдвинуть все элементы
		for (int i = 1; i < QueueLength; i++)
			Wait[i - 1] = Wait[i];

		//забрасываем первый "вытолкнутый элемент в конец"
		Wait[QueueLength - 1] = temp;
		return 1;

	}
	else return 0;
}

class gambling
{
private:
	const char charlist[5] = { '☺', '♠', '♣', '♥', '♦' };
	int spins[3] = { 4,6,7 };
public:
	gambling()
	{
		for (int i = 0; i < 3; i++)
		{
			this->spins[i] = random_int(mt);
		}

	};

	void mainCycle()
	{

		char status = 'w';
		while (status != 'x')
		{

			system("cls");

			std::cout << "x + enter to exit, enter to continue \n";
			status = getchar();
		}

	}
};

void main()
{
	gambling ba;

	ba.mainCycle();
}


