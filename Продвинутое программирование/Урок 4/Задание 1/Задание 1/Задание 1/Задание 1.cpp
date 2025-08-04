#include <iostream>
#include <vector>
#include <type_traits>

template<typename T>
typename std::enable_if<std::is_arithmetic<T>::value, T>::type square(T x) {
    return x * x;
}

template<typename T>
std::vector<T> square(const std::vector<T>& vec) {
    std::vector<T> result;
    for (const auto& elem : vec) {
        result.push_back(elem * elem);
    }
    return result;
}

template<typename T>
void printVector(const std::vector<T>& vec) {
    bool first = true;
    for (const auto& elem : vec) {
        if (!first) {
            std::cout << ", ";
        }
        std::cout << elem;
        first = false;
    }
    std::cout << std::endl;
}

int main() {
    int num = 4;
    std::cout << square(num) << std::endl;

    std::vector<int> vec = { -1, 4, 8 };
    std::vector<int> squared_vec = square(vec);
    printVector(squared_vec); 

    return 0;
}