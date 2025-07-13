#include "GroundVehicle.h"
#include <cmath>

GroundVehicle::GroundVehicle(const std::string& name, double speed, double drivingTime)
    : Vehicle(name, speed, VehicleType::GROUND), drivingTime(drivingTime) {
}

GroundVehicle::~GroundVehicle() = default;

double GroundVehicle::calculateTime(double distance) const {
    double totalTime = 0.0;
    double remainingDistance = distance;
    int restCount = 0;

    while (remainingDistance > 0) {
        double segmentDistance = std::min(drivingTime * speed, remainingDistance);
        double segmentTime = segmentDistance / speed;
        totalTime += segmentTime;
        remainingDistance -= segmentDistance;

        if (remainingDistance > 0) {
            totalTime += getRestTime(++restCount);
        }
    }

    return totalTime;
}