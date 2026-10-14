#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() 
{

    double a = -0.5;
    double b = -0.1;
    int k = 10;
    int n = 20;
    double acc = 0.0001; //точность вычислений

    double step_x = (b - a) / k;

    cout << fixed << setprecision(6); //форматирование для корректного вывода чисел

    for (int step = 0; step <= k; step++)  //внешний цикл x от a до b
    {
        double x = a + step * step_x;
        double sn = 0;
        double term_n = x;

        for (int m = 1; m <= n; m++) 
        {
            sn += term_n;
            term_n = term_n * x * m / (m + 1);
        }
        sn = -sn; //минус перед скобкой

        double se = 0;
        double term_e = x;
        int m = 1;

        while (fabs(term_e) >= acc) //вычисление цикла пока член ряда не станет меньше заданой точности
        {
            se += term_e;
            term_e = term_e * x * m / (m + 1);
            m++;
        }
        se = -se; //минус перед скобкой

        double y = log(1.0 - x); //финальное вычисление функции

        cout << x << setw(15) << sn << setw(15) << se << setw(15) << y << endl; //вывод с отступами
    }
    return 0;
}
