#include <iostream>
#include <iomanip>
#include <cstdlib> //для функций rand() и srand()
#include <ctime>   //для функции time()

using namespace std;

int main() 
{
    srand(time(0)); //инициализация случайных чисел

    const int MAX_SIZE = 100; 
    int a[MAX_SIZE];
    int n;

    cout << "Enter the start count of massif (up to 50): ";
    cin >> n;

    if (n < 3 || n > 50) 
    {
        cout << "invalid massif size" << endl;
        return 1;
    }

    for (int i = 0; i < n; i++) //формирование массива случайными числами от -50 до 50
    {
        a[i] = rand() % 101 - 50;
    }

    cout << "\nStart massif:";
    for (int i = 0; i < n; i++) 
    {
        cout << setw(5) << a[i];
    }
    cout << endl << "Real massif size: " << n << endl;

    int preLastIdx = n - 2; //удаление предпоследнего элемента
    for (int i = preLastIdx; i < n - 1; i++) 
    {
        a[i] = a[i + 1];
    }
    n--; //уменьшение размера массива

    int secondIdx = 1;
    for (int i = secondIdx; i < n - 1; i++) 
    {
        a[i] = a[i + 1];
    }
    n--;

    cout << "\nMassif after removing elements:";
    for (int i = 0; i < n; i++) 
    {
        cout << setw(5) << a[i];
    }
    cout << endl << "Real massif size: " << n << endl;

    for (int i = n - 1; i >= 0; i--) 
    {
        if (a[i] < 0) 
        {
            if (n >= MAX_SIZE) //проверка не переполнился ли массив
            {
                cout << "\nMassif is full over" << endl;
                break;
            }

            for (int j = n; j > i; j--) //сдвигаем элементы вправо, начиная с позиции i
            {
                a[j] = a[j - 1];
            }
            a[i] = 0;
            n++;      
        }
    }

    cout << "\nResult massif:";
    for (int i = 0; i < n; i++) 
    {
        cout << setw(5) << a[i];
    }
    cout << endl << "Real massif size: " << n << endl;

    return 0;
}
