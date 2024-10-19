#include<iostream>
#include<time.h>
using namespace std;

template<class T >
class MyArray
{
	T* arr;
	int size;
public:
	MyArray();
	void Output();
	~MyArray();
	MyArray(const MyArray<T>& b);	
};
template<class T>
MyArray<T>::MyArray()
{
	size = 10;
	arr = new T[10];
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 100 * 1.2;
	}
}
template<class T>
void MyArray<T>::Output()
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl << endl;
}
template<class T>
MyArray<T>::~MyArray()
{
	if (arr != nullptr)
	{
		delete[] arr;
	}
}
template<class T>
MyArray<T>::MyArray(const MyArray<T>& b)
{
	size = b.size;
	arr = new T[size];
	for (size_t i = 0; i < size; i++)
	{
		arr[i] = b.arr[i];
	}
}

