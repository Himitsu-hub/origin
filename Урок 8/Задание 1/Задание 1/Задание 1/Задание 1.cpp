#include <iostream>

class Fraction
{
private:
    int numerator_;
    int denominator_;

public:
    Fraction(int numerator, int denominator)
    {
        numerator_ = numerator;
        denominator_ = denominator;
    }

    int compare(const Fraction& other) const {
        long long num1 = static_cast<long long>(numerator_) * other.denominator_;
        long long num2 = static_cast<long long>(other.numerator_) * denominator_;
        if (num1 < num2) return -1;
        if (num1 > num2) return 1;
        return 0;
    }

    bool operator==(const Fraction& other) const { return compare(other) == 0; }
    bool operator!=(const Fraction& other) const { return compare(other) != 0; }
    bool operator<(const Fraction& other) const { return compare(other) < 0; }
    bool operator>(const Fraction& other) const { return compare(other) > 0; }
    bool operator<=(const Fraction& other) const { return compare(other) <= 0; }
    bool operator>=(const Fraction& other) const { return compare(other) >= 0; }
};

int main()
{
    Fraction f1(4, 3);
    Fraction f2(6, 11);

    std::cout << "f1" << ((f1 == f2) ? " == " : " not == ") << "f2" << '\n';
    std::cout << "f1" << ((f1 != f2) ? " != " : " not != ") << "f2" << '\n';
    std::cout << "f1" << ((f1 < f2) ? " < " : " not < ") << "f2" << '\n';
    std::cout << "f1" << ((f1 > f2) ? " > " : " not > ") << "f2" << '\n';
    std::cout << "f1" << ((f1 <= f2) ? " <= " : " not <= ") << "f2" << '\n';
    std::cout << "f1" << ((f1 >= f2) ? " >= " : " not >= ") << "f2" << '\n';
    return 0;
}