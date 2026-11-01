#include <iostream>
#include <cstdlib>
#include <windows.h>

using namespace std;

int main() 
{
    SetConsoleOutputCP(CP_UTF8);
    srand(time(nullptr));

    const int N = 7;
    int arr[N];
    cout << "Исходный массив: ";
    for (int i = 0; i < N; ++i) 
    {
        arr[i] = rand() % 10;
        cout << arr[i] << " ";
    }
    cout << endl << endl;

    for (int i = 0; i < N - 1; ++i) 
    {
        int min_idx = i;

        for (int j = i + 1; j < N; ++j) 
        {
            if (arr[j] < arr[min_idx]) min_idx = j;
        }

        if (min_idx != i) 
        {
            int temp = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = temp;
        }
    }

    cout << "Отсортированный массив: ";
    for (int i = 0; i < N; ++i) 
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
