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

    void increment() { value++; }
    void decrement() { value--; }
    int get_current() const { return value; }  
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(0, "rus");

    Counter* counter = nullptr;  
    string answer;
    int count;

    cout << "Вы хотите указать начальное значение счётчика? Введите да или нет: ";
    cin >> answer;

    if (answer == "да") {
        cout << "Введите начальное значение счётчика: ";
        cin >> count;
        counter = new Counter(count); 
    }
    else {
        counter = new Counter();  
    }

    char command;
    do {
        cout << "Введите команду ('+', '-', '=' или 'x'): ";
        cin >> command;

        switch (command) {
        case '+':
            counter->increment();
            break;
        case '-':
            counter->decrement();
            break;
        case '=':
            cout << counter->get_current() << endl;
            break;
        case 'x':
            cout << "До свидания!" << endl;
            break;
        default:
            cout << "Неизвестная команда!" << endl;
        }
    } while (command != 'x');

    delete counter;  
    return 0;
}