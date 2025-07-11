#include "ExtendedArray.h"
#include <iostream>
#include <typeinfo>

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

void test_check_sum() {
    // Тест для bool массива
    try {
        ExtArray<bool> bool_arr{ true, false, true, true, false };
        size_t sum = bool_arr.checkSum();
        if (sum != 3) {
            std::cerr << "FAIL: Bool array check sum (expected 3, got " << sum << ")\n";
        }
        else {
            std::cout << "Bool array check sum test passed\n";
        }
    }
    catch (...) {
        std::cerr << "FAIL: Unexpected exception in bool array check sum test\n";
    }

    // Тест для корректного int массива
    try {
        ExtArray<int> int_arr{ 1, 0, 1, 1, 0, 1 };
        size_t sum = int_arr.checkSum();
        if (sum != 4) {
            std::cerr << "FAIL: Int array check sum (expected 4, got " << sum << ")\n";
        }
        else {
            std::cout << "Int array check sum test passed\n";
        }
    }
    catch (...) {
        std::cerr << "FAIL: Unexpected exception in int array check sum test\n";
    }

    // Тест для некорректного int массива
    try {
        ExtArray<int> invalid_arr{ 1, 0, 2, 1 };
        invalid_arr.checkSum();
        std::cerr << "FAIL: No exception for invalid int array\n";
    }
    catch (const std::logic_error& e) {
        std::cout << "Invalid int array test passed (exception: " << e.what() << ")\n";
    }
    catch (...) {
        std::cerr << "FAIL: Wrong exception type for invalid int array\n";
    }

    // Тест для неподдерживаемого типа
    try {
        ExtArray<double> wrong_type{ 1.0, 0.0, 1.0 };
        wrong_type.checkSum();
        std::cerr << "FAIL: No exception for wrong array type\n";
    }
    catch (const std::bad_typeid& e) {
        std::cout << "Wrong type test passed (exception: " << e.what() << ")\n";
    }
    catch (...) {
        std::cerr << "FAIL: Wrong exception type for wrong array type\n";
    }

    // Тест для пустого массива
    try {
        ExtArray<bool> empty_bool(0);
        size_t sum = empty_bool.checkSum();
        if (sum != 0) {
            std::cerr << "FAIL: Empty bool array check sum (expected 0, got " << sum << ")\n";
        }
        else {
            std::cout << "Empty bool array check sum test passed\n";
        }

        ExtArray<int> empty_int(0);
        sum = empty_int.checkSum();
        if (sum != 0) {
            std::cerr << "FAIL: Empty int array check sum (expected 0, got " << sum << ")\n";
        }
        else {
            std::cout << "Empty int array check sum test passed\n";
        }
    }
    catch (...) {
        std::cerr << "FAIL: Unexpected exception in empty array check sum test\n";
    }
}

int main() {
    test_empty_array();
    test_normal_array();
    test_check_sum();
    std::cout << "All tests completed\n";
    return 0;
}