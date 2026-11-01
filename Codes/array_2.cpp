#include <iostream>
#include <algorithm>
#include <windows.h>

using namespace std;

int main() 
{
    SetConsoleOutputCP(CP_UTF8);

    int arr[8] = { 9, 3, 7, 1, 9, 2, 1, 9 };
    int size = 8;
    auto [min_ptr, max_ptr] = minmax_element(arr, arr + size);

    int min_val = *min_ptr;
    int max_val = *max_ptr;

    int min_index = distance(arr, min_ptr);
    int max_index = distance(arr, max_ptr);

    int min_count = count(arr, arr + size, min_val);
    int max_count = count(arr, arr + size, max_val);

    cout << "Минимальный элемент: " << min_val << endl << "Индекс первого вхождения: " << min_index << endl;
    if (min_count > 1) cout << "Количество минимальных элементов: " << min_count << endl;
    cout << endl;

    cout << "Максимальный элемент: " << max_val << endl << "Индекс первого вхождения: " << max_index << endl;
    if (max_count > 1) cout << "Количество максимальных элементов: " << max_count;
    cout << endl;

    return 0;
}
