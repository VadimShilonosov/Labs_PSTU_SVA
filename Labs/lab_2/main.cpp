#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int n = 1;
    double acc = 1e-4; //точность (10**4)
    double a = 1.0 / 3.0;
    double sum = a; //берём первый член как начальную сумму

    while (a >= acc) {

        a = a * (n + 1) / (3 * n);
        sum += a;
        n++;
    }

    cout << "result: " << sum << endl;

    return 0;
}
