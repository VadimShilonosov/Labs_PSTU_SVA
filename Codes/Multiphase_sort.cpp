#include <iostream>
#include <vector>
#include <algorithm>
#include <windows.h>

using namespace std;

//функция для вывода состояния лент
void printTapes(const vector<vector<int>>& tapes) 
{
    for (size_t i = 0; i < tapes.size(); ++i) 
    {
        cout << "Лента " << i + 1 << ": ";

        if (tapes[i].empty()) cout << "[пустая]";
        else for (int val : tapes[i]) cout << val << " ";

        cout << endl;
    }
    cout << "----------------------------------------------" << endl;
}

//симуляция многофазного слияния
void polyphaseSortSimulation(vector<int>& inputData) 
{
    if (inputData.empty()) return;

    vector<int> T1, T2, T3;

    size_t mid = inputData.size() / 2;
    if (mid == 0) mid = 1;

    T1.assign(inputData.begin(), inputData.begin() + mid);
    T2.assign(inputData.begin() + mid, inputData.end());

    sort(T1.begin(), T1.end());
    sort(T2.begin(), T2.end());

    vector<vector<int>> tapes = { T1, T2, T3 };

    cout << " - Исходное распределение по лентам " << endl;
    printTapes(tapes);

    cout << " - Фаза 1: Слияние из Ленты 1 и Ленты 2 в Ленту 3 " << endl;

    size_t i = 0, j = 0;
    while (i < tapes[0].size() && j < tapes[1].size()) 
    {
        if (tapes[0][i] < tapes[1][j]) tapes[2].push_back(tapes[0][i++]);
        else tapes[2].push_back(tapes[1][j++]);
    }

    tapes[0].erase(tapes[0].begin(), tapes[0].begin() + i);
    tapes[1].erase(tapes[1].begin(), tapes[1].begin() + j);
    printTapes(tapes);

    cout << " - Фаза 2: Финальное слияние " << endl;

    int activeInputTape = tapes[0].empty() ? 1 : 0;
    int emptyTape = tapes[0].empty() ? 0 : 1;

    size_t idxActive = 0;
    size_t idxT3 = 0;

    while (idxActive < tapes[activeInputTape].size() && idxT3 < tapes[2].size()) 
    {
        if (tapes[activeInputTape][idxActive] < tapes[2][idxT3]) tapes[emptyTape].push_back(tapes[activeInputTape][idxActive++]);
        else tapes[emptyTape].push_back(tapes[2][idxT3++]);
    }

    while (idxActive < tapes[activeInputTape].size()) 
    {
        tapes[emptyTape].push_back(tapes[activeInputTape][idxActive++]);
    }
    while (idxT3 < tapes[2].size()) 
    {
        tapes[emptyTape].push_back(tapes[2][idxT3++]);
    }

    tapes[activeInputTape].clear();
    tapes[2].clear();
    printTapes(tapes);

    inputData = tapes[emptyTape];
}

int main() 
{
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
    cout << "Введите " << n << " элементов через пробел: ";
    for (int i = 0; i < n; i++) 
    {
        cin >> arr[i];
    }
    polyphaseSortSimulation(arr);

    cout << "Итоговый отсортированный массив: ";
    for (int val : arr) 
    {
        cout << val << " ";
    }

    cout << endl;
    return 0;
}
