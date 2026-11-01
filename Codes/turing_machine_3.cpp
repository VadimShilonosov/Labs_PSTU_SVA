#include <iostream>
#include <windows.h>

using namespace std;

//перестановка последнего элемента в начало

int main()
{
	SetConsoleOutputCP(CP_UTF8);

	string tape = "1101001_";
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
			case '1':
				head++;
				break;
			case '0':
				head++;
				break;
			case '_':
				int symb = tape[head-1];
				tape.insert(0, 1, symb);
				state = "q_z";
				break;
			}
		}
	}
	cout << "Результат: " << tape.substr(0, tape.length() - 2) << endl;

	return 0;
}
