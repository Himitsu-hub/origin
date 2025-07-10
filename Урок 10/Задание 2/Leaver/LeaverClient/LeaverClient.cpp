#include <iostream>
#include <string>
#include <Windows.h>
#include "Leaver.h"

int main() {
    setlocale(0, "rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Leaver leaver;
    std::string name;

    std::cout << "Введите имя: ";
    std::getline(std::cin, name);

    std::cout << leaver.leave(name) << std::endl;

    return 0;
}