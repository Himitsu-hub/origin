#pragma once
#include "RaceCoreExport.h"
#include "RaceType.h"
#include <string>

class RACECORE_API Vehicle {
protected:
    std::string name;
    double speed;
    VehicleType type;

public:
    Vehicle(const std::string& name, double speed, VehicleType type);
    virtual ~Vehicle();

    virtual double calculateTime(double distance) const = 0;

    std::string getName() const;
    double getSpeed() const;
    VehicleType getType() const;
};