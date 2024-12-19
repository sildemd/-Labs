#include <iostream>
#include <clocale>
#include <cmath>
using namespace std;

double fi(double x)
{
    return (3.8 + 0.65 * x - 3 * sin(sqrt(x)));
}

double fi1(double x)
{
    return - (3 * cos(sqrt(x)) / 2 * sqrt(x)) - 0.65;
}
int main()
{
    setlocale(LC_ALL, "Russian");
    double a = 2;
    double b = 3;
    double c, x0;
    double x = 1;
    double e = 0.00001;
    bool s = true;
    for (double x = a; x <= b; x += 0.001)
    {
        if (abs(fi1(x)) >= 1)
        {
            s = false;
        }
    }
    if (s)
    {
        cout << "Введите любой x принадлежайщий отрезку от 2 до 3\n";
        cin >> x0;
        c = x0;
        while (abs(x - x0) > e)
        {
            x0 = c;
            x = fi(x0);
            c = fi(x0);
        }
    }
    cout << "Корень уравнения:\n" << x;
    return 0;
}