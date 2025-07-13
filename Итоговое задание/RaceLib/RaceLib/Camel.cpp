#include "Camel.h"

Camel::Camel() : GroundVehicle("Верблюд", 10, 30) {}
Camel::~Camel() = default;

double Camel::getRestTime(int restCount) const {
    return (restCount == 1) ? 5 : 8;
}