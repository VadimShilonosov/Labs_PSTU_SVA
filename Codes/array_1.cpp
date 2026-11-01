#include <iostream>
#include <iomanip>
#include <windows.h>

using namespace std;

int main() 
{
    SetConsoleOutputCP(CP_UTF8);

    int sum_1 = 0;
    int sum_2 = 0;

    int matrix[2][4] = {
        {12, 9, 6, 73},
        {81, 5, 67, -8}
    };

    const int WIDTH = 5;

    cout << "--- Исходный массив: ---" << endl << endl;

    for (int i = 0; i < 2; i++) 
    {
        for (int j = 0; j < 4; j++) 
        {
            cout << setw(WIDTH) << matrix[i][j];
            if (i==0) sum_1 += matrix[i][j];
            if (i==1) sum_2 += matrix[i][j];
        }
        cout << endl;
    }
    cout << endl << "Сумма первой строки: " << sum_1 << endl;
    cout << "Сумма второй строки: " << sum_2 << endl;


    return 0;
}
