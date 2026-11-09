#include <iostream>
#include <vector>
#include <windows.h>

using namespace std;

void shellSort(std::vector<int>& arr) 
{
    int n = arr.size();

    for (int gap = n / 2; gap > 0; gap /= 2) 
    {
        for (int i = gap; i < n; i++) 
        {
            int temp = arr[i];
            int j;

            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) 
            {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

int main() {
    SetConsoleOutputCP(CP_UTF8);

    int n;
    cout << "Введите длину массива: ";
    cin >> n;

    if (n <= 0) 
    {
        cout << "Размер массива должен быть больше 0!" << endl;
        return 1;
    }

    vector<int> arr(n);
    cout << "Введите " << n << " элементов массива через пробел: ";
    for (int i = 0; i < n; i++) 
    {
        cin >> arr[i];
    }

    shellSort(arr);

    cout << "Отсортированный массив: ";
    for (int i = 0; i < n; i++) 
    {
        cout << arr[i] << " ";
    }

    cout << endl;
    return 0;
}
