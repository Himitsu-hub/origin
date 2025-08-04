#include <iostream>
#include <stdexcept>

class smart_array {
private:
    int* data_;
    size_t size_;
    size_t capacity_;

public:
    smart_array(size_t initial_capacity)
        : data_(new int[initial_capacity]),
        size_(0),
        capacity_(initial_capacity) {
    }

    ~smart_array() {
        delete[] data_;
    }

    void add_element(int element) {
        if (size_ >= capacity_) {
            size_t new_capacity = capacity_ * 2;
            int* new_data = new int[new_capacity];

            for (size_t i = 0; i < size_; ++i) {
                new_data[i] = data_[i];
            }

            delete[] data_;
            data_ = new_data;
            capacity_ = new_capacity;
        }

        data_[size_] = element;
        size_++;
    }

    int get_element(size_t index) const {
        if (index >= size_) {
            throw std::out_of_range("Index out of range");
        }
        return data_[index];
    }

    smart_array(const smart_array&) = delete;
    smart_array& operator=(const smart_array&) = delete;
};
int main() {
    try {
        smart_array arr(5);
        arr.add_element(1);
        arr.add_element(4);
        arr.add_element(155);
        arr.add_element(14);
        arr.add_element(15);
        std::cout << arr.get_element(1) << std::endl;
    }
    catch (const std::exception& ex) {
        std::cout << ex.what() << std::endl;
    }

    return 0;
}

