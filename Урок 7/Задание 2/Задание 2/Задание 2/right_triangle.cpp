#include "right_triangle.h"
#include "figure_error.h"

RightTriangle::RightTriangle(int a, int b, int c, int A, int B)
    : Triangle(a, b, c, A, B, 90, "Прямоугольный треугольник") {

    if (C != 90) {
        throw FigureError("Угол C должен быть равен 90");
    }
}