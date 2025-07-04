#include <iostream>
#include <vector>
#include "triangle.h"
#include "right_triangle.h"
#include "isosceles_triangle.h"
#include "equilateral_triangle.h"
#include "quadrangle.h"
#include "rectangle.h"
#include "square.h"
#include "parallelogram.h"
#include "rhombus.h"
using namespace std;

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