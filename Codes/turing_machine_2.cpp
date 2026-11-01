#include <iostream>
#include <windows.h>

using namespace std;

//сложение унарных чисел

int main()
{
	SetConsoleOutputCP(CP_UTF8);

	string tape = "111+11";
	string state = "q0";
	int head = 0;

	cout << "Исходная лента: " << tape << endl;

	while (state != "q_z")
	{
		char current_symbol = tape[head];

		if (state == "q0")
		{
			switch (current_symbol)
			{
			case '1':
				head++;
				break;
			case '+':
				tape[head] = '1';
				state = "q_z";
				break;
			}
		}
	}
	cout << "Результат: " << tape.substr(0, tape.length() - 1) << endl;

	return 0;
}
