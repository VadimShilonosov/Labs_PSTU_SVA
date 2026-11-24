#include <iostream>
#include <iomanip>
#include <windows.h>

using namespace std;

void printArray(const int* arr, int size, const string& label) 
{
    cout << label << " (размер = " << size << "):" << endl;

    for (int i = 0; i < size; ++i) 
    {
        if (i == 0)  cout << right << setw(3) << arr[i];
        else cout << "  " << right << setw(3) << arr[i];
    }
    cout << endl << endl;
}

int* resizeArray(int* oldArr, int oldSize, int newSize) 
{
    int* newArr = new int[newSize];
    int elementsToCopy = (oldSize < newSize) ? oldSize : newSize;

    for (int i = 0; i < elementsToCopy; ++i) 
    {
        newArr[i] = oldArr[i];
    }
    for (int i = oldSize; i < newSize; ++i) 
    {
        newArr[i] = (i + 1) * 100;
    }

    delete[] oldArr;
    return newArr;
}

int main() 
{
    SetConsoleOutputCP(CP_UTF8);

    int size = 3;
    int* arr = new int[size] {5, 42, 128};
    printArray(arr, size, "1. Исходный массив");

    arr = resizeArray(arr, size, 6);
    size = 6;
    printArray(arr, size, "2. После увеличения");

    arr = resizeArray(arr, size, 2);
    size = 2;
    printArray(arr, size, "3. После уменьшения");

    delete[] arr;
    return 0;
}
