#include "parallelogram.h"
#include "figure_error.h"

Parallelogram::Parallelogram(int a, int b, int A, int B)
    : Quadrangle(a, b, a, b, A, B, A, B, "Параллелограмм") {

    if (a != c || b != d) {
        throw FigureError("Стороны должны быть попарно равны");
    }
    if (A != C || B != D) {
        throw FigureError("Углы должны быть попарно равны");
    }
}