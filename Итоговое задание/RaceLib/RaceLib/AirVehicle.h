#pragma once
#include "Vehicle.h"

class RACECORE_API AirVehicle : public Vehicle {
protected:
    virtual double getDistanceReduction(double distance) const = 0;

public:
    AirVehicle(const std::string& name, double speed);
    ~AirVehicle() override;
    double calculateTime(double distance) const override;
};
