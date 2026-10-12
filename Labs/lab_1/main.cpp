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

    double d_numerator = pow(a + b, 5) - (pow(a, 5) + 5 * pow(a, 4) * b + 10 * pow(a, 3) * pow(b, 2));
    double d_denominator = 10 * pow(a, 2) * pow(b, 3) + 5 * a * pow(b, 4) + pow(b, 5);
    double d_result = d_numerator / d_denominator;

    cout << "result of double expression: " << d_result << endl;

    return 0;
}
