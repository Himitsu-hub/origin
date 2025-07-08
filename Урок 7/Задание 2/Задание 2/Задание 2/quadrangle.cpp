#include "quadrangle.h"
#include "figure_error.h"
#include <iostream>

Quadrangle::Quadrangle(int a, int b, int c, int d, int A, int B, int C, int D, const std::string& name)
    : Figure(name), a(a), b(b), c(c), d(d), A(A), B(B), C(C), D(D) {

    if (A + B + C + D != 360) {
        throw FigureError("Сумма углов не равна 360");
    }

    std::cout << name << " (стороны " << a << ", " << b << ", " << c << ", " << d
        << "; углы " << A << ", " << B << ", " << C << ", " << D << ") создан\n";
}

Quadrangle::Quadrangle(int a, int b, int c, int d, int A, int B, int C, int D)
    : Quadrangle(a, b, c, d, A, B, C, D, "Четырёхугольник") {
}

int Quadrangle::get_a() const { return a; }
int Quadrangle::get_b() const { return b; }
int Quadrangle::get_c() const { return c; }
int Quadrangle::get_d() const { return d; }
int Quadrangle::get_A() const { return A; }
int Quadrangle::get_B() const { return B; }
int Quadrangle::get_C() const { return C; }
int Quadrangle::get_D() const { return D; }

void Quadrangle::print_info() const {
    std::cout << name << ":\n";
    std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << " d=" << d << "\n";
    std::cout << "Углы: A=" << A << " B=" << B << " C=" << C << " D=" << D << "\n\n";
}