#include<iostream>
using namespace std;
class A
{
	int* data;
	int size;
public:
	A()
	{
		data = nullptr;
		size = 0;
	}
	A(int ar[], int Size)
	{
		cout << "Constructed the array\n";
		size = Size;
		data = new int[size];
		for (int i = 0; i < size; i++)
		{
			data[i] = ar[i];
		}
	}

	A(initializer_list<int> a)
	{
		printf("Constructed via initializer list\n");
		printf("Size is %i\n", static_cast<int>(a.size()));
		size = a.size();
		data = new int[size];
		for (auto x = a.begin(); x != a.end(); x++)
		{
			*data = *x;
			data++;
		}
		data -= size;
	}

	void Output()
	{
		for (int i = 0; i < size; i++)
		{
			//cout << str[i] << "\t";
			//cout << *(str + i) << "\t";

			cout << *data << " ";
			data++;
		}
		data -= size;
		cout << endl;
	}
	~A()
	{
		delete[] data;
	}

};
void main()
{

	int mas[]{ 2,4,6,8 };
	A b{ mas,4 };
	b.Output();


	system("pause");
}