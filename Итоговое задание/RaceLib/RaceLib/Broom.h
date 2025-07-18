#pragma once
#include "AirVehicle.h"

class RACECORE_API Broom : public AirVehicle {
public:
    Broom();
    ~Broom() override;
    double getDistanceReduction(double distance) const override;
};