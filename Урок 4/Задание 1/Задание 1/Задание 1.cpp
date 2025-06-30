#include <iostream>
#include <string>
using namespace std;

class Figure {
protected:
    int sides_count;
    string name;

    Figure(int count, const string& fig_name)
        : sides_count(count), name(fig_name) {
    }


public:
    Figure() : Figure(0, "Фигура") {}

    int get_sides_count() const {
        return sides_count;
    }

    string get_name() const {
        return name;
    }
};

class Triangle : public Figure {
public:
    Triangle() : Figure(3, "Треугольник") {}
};

class Quadrangle : public Figure {
public:
    Quadrangle() : Figure(4, "Четырёхугольник") {}
};

int main() {
    setlocale(0, "rus");
    Figure figure;
    Triangle triangle;
    Quadrangle quadrangle;

    cout << "Количество сторон:" << endl;
    cout << figure.get_name() << ": " << figure.get_sides_count() << endl;
    cout << triangle.get_name() << ": " << triangle.get_sides_count() << endl;
    cout << quadrangle.get_name() << ": " << quadrangle.get_sides_count() << endl;

    return 0;
}