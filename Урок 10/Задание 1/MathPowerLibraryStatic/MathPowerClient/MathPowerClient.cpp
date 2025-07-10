#include <iostream>
#include <string>
#include <Windows.h>
#include "Greeter.h"

int main() {
    setlocale(0, "rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Greeter greeter;
    std::string name;

    std::cout << "Введите имя: ";
    std::getline(std::cin, name);

    std::cout << greeter.greet(name) << std::endl;

    return 0;
}