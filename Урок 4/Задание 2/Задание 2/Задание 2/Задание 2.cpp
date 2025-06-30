#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Figure {
protected:
    string name;

    Figure(const string& fig_name) : name(fig_name) {}

public:
    virtual void print_info() const = 0;
    string get_name() const { return name; }
    virtual ~Figure() {}
};

class Triangle : public Figure {
protected:
    int a, b, c;
    int A, B, C;

    Triangle(int a, int b, int c, int A, int B, int C, const string& name)
        : Figure(name), a(a), b(b), c(c), A(A), B(B), C(C) {
    }

public:
    Triangle(int a, int b, int c, int A, int B, int C)
        : Triangle(a, b, c, A, B, C, "Треугольник") {
    }

    int get_a() const { return a; }
    int get_b() const { return b; }
    int get_c() const { return c; }
    int get_A() const { return A; }
    int get_B() const { return B; }
    int get_C() const { return C; }

    void print_info() const override {
        cout << name << ":\n";
        cout << "Стороны: a=" << a << " b=" << b << " c=" << c << "\n";
        cout << "Углы: A=" << A << " B=" << B << " C=" << C << "\n\n";
    }
};

class RightTriangle : public Triangle {
public:
    RightTriangle(int a, int b, int c, int A, int B)
        : Triangle(a, b, c, A, B, 90, "Прямоугольный треугольник") {
    }
};

class IsoscelesTriangle : public Triangle {
public:
    IsoscelesTriangle(int a, int b, int A, int B)
        : Triangle(a, b, a, A, B, A, "Равнобедренный треугольник") {
    }
};

class EquilateralTriangle : public Triangle {
public:
    EquilateralTriangle(int a)
        : Triangle(a, a, a, 60, 60, 60, "Равносторонний треугольник") {
    }
};

class Quadrangle : public Figure {
protected:
    int a, b, c, d;
    int A, B, C, D;

    Quadrangle(int a, int b, int c, int d, int A, int B, int C, int D, const string& name)
        : Figure(name), a(a), b(b), c(c), d(d), A(A), B(B), C(C), D(D) {
    }

public:
    Quadrangle(int a, int b, int c, int d, int A, int B, int C, int D)
        : Quadrangle(a, b, c, d, A, B, C, D, "Четырёхугольник") {
    }

    int get_a() const { return a; }
    int get_b() const { return b; }
    int get_c() const { return c; }
    int get_d() const { return d; }
    int get_A() const { return A; }
    int get_B() const { return B; }
    int get_C() const { return C; }
    int get_D() const { return D; }

    void print_info() const override {
        cout << name << ":\n";
        cout << "Стороны: a=" << a << " b=" << b << " c=" << c << " d=" << d << "\n";
        cout << "Углы: A=" << A << " B=" << B << " C=" << C << " D=" << D << "\n\n";
    }
};


class Rectangle : public Quadrangle {
public:
    Rectangle(int a, int b)
        : Quadrangle(a, b, a, b, 90, 90, 90, 90, "Прямоугольник") {
    }
};

class Square : public Rectangle {
public:
    Square(int a) : Rectangle(a, a) { name = "Квадрат"; }
};

class Parallelogram : public Quadrangle {
public:
    Parallelogram(int a, int b, int A, int B)
        : Quadrangle(a, b, a, b, A, B, A, B, "Параллелограмм") {
    }
};

class Rhombus : public Parallelogram {
public:
    Rhombus(int a, int A, int B)
        : Parallelogram(a, a, A, B) {
        name = "Ромб";
    }
};

int main() {
    setlocale(0, "rus");
    vector<Figure*> figures = {
        new Triangle(10, 20, 30, 50, 60, 70),
        new RightTriangle(10, 20, 30, 50, 60),
        new IsoscelesTriangle(10, 20, 50, 60),
        new EquilateralTriangle(30),
        new Quadrangle(10, 20, 30, 40, 50, 60, 70, 80),
        new Rectangle(10, 20),
        new Square(20),
        new Parallelogram(20, 30, 30, 40),
        new Rhombus(30, 30, 40)
    };

    for (const auto& figure : figures) {
        figure->print_info();
        delete figure;
    }

    return 0;
}