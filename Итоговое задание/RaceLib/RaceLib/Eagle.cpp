#include "Eagle.h"

Eagle::Eagle() : AirVehicle("Орёл", 8) {}

Eagle::~Eagle() = default;

double Eagle::getDistanceReduction(double distance) const {
    return 0.06;
}