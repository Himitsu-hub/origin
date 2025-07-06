#include <iostream>
using namespace std;

#define MODE 1

#ifndef MODE
#error "Необходимо определить MODE"
#endif

#if MODE == 1
int add(int a, int b) {
    return a + b;
}
#endif

int main() {
    setlocale(0, "rus");
#if MODE == 0
    cout << "Работаю в режиме тренировки" << endl;

#elif MODE == 1
    cout << "Работаю в боевом режиме" << endl;

    int num1, num2;
    cout << "Введите число 1: ";
    cin >> num1;
    cout << "Введите число 2: ";
    cin >> num2;

    cout << "Результат сложения: " << add(num1, num2) << endl;

#else
    cout << "Неизвестный режим. Завершение работы" << endl;
#endif

    return 0;
}