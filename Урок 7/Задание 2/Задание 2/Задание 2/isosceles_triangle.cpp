#include "isosceles_triangle.h"
#include "figure_error.h"

IsoscelesTriangle::IsoscelesTriangle(int a, int b, int A, int B)
    : Triangle(a, b, a, A, B, A, "Равнобедренный треугольник") {

    if (a != c) {
        throw FigureError("Стороны a и c должны быть равны");
    }
    if (A != C) {
        throw FigureError("Углы A и C должны быть равны");
    }
}