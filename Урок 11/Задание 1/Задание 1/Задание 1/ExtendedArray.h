#pragma once
#include <utility>
#include <initializer_list>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <typeinfo>
#include <type_traits>

template <typename T>
class ExtArray {
private:
    std::vector<T> extended_array;
    size_t _size;

    void validateCheckSumRequirements() const {
        if (!std::is_same<T, bool>::value && !std::is_same<T, int>::value) {
            throw std::bad_typeid();
        }

        if constexpr (std::is_same_v<T, int>) {
            for (const auto& item : extended_array) {
                if (item != 0 && item != 1) {
                    throw std::logic_error("Array contains values other than 0 and 1");
                }
            }
        }
    }

public:
    ExtArray(std::initializer_list<T> l) : extended_array(l), _size(l.size()) {}

    ExtArray(int size) : _size(size) {
        if (size < 0) throw std::invalid_argument("Size cannot be negative");
        extended_array.resize(_size);
    }

    T& operator[](size_t index) {
        if (index >= _size) throw std::out_of_range("Index out of range");
        return extended_array[index];
    }

    size_t size() const { return _size; }

    double mean() const {
        if (_size == 0) return 0.0;
        double sum = 0;
        for (const auto& item : extended_array) {
            sum += item;
        }
        return sum / _size;
    }

    double mean(size_t start, size_t end) const {
        if (start >= end) {
            throw std::invalid_argument("Start index must be less than end index");
        }
        if (end > _size) {
            throw std::out_of_range("End index exceeds array size");
        }

        double sum = 0;
        size_t count = 0;
        for (size_t i = start; i < end; ++i) {
            sum += extended_array[i];
            ++count;
        }

        return sum / count;
    }

    double median() const {
        if (_size == 0) return 0.0;
        std::vector<T> temp_array = extended_array;
        std::sort(temp_array.begin(), temp_array.end());

        if (_size % 2 == 1) {
            return temp_array[_size / 2];
        }
        else {
            return static_cast<double>(temp_array[(_size / 2) - 1] + temp_array[_size / 2]) / 2;
        }
    }

    std::pair<T, int> mode() const {
        if (_size == 0) return { T(), 0 };

        T max_value = extended_array[0];
        int max_count = 1;

        for (size_t i = 0; i < _size; ++i) {
            int count = 1;
            for (size_t j = i + 1; j < _size; ++j) {
                if (extended_array[i] == extended_array[j]) {
                    ++count;
                }
            }

            if (count > max_count ||
                (count == max_count && extended_array[i] < max_value)) {
                max_count = count;
                max_value = extended_array[i];
            }
        }

        return { max_value, max_count };
    }
    size_t checkSum() const {
        validateCheckSumRequirements();

        size_t count = 0;
        for (const auto& item : extended_array) {
            if (item) {  
                count++;
            }
        }
        return count;
    }
};