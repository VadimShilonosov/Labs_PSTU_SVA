#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    float a = 1000;
    float b = 0.0001;

    float numerator = pow(a + b, 5) - (pow(a, 5) + 5 * pow(a, 4) * b + 10 * pow(a, 3) * pow(b, 2));
    float denominator = 10 * pow(a, 2) * pow(b, 3) + 5 * a * pow(b, 4) + pow(b, 5);
    float result = numerator / denominator;

    cout << "result of expression: " << result << endl;


    double c = 1000;
    double d = 0.0001;

    double d_numerator = pow(c + d, 5) - (pow(c, 5) + 5 * pow(c, 4) * d + 10 * pow(c, 3) * pow(d, 2));
    double d_denominator = 10 * pow(c, 2) * pow(d, 3) + 5 * c * pow(d, 4) + pow(d, 5);
    double d_result = d_numerator / d_denominator;

    cout << "result of double expression: " << d_result << endl;

    int n = 10;
    int m = 20;

    int result_1 = m++ n;
    bool result_2 = (--n > m++);
    bool result_3 = (n-- < ++m);

    cout << "Result 1: " << result_1 << enld << "Result 2: " << result_2 << endl << "Result 3: " << result_3 << endl;
    
    return 0;
}
