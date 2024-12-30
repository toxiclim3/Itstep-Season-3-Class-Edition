#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
using namespace std;

struct print 
{
    void operator()(const vector<int>& vec) const 
    {
        for (int i = 0; i < vec.size(); i++) 
        {
            cout << vec[i] << " ";
        }
        cout << endl;
    }
};

struct findMin 
{
    int operator()(const vector<int>& vec) const 
    {
        return *min_element(vec.begin(), vec.end());
    }
};

struct findMax 
{
    int operator()(const vector<int>& vec) const 
    {
        return *max_element(vec.begin(), vec.end());
    }
};

struct sortAsc 
{
    void operator()(vector<int>& vec) const 
    {
        sort(vec.begin(), vec.end());
    }
};

struct sortDesc
{
    void operator()(vector<int>& vec) const 
    {
        sort(vec.rbegin(), vec.rend());
    }
};

struct addAll 
{
    void operator()(vector<int>& vec, int val) const 
    {
        for (int i = 0; i < vec.size(); i++)
        {
            vec[i] += val;
        }
    }
};

struct removeMatching 
{
    int operator()(vector<int>& vec, int val) const 
    {
        int deleted = 0;
        for (int i = 0; i < vec.size(); i++)
        {
            if (vec[i] == val)
            {
                vec.erase(vec.begin() + i);
                deleted++;
            }
        }
        
        return deleted;
    }
};

int main() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> limit(0, 10);

    vector<int> vecna(10);
    for (int i = 0; i < vecna.size(); i++)
    {
        vecna[i] = limit(gen);
    }

    print print;
    findMin findMin;
    findMax findMax;
    sortAsc sortAsc;
    sortDesc sortDesc;
    addAll addAll;
    removeMatching removeMatching;

    print(vecna);

    cout << "Minimum value: " << findMin(vecna) << endl;
    cout << "Maximum value: " << findMax(vecna) << endl;

    sortAsc(vecna);
    print(vecna);

    sortDesc(vecna);
    print(vecna);

    addAll(vecna, 10);
    print(vecna);

    addAll(vecna, -10);
    print(vecna);

    int removeVal = 10;
    int removed = removeMatching(vecna, removeVal);
    cout << "Removed " << removed << " occurrences of " << removeVal << ".\n";
    print(vecna);

    return 0;
}
