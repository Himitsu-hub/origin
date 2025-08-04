#include <iostream>
#include <vector>
#include <algorithm>

class DivisibleByThreeCounter {
private:
    int sum = 0;
    int count = 0;

public:
    void operator()(int num) {
        if (num % 3 == 0) {
            sum += num;
            count++;
        }
    }

    int get_sum() const {
        return sum;
    }

    int get_count() const {
        return count;
    }
};

int main() {
    std::vector<int> numbers = { 4, 1, 3, 6, 25, 54 };

    DivisibleByThreeCounter counter = std::for_each(
        numbers.begin(),
        numbers.end(),
        DivisibleByThreeCounter()
    );

    std::cout << "get_sum() = " << counter.get_sum() << std::endl;
    std::cout << "get_count() = " << counter.get_count() << std::endl;

    return 0;
}