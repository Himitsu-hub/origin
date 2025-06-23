#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

class Counter {
private:
    int value;  

public:
    Counter() : value(1) {}

    Counter(int initial_value) : value(initial_value) {}

    void increment() {
        value++;
    }

    void decrement() {
        value--;
    }

    int get_current() {
        return value;
    }
};

int main() {
    setlocale(0, "rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string answer;
    int initial_value = 1;
    char command;

    cout << "Вы хотите указать начальное значение счётчика? Введите да или нет: ";
    cin >> answer;

    if (answer == "да") {
        cout << "Введите начальное значение счётчика: ";
        cin >> initial_value;
    }

    Counter counter(initial_value);

    while (true) {
        cout << "Введите команду ('+', '-', '=' или 'x'): ";
        cin >> command;

        switch (command) {
        case '+':
            counter.increment();
            break;
        case '-':
            counter.decrement();
            break;
        case '=':
            cout << counter.get_current() << endl;
            break;
        case 'x':
            cout << "До свидания!" << endl;
            return 0;
        default:
            cout << "Неизвестная команда!" << endl;
        }
    }

    return 0;
}