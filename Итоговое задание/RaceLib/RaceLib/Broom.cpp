#include "Broom.h"

Broom::Broom() : AirVehicle("Метла", 20) {}

Broom::~Broom() = default;

double Broom::getDistanceReduction(double distance) const {
    int reductionPercent = static_cast<int>(distance / 1000);
    return reductionPercent * 0.01;
}