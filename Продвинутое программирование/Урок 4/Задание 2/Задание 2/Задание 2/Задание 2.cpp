#include <iostream>
#include <vector>

template <typename T>
class Table {
private:
    std::vector<std::vector<T>> data;

public:
    Table(size_t rows, size_t cols) {
        data.resize(rows);
        for (auto& row : data) {
            row.resize(cols);
        }
    }

    std::vector<T>& operator[](size_t index) {
        return data[index];
    }

    const std::vector<T>& operator[](size_t index) const {
        return data[index];
    }

    std::pair<size_t, size_t> Size() const {
        if (data.empty() || data[0].empty()) {
            return { 0, 0 };
        }
        return { data.size(), data[0].size() };
    }
};

int main() {
    Table<int> test(2, 3);
    test[0][0] = 4;
    std::cout << test[0][0] << std::endl; 

    auto size = test.Size();
    std::cout << "Massive size: " << size.first << " rows, " << size.second << " columns" << std::endl;

    return 0;
}