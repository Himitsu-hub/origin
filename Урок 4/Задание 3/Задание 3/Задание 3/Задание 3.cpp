#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Figure {
protected:
    int sides_count;
    string name;

    Figure(int count, const string& n) : sides_count(count), name(n) {}

public:
    Figure() : Figure(0, "Фигура") {}

    virtual bool check() const {
        return sides_count == 0;
    }

    virtual void print_info() const {
        cout << name << ":\n";
        cout << (check() ? "Правильная" : "Неправильная") << endl;
        cout << "Количество сторон: " << sides_count << "\n";
    }

    virtual ~Figure() {}
};

class Triangle : public Figure {
protected:
    int a, b, c;
    int A, B, C;

public:
    Triangle(int a, int b, int c, int A, int B, int C)
        : Figure(3, "Треугольник"), a(a), b(b), c(c), A(A), B(B), C(C) {
    }

    bool check() const override {
        return (A + B + C == 180);
    }

    void print_info() const override {
        Figure::print_info();
        cout << "Стороны: a=" << a << " b=" << b << " c=" << c << "\n";
        cout << "Углы: A=" << A << " B=" << B << " C=" << C << "\n\n";
    }
};

class RightTriangle : public Triangle {
public:
    RightTriangle(int a, int b, int c, int A, int B)
        : Triangle(a, b, c, A, B, 90) {
        name = "Прямоугольный треугольник";
    }

    bool check() const override {
        return Triangle::check() && (C == 90) && (A + B == 90);
    }
};

class IsoscelesTriangle : public Triangle {
public:
    IsoscelesTriangle(int a, int b, int A, int B)
        : Triangle(a, b, a, A, B, A) {
        name = "Равнобедренный треугольник";
    }

    bool check() const override {
        return Triangle::check() && (a == c) && (A == C);
    }
};

class EquilateralTriangle : public Triangle {
public:
    EquilateralTriangle(int a)
        : Triangle(a, a, a, 60, 60, 60) {
        name = "Равносторонний треугольник";
    }

    bool check() const override {
        return Triangle::check() && (a == b && b == c) && (A == 60 && B == 60 && C == 60);
    }
};

class Quadrangle : public Figure {
protected:
    int a, b, c, d;
    int A, B, C, D;

public:
    Quadrangle(int a, int b, int c, int d, int A, int B, int C, int D)
        : Figure(4, "Четырёхугольник"), a(a), b(b), c(c), d(d), A(A), B(B), C(C), D(D) {
    }

    bool check() const override {
        return (A + B + C + D == 360);
    }

    void print_info() const override {
        Figure::print_info();
        cout << "Стороны: a=" << a << " b=" << b << " c=" << c << " d=" << d << "\n";
        cout << "Углы: A=" << A << " B=" << B << " C=" << C << " D=" << D << "\n\n";
    }
};

class Rectangle : public Quadrangle {
public:
    Rectangle(int a, int b)
        : Quadrangle(a, b, a, b, 90, 90, 90, 90) {
        name = "Прямоугольник";
    }

    bool check() const override {
        return Quadrangle::check() && (a == c && b == d) && (A == 90 && B == 90 && C == 90 && D == 90);
    }
};

class Square : public Rectangle {
public:
    Square(int a) : Rectangle(a, a) {
        name = "Квадрат";
    }

    bool check() const override {
        return Rectangle::check() && (a == b && b == c && c == d);
    }
};

class Parallelogram : public Quadrangle {
public:
    Parallelogram(int a, int b, int A, int B)
        : Quadrangle(a, b, a, b, A, B, A, B) {
        name = "Параллелограмм";
    }

    bool check() const override {
        return false; 
    }
};

class Rhombus : public Parallelogram {
public:
    Rhombus(int a, int A, int B)
        : Parallelogram(a, a, A, B) {
        name = "Ромб";
    }

    bool check() const override {
        return false; 
    }
};

int main() {
    setlocale(0, "rus");
    vector<Figure*> figures = {
        new Figure(),
        new Triangle(10, 20, 30, 50, 60, 70),
        new RightTriangle(10, 20, 30, 50, 60),
        new RightTriangle(10, 20, 30, 50, 40),
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