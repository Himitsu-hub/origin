#pragma once
#include "Vehicle.h"

class RACECORE_API GroundVehicle : public Vehicle {
protected:
    double drivingTime;
    virtual double getRestTime(int restCount) const = 0;

public:
    GroundVehicle(const std::string& name, double speed, double drivingTime);
    ~GroundVehicle() override;
    double calculateTime(double distance) const override;
};