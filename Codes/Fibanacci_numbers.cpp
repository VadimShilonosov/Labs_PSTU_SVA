#include <iostream>
#include <windows.h>

using namespace std;

int main() 
{
    SetConsoleOutputCP(CP_UTF8);
    int n;
    cin >> n;

    if (n == 0) 
    {
        cout << 0 << endl;
        return 0;
    }
    if (n == 1) 
    {
        cout << 1 << endl;
        return 0;
    }

    int prev2 = 0;
    int prev1 = 1;
    int current = 0;

    for (int i = 2; i < n; ++i) 
    {
        current = prev1 + prev2;
        prev2 = prev1;
        prev1 = current;
    }

    cout << current << endl;

    return 0;
}
