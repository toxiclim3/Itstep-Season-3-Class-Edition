// CL3p2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define _CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES 1 
//^ автоматически конвертирует "небезопасные" strcpy, sprintf в strcpy_s,sprintf_s с автоматическими буфферами. 
// Прикольно, но я без понятия как это работает

#include <iostream>
#include <numeric>
#include "fractional.h"
using namespace std; 

class fraction
{
private:
    int numerator;
    int denominator;
public:
    fraction();
    ~fraction();
    fraction(int, int);

    int getN1();
    int getN2();
    std::string getFrac();
    void display();

    void setN1(int);
    void setN2(int);
    void setFraction(int, int);
    void userSetFraction();

    fraction addWithAnother(fraction);
    fraction subWithAnother(fraction);
    fraction multWithAnother(fraction);
    fraction divWithAnother(fraction);

    void simplify();
};

int fraction::getN1()
{
    return numerator;
}
int fraction::getN2()
{
    return denominator;
}

/*char* getFrac()
{
    char buffer[50];
    int len = sprintf(buffer, "%i/%i", numerator, denominator);
    char* res = new char[len];
    strcpy_s(res, len + 1, buffer);
    return res;
}*/

//вызывает утечку памяти, так как нету доступа к указателю res, кроме использования string не знаю даже как тут решать
//разве что на месте собирать дробь, но это как-то некрасиво
// :(

string fraction::getFrac()
{
    char buffer[50];
    sprintf(buffer, "%i/%i", numerator, denominator);
    return string(buffer).c_str(); //в то время как это слишком простовато
}

void fraction::display()
{
    printf("%i/%i ", numerator, denominator);
}

void fraction::setN1(int num)
{
    if (num <= 0)
    {
        printf("Error: cant set numerator to <= 0");
    }
    else
    {
        numerator = num;
    }

};
void fraction::setN2(int num)
{
    if (num <= 0)
    {
        printf("Error: cant set denominator to <= 0");
    }
    else
    {
        denominator = num;
    }

};
void fraction::setFraction(int _n1, int _n2)
{
    numerator = _n1;
    denominator = _n2;
}
void fraction::userSetFraction()
{
    int t1 = 0, t2 = 0;
    printf("Input the Numerator (Can't be <= 0): ");
    while (t1 <= 0)
    {
        cin >> t1;
    }
    numerator = t1;
    printf("Input the Denominator (Can't be <= 0): ");
    while (t2 <= 0)
    {
        cin >> t2;
    }
    denominator = t2;
}

fraction fraction::addWithAnother(fraction b)
{
    fraction result;
    result.setN1(getN1() + b.getN1());
    result.setN2(getN2() + b.getN2());
    return result;
}
fraction fraction::subWithAnother(fraction b)
{
    fraction result;
    result.setN1(getN1() - b.getN1());
    result.setN2(getN2() - b.getN2());
    return result;
}
fraction fraction::multWithAnother(fraction b)
{
    fraction result;
    result.setN1(getN1() * b.getN1());
    result.setN2(getN2() * b.getN2());
    return result;
}
fraction fraction::divWithAnother(fraction b)
{
    fraction result;
    result.setN1(getN1() * b.getN2());
    result.setN2(getN2() * b.getN1());
    result.simplify();
    return result;
}
void fraction::simplify()
{

    float divisor = gcd(getN1(), getN2());
    setN1(getN1() / divisor);
    setN2(getN2() / divisor);
}
fraction::fraction()
{
    numerator = 0;
    denominator = 0;
}
fraction::~fraction()
{

}
fraction::fraction(int a, int b)
{
    numerator = a;
    denominator = b;
}


int main()
{
    //fraction frac1(6, 3);
    //fraction frac2(3, 2);
    fraction frac1;
    fraction frac2;
    frac1.userSetFraction();
    frac2.userSetFraction();

    fraction fracAdd = frac1.addWithAnother(frac2);
    fraction fracMult = frac1.multWithAnother(frac2);
    fraction fracDiv = frac1.divWithAnother(frac2);
    fraction fracSub = frac1.subWithAnother(frac2);
    
    frac1.display();
    cout << " and ";
    frac2.display();
    cout << endl;
    printf("%s + %s = %s\n", frac1.getFrac().c_str(), frac2.getFrac().c_str(), fracAdd.getFrac().c_str());
    printf("%s * %s = %s\n", frac1.getFrac().c_str(), frac2.getFrac().c_str(), fracMult.getFrac().c_str());
    printf("%s / %s = %s\n", frac1.getFrac().c_str(), frac2.getFrac().c_str(), fracDiv.getFrac().c_str());
    printf("%s - %s = %s\n", frac1.getFrac().c_str(), frac2.getFrac().c_str(), fracSub.getFrac().c_str());
}