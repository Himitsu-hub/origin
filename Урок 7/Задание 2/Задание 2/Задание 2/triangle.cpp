#include "triangle.h"
#include "figure_error.h"
#include <iostream>

Triangle::Triangle(int a, int b, int c, int A, int B, int C, const std::string& name)
    : Figure(name), a(a), b(b), c(c), A(A), B(B), C(C) {

    if (A + B + C != 180) {
        throw FigureError("Сумма углов не равна 180");
    }

    std::cout << name << " (стороны " << a << ", " << b << ", " << c
        << "; углы " << A << ", " << B << ", " << C << ") создан\n";
}

Triangle::Triangle(int a, int b, int c, int A, int B, int C)
    : Triangle(a, b, c, A, B, C, "Треугольник") {
}

int Triangle::get_a() const { return a; }
int Triangle::get_b() const { return b; }
int Triangle::get_c() const { return c; }
int Triangle::get_A() const { return A; }
int Triangle::get_B() const { return B; }
int Triangle::get_C() const { return C; }

void Triangle::print_info() const {
    std::cout << name << ":\n";
    std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << "\n";
    std::cout << "Углы: A=" << A << " B=" << B << " C=" << C << "\n\n";
}