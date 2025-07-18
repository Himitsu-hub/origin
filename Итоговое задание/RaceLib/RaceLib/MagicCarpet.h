#pragma once
#include "AirVehicle.h"

class RACECORE_API MagicCarpet : public AirVehicle {
public:
    MagicCarpet();
    ~MagicCarpet() override;
    double getDistanceReduction(double distance) const override;
};