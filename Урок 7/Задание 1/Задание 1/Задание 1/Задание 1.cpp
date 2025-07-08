#include <iostream>
#include <string>
#include <stdexcept>
#include <Windows.h>

class bad_length : public std::exception {
public:
    const char* what() const noexcept override {
        return "Вы ввели слово запретной длины! До свидания";
    }
};

int function(std::string str, int forbidden_length) {
    int length = str.length();
    if (length == forbidden_length) {
        throw bad_length();
    }
    return length;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(0, "rus");
    int forbidden_len;
    std::cout << "Введите запретную длину: ";
    std::cin >> forbidden_len;

    std::string word;
    while (true) {
        std::cout << "Введите слово: ";
        std::cin >> word;

        try {
            int len = function(word, forbidden_len);
            std::cout << "Длина слова \"" << word << "\" равна " << len << std::endl;
        }
        catch (const bad_length& e) {
            std::cout << e.what() << std::endl;
            break;
        }
    }

    return 0;
}