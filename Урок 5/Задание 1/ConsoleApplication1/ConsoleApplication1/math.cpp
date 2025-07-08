#include <iostream>
#include <stdexcept>
#include "math.h"

int main() {
    setlocale(0, "rus");
    double num1, num2;
    int operation;

    std :: cout << "Введите первое число: ";
    std:: cin >> num1;
    std:: cout << "Введите второе число: ";
    std:: cin >> num2;
    std:: cout << "Выберите операцию (1 - сложение, 2 - вычитание, 3 - умножение, 4 - деление, 5 - возведение в степень): ";
    std:: cin >> operation;

  
        double result;
        switch (operation) {
        case 1:
            result = add(num1, num2);
            std:: cout << num1 << " + " << num2 << " = " << result << std:: endl;
            break;

        case 2:
            result = subtract(num1, num2);
            std:: cout << num1 << " - " << num2 << " = " << result << std:: endl;
            break;

        case 3:
            result = multiply(num1, num2);
            std:: cout << num1 << " * " << num2 << " = " << result << std:: endl;
            break;

        case 4:
            result = divide(num1, num2);
            std:: cout << num1 << " / " << num2 << " = " << result << std:: endl;
            break;

        case 5:
            result = power(num1, num2);
            std:: cout << num1 << " в степени " << num2 << " = " << result << std:: endl;
            break;

        default:
            std:: cout << "Неверный выбор операции!" << std:: endl;
            return 1;
        }
   

    return 0;
}