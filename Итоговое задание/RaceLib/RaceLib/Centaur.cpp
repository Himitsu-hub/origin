#include "Centaur.h"

Centaur::Centaur() : GroundVehicle("Кентавр", 15, 8) {}

Centaur::~Centaur() = default;

double Centaur::getRestTime(int restCount) const {
    return 2;
}