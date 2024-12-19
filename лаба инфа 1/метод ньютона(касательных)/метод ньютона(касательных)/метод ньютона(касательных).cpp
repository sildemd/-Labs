
#include <iostream>
#include <clocale>
#include <cmath>
using namespace std;

double f(double x)
{
    return (3 * sin(sqrt(x)) + 0.35 * x - 3.8);
}
double f1(double x)
{
    return ((3 * cos(sqrt(x)) / 2 * sqrt(x)) + 0.35);
}
double f2(double x)
{
    return - (( 3 * sin(sqrt(x)) * sqrt(x) + 3 * cos(sqrt(x))) / 4 * pow(x , (1.5)));
}
int main() {
    setlocale(LC_ALL, "Russian");
    double q, w, e, x, x0;
    cin >> q >> w >> e;
    if (f(q) * f2(q) > 0)
    {
        x0 = q;
    }
    else
    {
        if (f(w) * f2(w) > 0)
        {
            x0 = w;
        }
        else
        {
            cout << "Неправильно введен интервал";
        }
    }
    x = x0 - f(x0) / f1(x0);
    while ((abs(x - x0)) > e)
    {
        x0 = x - f(x) / f1(x);
        x = x0 - f(x0) / f1(x0);
    }
    cout << "Корень уравнения:\n" << x;
    return 0;
}