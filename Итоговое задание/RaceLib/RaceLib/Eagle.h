#pragma once
#include "AirVehicle.h"

class RACECORE_API Eagle : public AirVehicle {
public:
    Eagle();
    virtual ~Eagle() override;
    double getDistanceReduction(double distance) const override;
};