#include <iostream>
#include <windows.h>

using namespace std;

int main() 
{
    SetConsoleOutputCP(CP_UTF8);

    srand(time(nullptr));
    const int N = 7;
    int arr[N];
    bool is_placed_elsewhere = false;

    cout << "Исходный массив: ";
    for (int i = 0; i < N; ++i) 
    {
        arr[i] = rand() % 10;
        cout << arr[i] << " ";
    }
    cout << endl << endl;

    for (int i = 1; i < N; ++i) 
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) 
        {
            arr[j + 1] = arr[j];
            j--;
            is_placed_elsewhere = true;
        }

        arr[j + 1] = key;
    }

    cout << "Отсортированный массив: ";
    for (int i = 0; i < N; ++i) 
    {
        cout << arr[i] << " ";
    }

    cout << endl << endl;
    if (is_placed_elsewhere) cout << "True (для всех элементов найдено место)" << endl;
    else cout << "False ( не для всех элементов найдено место!" << endl;

    return 0;
}
