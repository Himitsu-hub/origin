#include "quadrangle.h"
#include <iostream>

Quadrangle::Quadrangle(int a, int b, int c, int d, int A, int B, int C, int D, const string& name)
    : Figure(name), a(a), b(b), c(c), d(d), A(A), B(B), C(C), D(D) {
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
    cout << name << ":\n";
    cout << "Стороны: a=" << a << " b=" << b << " c=" << c << " d=" << d << "\n";
    cout << "Углы: A=" << A << " B=" << B << " C=" << C << " D=" << D << "\n\n";
}