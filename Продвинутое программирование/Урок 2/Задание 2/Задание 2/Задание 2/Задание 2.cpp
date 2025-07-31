#include <iostream>
#include <stdexcept>
#include <algorithm> 

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

    smart_array(const smart_array& other)
        : data_(new int[other.capacity_]),
        size_(other.size_),
        capacity_(other.capacity_) {
        std::copy(other.data_, other.data_ + other.size_, data_);
    }

    smart_array& operator=(const smart_array& other) {
        if (this != &other) { 
            int* new_data = new int[other.capacity_];
            std::copy(other.data_, other.data_ + other.size_, new_data);

            delete[] data_;

            data_ = new_data;
            size_ = other.size_;
            capacity_ = other.capacity_;
        }
        return *this;
    }

    ~smart_array() {
        delete[] data_;
    }

    void add_element(int element) {
        if (size_ >= capacity_) {
            size_t new_capacity = capacity_ * 2;
            int* new_data = new int[new_capacity];
            std::copy(data_, data_ + size_, new_data);
            delete[] data_;
            data_ = new_data;
            capacity_ = new_capacity;
        }
        data_[size_++] = element;
    }

    int get_element(size_t index) const {
        if (index >= size_) {
            throw std::out_of_range("Index out of range");
        }
        return data_[index];
    }

    size_t get_size() const { return size_; }
    size_t get_capacity() const { return capacity_; }
};
int main() {
    smart_array arr(5);
    arr.add_element(1);
    arr.add_element(4);
    arr.add_element(155);

    smart_array new_array(2);
    new_array.add_element(44);
    new_array.add_element(34);

    arr = new_array; 

    for (size_t i = 0; i < arr.get_size(); ++i) {
        std::cout << arr.get_element(i) << " ";
    }
    std::cout << std::endl;

    return 0;
}