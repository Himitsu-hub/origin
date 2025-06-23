#include <iostream>
using namespace std;

class Calculator {
public:
    double num1;
    double num2;

public:
    double add() {
        return num1 + num2;
    }

    double multiply() {
        return num1 * num2;
    }

    double subtract_1_2() {
        return num1 - num2;
    }

    double subtract_2_1() {
        return num2 - num1;
    }

    double divide_1_2() {
        return num1 / num2;
    }

    double divide_2_1() {
        return num2 / num1;
    }

    bool set_num1(double num1) {
        if (num1 != 0) {
            this->num1 = num1;
            return true;
        }
        return false;
    }

    bool set_num2(double num2) {
        if (num2 != 0) {
            this->num2 = num2;
            return true;
        }
        return false;
    }
};

int main() {
    setlocale(0, "rus");
    Calculator calc;
    double num1, num2;

    while (true) {
        do {
            cout << "Введите num1: ";
            cin >> num1;
            if (!calc.set_num1(num1)) {
                cout << "Неверный ввод! num1 не может быть равен 0." << endl;
            }
        } while (!calc.set_num1(num1));

        do {
            cout << "Введите num2: ";
            cin >> num2;
            if (!calc.set_num2(num2)) {
                cout << "Неверный ввод! num2 не может быть равен 0." << endl;
            }
        } while (!calc.set_num2(num2));

        cout << "num1 + num2 = " << calc.add() << endl;
        cout << "num1 - num2 = " << calc.subtract_1_2() << endl;
        cout << "num2 - num1 = " << calc.subtract_2_1() << endl;
        cout << "num1 * num2 = " << calc.multiply() << endl;
        cout << "num1 / num2 = " << calc.divide_1_2() << endl;
        cout << "num2 / num1 = " << calc.divide_2_1() << endl;
    }

    return 0;
}