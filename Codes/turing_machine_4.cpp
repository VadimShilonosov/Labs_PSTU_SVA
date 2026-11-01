#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

//проверка на полиндром

int main() {
    SetConsoleOutputCP(CP_UTF8);

    string tape = "10101_";
    string state = "q0";
    int head = 0;

    char saved_symbol = '_';

    cout << "Исходная лента: " << tape.substr(0, tape.length() - 1) << endl;

    while (state != "q_z" && state != "q_reject") 
    {
        char current_symbol = tape[head];

        if (state == "q0") 
        {
            if (current_symbol == 'X') head++;
            else if (current_symbol == '0' || current_symbol == '1') 
            {
                saved_symbol = current_symbol;
                tape[head] = 'X';
                head++;
                state = "q_find_right";
            }
            else if (current_symbol == '_') state = "q_z";
            
        }
        else if (state == "q_find_right") 
        {
            if (current_symbol != 'X' && current_symbol != '_') head++;
            else 
            {
                head--;
                state = "q_check_left";
            }
        }

        else if (state == "q_check_left") 
        {
            if (current_symbol == 'X') state = "q_z";
            else if (current_symbol == saved_symbol) 
            {
                tape[head] = 'X';
                head--;
                state = "q_return_start";
            }
            else state = "q_reject";
        }

        else if (state == "q_return_start") 
        {
            if (head > 0) {
                head--;
            }
            else state = "q0";
        }
    }

    if (state == "q_z") cout << "Строка полиндром!" << endl;
    else cout << "Строка НЕ полиндром!" << endl;

    return 0;
}
