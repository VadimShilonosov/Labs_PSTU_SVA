#include <iostream>
#include <vector>
#include <windows.h>

using namespace std;

int main() 
{
    SetConsoleOutputCP(CP_UTF8);
    const int N = 5;

    vector<vector<int>> matrix(N, vector<int>(N));
    int counter = 1;
    for (int i = 0; i < N; ++i) 
    {
        for (int j = 0; j < N; ++j) 
        {
            matrix[i][j] = counter++;
        }
    }

    cout << "Исходная матрица:\n";
    for (int i = 0; i < N; ++i) 
    {
        for (int j = 0; j < N; ++j) 
        {
            cout << matrix[i][j] << "\t";
        }
        cout << "\n";
    }

    //замена элементов
    for (int i = 0; i < N; ++i) 
    {
        matrix[i][i] = 0;
        matrix[i][N - 1 - i] = 0;
    }

    cout << "\nМатрица после замены диагоналей:\n";
    for (int i = 0; i < N; ++i) 
    {
        for (int j = 0; j < N; ++j) 
        {
            cout << matrix[i][j] << "\t";
        }
        cout << "\n";
    }
    return 0;
}
