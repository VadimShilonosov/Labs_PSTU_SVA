#include <iostream>
#include <vector>
#include <windows.h>

using namespace std;

const int NUM_DISKS = 5;
vector<int> rods[3];
int step_count = 0;

//вывод состояния башен
void printTowers() 
{
    for (int level = NUM_DISKS - 1; level >= 0; --level) 
    {
        for (int r = 0; r < 3; ++r) 
        {
            int disk_size = 0;
            if (level < rods[r].size()) disk_size = rods[r][level];

            int spaces = NUM_DISKS - disk_size;
            string pad(spaces, ' ');
            string half_disk(disk_size, '#');

            if (disk_size == 0) cout << pad << "|" << pad << "   ";
            else cout << pad << half_disk << "|" << half_disk << pad << "   ";
        }
        cout << endl;
    }
    cout << "===========   ===========   ===========" << endl;
    cout << " Стержень 1    Стержень 2    Стержень 3" << endl << endl;
}

//вывод шага
void moveDisk(int from, int to) 
{
    int disk = rods[from].back();
    rods[from].pop_back();
    rods[to].push_back(disk);

    step_count++;
    cout << "---------------------------------------" << endl;
    cout << "Шаг " << step_count << endl << endl;

    printTowers();
}

void hanoi(int n, int from, int to, int aux) 
{
    if (n == 1) 
    {
        moveDisk(from, to);
        return;
    }
    hanoi(n - 1, from, aux, to);
    moveDisk(from, to);
    hanoi(n - 1, aux, to, from);
}

int main() 
{
    SetConsoleOutputCP(CP_UTF8);

    for (int i = NUM_DISKS; i >= 1; --i)
    {
        rods[0].push_back(i);
    }

    cout << "Исходное состояние:" << endl << endl;
    printTowers();

    //переносим кольца со стержня 0 на стержень 2 через 1
    hanoi(NUM_DISKS, 0, 2, 1);

    cout << "Готово! Всего выполнено шагов: " << step_count << endl;
    return 0;
}
