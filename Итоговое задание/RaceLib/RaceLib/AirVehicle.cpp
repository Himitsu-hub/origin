#include "AirVehicle.h"

AirVehicle::AirVehicle(const std::string& name, double speed)
    : Vehicle(name, speed, VehicleType::AIR) {
}

AirVehicle::~AirVehicle() = default;

double AirVehicle::calculateTime(double distance) const {
    double effectiveDistance = distance * (1 - getDistanceReduction(distance));
    return effectiveDistance / speed;
}