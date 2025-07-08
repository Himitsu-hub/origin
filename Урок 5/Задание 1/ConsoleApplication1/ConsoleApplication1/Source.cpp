#include "math.h"
#include <cmath>
#include <stdexcept>
#include <iostream>

double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

double divide(double a, double b) {
    if (b == 0) {
        std:: cout<< "Делить на ноль нельзя!";
    }
    return a / b;
}

double power(double a, double b) {
    return pow(a, b);
}