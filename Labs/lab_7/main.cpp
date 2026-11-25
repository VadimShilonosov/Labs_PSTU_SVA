#include <iostream>
#include <windows.h>

using namespace std;

struct Complex
{
    double re; //действительная часть
    double im; //мнимая часть
};

double power(int base, int exp)
{
    if (exp == 0) return 1.0;

    double result = 1.0;
    int abs_exp = abs(exp);

    for (int i = 0; i < abs_exp; i++)
    {
        result *= base;
    }

    if (exp < 0) return 1.0 / result;
    return result;
}

Complex power(Complex z, int exp)
{
    Complex res;

    if (exp == 0)
    {
        res.re = 1.0;
        res.im = 0.0;
        return res;
    }

    double r = sqrt(z.re * z.re + z.im * z.im);
    double phi = atan2(z.im, z.re);

    double r_n = pow(r, exp);
    res.re = r_n * cos(exp * phi);
    res.im = r_n * sin(exp * phi);

    return res;
}

int main()
{
    SetConsoleOutputCP(CP_UTF8);

    int a = 3;
    int n1 = 4;
    cout << "Целое число: " << a << "^" << n1 << " = " << power(a, n1) << endl;

    int n2 = -2;
    cout << "Целое число: " << a << "^(" << n2 << ") = " << power(a, n2) << endl;

    Complex z = { 1.0, 2.0 }; // 1 + 2i
    int n3 = 3;
    Complex z_res = power(z, n3);

    cout << "Комплексное число: (" << z.re << " + " << z.im << "i)^" << n3 << " = "
        << z_res.re << (z_res.im >= 0 ? " + " : " - ") << fabs(z_res.im) << "i" << endl;

    return 0;
}
