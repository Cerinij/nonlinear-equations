#include <iostream>
#include <cmath>
#include <clocale>

using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");
    double a = 0.0, b = 1.0, x0, x1;
    double epsilon = 1e-6;

    x0 = (a + b) / 2;

    double fx = cos(sqrt(1 - 0.3 * pow(x0, 3)));
    x1 = fx;
    while (abs(x1 - x0) > epsilon)
    {
        x0 = x1;
        x1 = cos(sqrt(1 - 0.3 * pow(x0, 3)));
    }
    cout << "Приблизительное значение корня уравнения: " << x1 << endl;
    return 0;
}