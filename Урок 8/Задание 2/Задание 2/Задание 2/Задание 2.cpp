#include <iostream>
#include <stdexcept>
#include <cstdlib> 

class Fraction {
private:
    int numerator;
    int denominator;

    int gcd(int a, int b) const {
        a = abs(a);
        b = abs(b);
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }


    void simplify() {
        int common_divisor = gcd(numerator, denominator);
        numerator /= common_divisor;
        denominator /= common_divisor;
        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }
    }

public:
    Fraction(int num = 0, int denom = 1) : numerator(num), denominator(denom) {
        if (denominator == 0) throw std::invalid_argument("Знаменатель не может быть нулем");
        simplify();
    }

    Fraction operator+(const Fraction& other) const {
        return Fraction(numerator * other.denominator + other.numerator * denominator,
            denominator * other.denominator);
    }

    Fraction operator-(const Fraction& other) const {
        return Fraction(numerator * other.denominator - other.numerator * denominator,
            denominator * other.denominator);
    }

    Fraction operator*(const Fraction& other) const {
        return Fraction(numerator * other.numerator, denominator * other.denominator);
    }

    Fraction operator/(const Fraction& other) const {
        if (other.numerator == 0) throw std::invalid_argument("Деление на ноль");
        return Fraction(numerator * other.denominator, denominator * other.numerator);
    }

    Fraction operator-() const {
        return Fraction(-numerator, denominator);
    }

    Fraction& operator++() {
        numerator += denominator;
        simplify();
        return *this;
    }

    Fraction operator++(int) {
        Fraction temp = *this;
        ++(*this);
        return temp;
    }

    Fraction& operator--() {
        numerator -= denominator;
        simplify();
        return *this;
    }

    Fraction operator--(int) {
        Fraction temp = *this;
        --(*this);
        return temp;
    }

    friend std::ostream& operator<<(std::ostream& os, const Fraction& f) {
        os << f.numerator;
        if (f.denominator != 1) os << '/' << f.denominator;
        return os;
    }
};

int main() {
    setlocale(0, "rus");
    try {
        int num1, denom1, num2, denom2;

        std::cout << "Введите числитель дроби 1: ";
        std::cin >> num1;
        std::cout << "Введите знаменатель дроби 1: ";
        std::cin >> denom1;

        std::cout << "Введите числитель дроби 2: ";
        std::cin >> num2;
        std::cout << "Введите знаменатель дроби 2: ";
        std::cin >> denom2;

        Fraction f1(num1, denom1);
        Fraction f2(num2, denom2);

        std::cout << f1 << " + " << f2 << " = " << (f1 + f2) << '\n';
        std::cout << f1 << " - " << f2 << " = " << (f1 - f2) << '\n';
        std::cout << f1 << " * " << f2 << " = " << (f1 * f2) << '\n';
        std::cout << f1 << " / " << f2 << " = " << (f1 / f2) << '\n';

        Fraction temp = f1;
        std::cout << "++" << temp << " * " << f2 << " = " << (++temp * f2) << '\n';
        std::cout << "Значение дроби 1 = " << temp << '\n';

        temp = f1;
        std::cout << temp << "-- * " << f2 << " = " << (temp-- * f2) << '\n';
        std::cout << "Значение дроби 1 = " << temp << '\n';

    }
    catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << '\n';
    }

    return 0;
}