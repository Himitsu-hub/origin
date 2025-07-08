#include "rhombus.h"
#include "figure_error.h"

Rhombus::Rhombus(int a, int A, int B)
    : Parallelogram(a, a, A, B) {
    name = "Ромб";

    if (a != b || a != c || a != d) {
        throw FigureError("Все стороны должны быть равны");
    }
    if (A != C || B != D) {
        throw FigureError("Углы должны быть попарно равны");
    }
}