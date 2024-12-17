#include <iostream>
#include <cmath>
#include <clocale>
#include <chrono>

using namespace std;
using namespace chrono;

int main()
{
    auto start = steady_clock::now();
    int count = 1;
    setlocale(LC_ALL, "ru");
    double a = 0.0, b = 1.0, x0;
    double epsilon = 1e-6;
    x0 = (a + b) / 2;
    double fx = acos(x0) - sqrt(1 - 0.3 * pow(x0, 3));
    while (fx != 0)
    {
        cout << "Итерация " << count << ": " << x0 << endl;
        fx = acos(x0) - sqrt(1 - 0.3 * pow(x0, 3));
        if (fx * (acos(a) - sqrt(1 - 0.3 * pow(a, 3))) < 0)
        {
            b = x0;
        }
        else
        {
            a = x0;
        }
        if (b - a < epsilon)
        {
            cout << "Приблизительное значение корня: " << a << endl;
            fx = 0;
        }
        x0 = (a + b) / 2;
        count += 1;

    }
    auto stop = steady_clock::now();
    auto result = duration_cast<duration<double>>(stop - start).count();
    cout << "Время выполнения: " << result << endl;
    return 0;
}