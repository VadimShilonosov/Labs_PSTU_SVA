#include <iostream>
#include <algorithm>
#include <windows.h>

using namespace std;

int main() 
{
    SetConsoleOutputCP(CP_UTF8);

    int arr[6] = {1, 3, 5, 5, 8, 12};
    int size = 6;

    bool is_ordered = is_sorted(arr, arr + size);
    if (is_ordered) cout << "Список идет по возрастанию!" << endl;
    else cout << "Список идет по убыванию!" << endl;

    return 0;
}
