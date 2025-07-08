#include "rectangle.h"
#include "figure_error.h"

Rectangle::Rectangle(int a, int b)
    : Quadrangle(a, b, a, b, 90, 90, 90, 90, "Прямоугольник") {

    if (a != c || b != d) {
        throw FigureError("Стороны должны быть попарно равны");
    }
    if (A != 90 || B != 90 || C != 90 || D != 90) {
        throw FigureError("Все углы должны быть равны 90");
    }
}