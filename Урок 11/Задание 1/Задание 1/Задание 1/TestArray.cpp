#include "ExtendedArray.h"
#include <iostream>

void test_empty_array() {
    ExtArray<int> arr(0);
    if (arr.size() != 0) std::cerr << "FAIL: Empty array size\n";
    if (arr.mean() != 0.0) std::cerr << "FAIL: Empty array mean\n";
    if (arr.median() != 0.0) std::cerr << "FAIL: Empty array median\n";

    auto mode = arr.mode();
    if (mode.first != 0 || mode.second != 0) std::cerr << "FAIL: Empty array mode\n";

    std::cout << "Empty array tests completed\n";
}

void test_normal_array() {
    ExtArray<int> arr = { 1, 2, 2, 3, 4 };
    if (arr.size() != 5) std::cerr << "FAIL: Normal array size\n";
    if (arr.mean() != 2.4) std::cerr << "FAIL: Normal array mean\n";
    if (arr.median() != 2.0) std::cerr << "FAIL: Normal array median\n";

    auto mode = arr.mode();
    if (mode.first != 2 || mode.second != 2) std::cerr << "FAIL: Normal array mode\n";

    std::cout << "Normal array tests completed\n";
}

int main() {
    test_empty_array();
    test_normal_array();
    std::cout << "All tests completed\n";
    return 0;
}