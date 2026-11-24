#include <iostream>
#include <iomanip>
#include <windows.h>

using namespace std;

void printArray(const int* arr, int size, const string& title)
{
    cout << title << " (размер = " << size << "):" << endl;
    for (int i = 0; i < size; ++i) 
    {
        if (i == 0) cout << right << setw(3) << arr[i];
        else cout << "  " << right << setw(3) << arr[i];
    }
    cout << "\n\n";
}

void resizeArray(int*& arr, int& size, int newSize) 
{
    //выделяем новую память в куче
    int* tempArr = new int[newSize];

    //копируем старые данные в новый массив
    int limit = (size < newSize) ? size : newSize;
    for (int i = 0; i < limit; ++i) 
    {
        tempArr[i] = arr[i];
    }

    //дозаполняем новые ячейки
    for (int i = size; i < newSize; ++i) 
    {
        tempArr[i] = (i + 1) * 100;
    }

    //удаляем старый массив
    delete[] arr;

    //меняем указатель и размер на новые
    arr = tempArr;
    size = newSize;
}

int main() 
{
    SetConsoleOutputCP(CP_UTF8);

    int size = 3;
    int* arr = new int[size];
    arr[0] = 5;
    arr[1] = 42;
    arr[2] = 128;

    printArray(arr, size, "1. Создан исходный массив");

    resizeArray(arr, size, 6);
    printArray(arr, size, "2. Массив увеличен");

    resizeArray(arr, size, 2);
    printArray(arr, size, "3. Массив уменьшен");

    //удаляем массив после завершения кода
    delete[] arr;
    arr = nullptr;
    return 0;
}
