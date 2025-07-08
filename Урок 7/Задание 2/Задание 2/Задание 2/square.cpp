#include "square.h"
#include "figure_error.h"

Square::Square(int a) : Rectangle(a, a) {
    name = "Квадрат";

    if (a != b || a != c || a != d) {
        throw FigureError("Все стороны должны быть равны");
    }
    if (A != 90 || B != 90 || C != 90 || D != 90) {
        throw FigureError("Все углы должны быть равны 90");
    }
}