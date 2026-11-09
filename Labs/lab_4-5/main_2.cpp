#include <iostream>
#include <iomanip>
#include <windows.h>

using namespace std;
const int MAX_SIZE = 100;

// Функция для заполнения квадратной матрицы
void generateMatrix(int matrix[MAX_SIZE][MAX_SIZE], int n) 
{
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            matrix[i][j] = rand() % 101 - 50;
        }
    }
}

// Функция для вывода матрицы
void printMatrix(const int matrix[MAX_SIZE][MAX_SIZE], int n, const string& message) 
{
    cout << message << endl;
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            cout << setw(5) << matrix[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

// Функция для смены мест диагоналей
void swapDiagonals(int matrix[MAX_SIZE][MAX_SIZE], int n) 
{
    for (int i = 0; i < n; i++) 
    {
        int temp = matrix[i][i];
        matrix[i][i] = matrix[i][n - 1 - i];
        matrix[i][n - 1 - i] = temp;
    }
}

int main() 
{
    SetConsoleOutputCP(CP_UTF8);

    srand(time(0));

    int matrix[MAX_SIZE][MAX_SIZE];
    int n;

    cout << "Введите размер квадратной матрицы N (до " << MAX_SIZE << "): ";
    cin >> n;

    if (n <= 0 || n > MAX_SIZE) 
    {
        cout << "Ошибка: неверный размер матрицы!" << endl;
        return 1;
    }

    generateMatrix(matrix, n);
    printMatrix(matrix, n, "Исходная матрица:");

    swapDiagonals(matrix, n);
    printMatrix(matrix, n, "Матрица после перестановки диагоналей:");

    return 0;
}
