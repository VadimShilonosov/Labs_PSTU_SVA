#include <iostream>
#include <windows.h>

using namespace std;

const int N = 8;
int board[N][N] = { 0 };
int step = 0;

void printBoard() 
{
    step++;
    cout << "Шаг " << step << ":" << endl;

    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < N; j++) 
        {
            if (board[i][j] == 1) cout << "Q ";
            else cout << ". ";
        }
        cout << endl;
    }
    cout << "----------------" << endl;
}

//проверка можно ли поставить ферзя
bool isSafe(int row, int col) 
{
    for (int i = 0; i < col; i++) 
    {
        if (board[row][i] == 1) return false;
    }
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) 
    {
        if (board[i][j] == 1) return false;
    }
    for (int i = row, j = col; i < N && j >= 0; i++, j--) 
    {
        if (board[i][j] == 1) return false;
    }
    return true;
}

//главная функция решения (рекурсия)
bool solve(int col) 
{
    if (col >= N) return true;

    for (int i = 0; i < N; i++) 
    {
        if (isSafe(i, col)) 
        {
            board[i][col] = 1;
            cout << "Ставим ферзя в строку " << i + 1 << ", столбец " << col + 1 << endl;
            printBoard();

            if (solve(col + 1)) return true;

            board[i][col] = 0;
            cout << "Тупик! Убираем ферзя из строки " << i + 1 << ", столбца " << col + 1 << endl;
            printBoard();
        }
    }
    return false;
}

int main() 
{
    SetConsoleOutputCP(CP_UTF8);

    if (solve(0)) cout << "Готово! Решение найдено" << endl;
    else cout << "Решений нет." << endl;
    return 0;
}
