#include "Vehicle.h"

Vehicle::Vehicle(const std::string& name, double speed, VehicleType type)
    : name(name), speed(speed), type(type) {
}

Vehicle::~Vehicle() = default;

std::string Vehicle::getName() const { return name; }
double Vehicle::getSpeed() const { return speed; }
VehicleType Vehicle::getType() const { return type; }