#include "equilateral_triangle.h"
#include "figure_error.h"

EquilateralTriangle::EquilateralTriangle(int a)
    : Triangle(a, a, a, 60, 60, 60, "Равносторонний треугольник") {

    if (a != b || a != c) {
        throw FigureError("Все стороны должны быть равны");
    }
    if (A != 60 || B != 60 || C != 60) {
        throw FigureError("Все углы должны быть равны 60");
    }
}