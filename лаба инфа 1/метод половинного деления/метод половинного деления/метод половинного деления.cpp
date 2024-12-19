#include <iostream>
#include <clocale>
#include <cmath>
using namespace std;

double f(double x)
{
    return (3 * sin(sqrt(x)) + 0.35 * x - 3.8);
}

int main()
{
    setlocale(LC_ALL, "Russian");
    double a = 2;
    double b = 3;
    double e = 0.00001;
    double c = (a + b) / 2;
    if (f(a) * f(b) < 0)
    {
        while (abs(b - a) > e)
        {
            c = (a + b) / 2;
            if (f(a) * f(c) < 0)
            {
                b = c;
            }
            else
            {
                a = c;
            }
        }
    }
    else
    {
        cout << "На отрезке нет корня";
    }
    cout << "Корень уравнения:\n" << c;
    return 0;
}