#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"
#include <iostream>
using namespace std;

/*

       Тема: Поліморфізм (Динамічний)

       1.Показщик на базовий класс може посилатися на свого потомка

       Проблема: виклик базового класу

       Зв'язування - визначення якого саме класу інтерфейс буде використовуватись при конкретному виклику
       Раннє зв'язування - зв'язування на етапі компіляції програми, на основі лівостороннього об'єкта визначається інтерфейс (Статичний поліморфізм)
       Піздне зв'язування - зв'язування на етапі роботи програми (Динамічний поліморфізм)

       1.Використовуєтся ключове слово virtual у базовому класі
       2.Cігнатури методів мають бути однакові

*/

int main()
{
    Circle circle;
    Rectangle rectangle;
    Triangle triangle;

    circle.SetDimension(10.0);
    circle.ShowArea();
    
    rectangle.SetDimension(5.5, 10.0);
    rectangle.ShowArea();

    triangle.SetDimension(5.5, 10.0);
    triangle.ShowArea();

 

   
    return 0;
}