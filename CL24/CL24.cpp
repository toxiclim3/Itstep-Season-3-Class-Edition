// CL24.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <random>
using namespace std;

template <class T>
T findMin(vector<T> vec)
{
    T min = vec[0];
    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i] < min)
        {
            min = vec[i];
        }
    }
    return min;
}

template <class T>
T findMax(vector<T> vec)
{
    T max = vec[0];
    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i] > max)
        {
            max = vec[i];
        }
    }
    return max;
}

int partition(vector<int>& arr, int low, int high) {

    // Choose the pivot
    int pivot = arr[high];

    // Index of smaller element and indicates 
    // the right position of pivot found so far
    int i = low - 1;

    // Traverse arr[;ow..high] and move all smaller
    // elements on left side. Elements from low to 
    // i are smaller after every iteration
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    // Move pivot after smaller elements and
    // return its position
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// The QuickSort function implementation
void quickSort(vector<int>& arr, int low, int high) {

    if (low < high) {

        // pi is the partition return index of pivot
        int pi = partition(arr, low, high);

        // Recursion calls for smaller elements
        // and greater or equals elements
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

template <class T>
void sortAsc(vector<T>& vec)
{
    quickSort(vec, 0, vec.size() - 1);
}

template <class T>
void sortDesc(vector<T>& vec)
{
    quickSort(vec, 0, vec.size() - 1);
    
    vector<T> temp = vec;
    int temp2 = 0;

    for (int i = vec.size() - 1; i >= 0; i--)
    {
        temp[i] = vec[temp2];
        temp2++;
    }

    vec = temp;
}

template <class T>
void addAll(vector<T> &vec, int val)
{
    for (int i = 0; i < vec.size(); i++)
    {
        vec[i] += val;
    }
}

int main()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    uniform_int_distribution<int> limit(-100, 100);

    vector<int> vecna;
    
    vecna.reserve(10);
    for (int i = 0; i < 10; i++)
    {
        vecna.emplace_back(limit(gen));
        cout << vecna[i] << " ";
    }
    cout << endl;

    cout << findMin(vecna) << endl;
    cout << findMax(vecna) << endl;
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
