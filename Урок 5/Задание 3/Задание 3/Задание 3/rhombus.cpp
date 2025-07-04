#include "rhombus.h"
using namespace std;

Rhombus::Rhombus(int a, int A, int B)
    : Parallelogram(a, a, A, B) {
    name = "Ромб";
}