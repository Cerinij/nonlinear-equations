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
    double a = 0.0, b = 1.0;
    double x0 = a;
    double epsilon = 1e-6;

    double fx = acos(x0) - sqrt(1 - 0.3 * pow(x0, 3));
    double dfx = -1 / sqrt(1 - pow(x0, 2)) + 0.45 * pow(x0, 2) / sqrt(1 - 0.3 * pow(x0, 3));

    double x1 = x0 - fx / dfx;
    while (abs(x1 - x0) > epsilon)
    {
        cout << "Итерация " << count << ": " << x1 << endl;
        x0 = x1;

        fx = acos(x0) - sqrt(1 - 0.3 * pow(x0, 3));
        dfx = -1 / sqrt(1 - pow(x0, 2)) + 0.45 * pow(x0, 2) / sqrt(1 - 0.3 * pow(x0, 3));

        x1 = x0 - fx / dfx;
        count += 1;
    }
    cout << "Приближенное значение корня уравнения: " << x1 << endl;
    auto stop = steady_clock::now();
    auto result = duration_cast<duration<double>>(stop - start).count();
    cout << "Время выполнения: " << result << endl;
    return 0;
}