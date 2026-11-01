#include <iostream>
#include <windows.h>

using namespace std;

//инверсия чисел

int main()
{
	SetConsoleOutputCP(CP_UTF8);

	string tape = "10110_";
	string state = "q0";
	int head = 0;

	cout << "Исходная лента: " << tape.substr(0, tape.length() - 1) << endl;

	while (state != "q_z")
	{
		char current_symbol = tape[head];

		if (state == "q0")
		{
			switch (current_symbol)
			{
			case '0':
				tape[head] = '1';
				head++;
				break;
			case '1':
				tape[head] = '0';
				head++;
				break;
			case '_':
				state = "q_z";
				break;
			}
		}
	}
	cout << "Результат: " << tape.substr(0, tape.length() - 1) << endl;

	return 0;
}
