#include <iostream>
#include <stdexcept>
#include "math.h"

using namespace std;

int main() {
    setlocale(0, "rus");
    double num1, num2;
    int operation;

    cout << "Введите первое число: ";
    cin >> num1;
    cout << "Введите второе число: ";
    cin >> num2;
    cout << "Выберите операцию (1 - сложение, 2 - вычитание, 3 - умножение, 4 - деление, 5 - возведение в степень): ";
    cin >> operation;

  
        double result;
        switch (operation) {
        case 1:
            result = add(num1, num2);
            cout << num1 << " + " << num2 << " = " << result << endl;
            break;

        case 2:
            result = subtract(num1, num2);
            cout << num1 << " - " << num2 << " = " << result << endl;
            break;

        case 3:
            result = multiply(num1, num2);
            cout << num1 << " * " << num2 << " = " << result << endl;
            break;

        case 4:
            result = divide(num1, num2);
            cout << num1 << " / " << num2 << " = " << result << endl;
            break;

        case 5:
            result = power(num1, num2);
            cout << num1 << " в степени " << num2 << " = " << result << endl;
            break;

        default:
            cout << "Неверный выбор операции!" << endl;
            return 1;
        }
   

    return 0;
}