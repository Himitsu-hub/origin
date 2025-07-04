#ifndef QUADRANGLE_H
#define QUADRANGLE_H

#include "figure.h"
using namespace std;

class Quadrangle : public Figure {
protected:
    int a, b, c, d;
    int A, B, C, D;

    Quadrangle(int a, int b, int c, int d, int A, int B, int C, int D, const string& name);

public:
    Quadrangle(int a, int b, int c, int d, int A, int B, int C, int D);

    int get_a() const;
    int get_b() const;
    int get_c() const;
    int get_d() const;
    int get_A() const;
    int get_B() const;
    int get_C() const;
    int get_D() const;

    void print_info() const override;
};

#endif