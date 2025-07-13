#pragma once
#include "AirVehicle.h"

class RACECORE_API MagicCarpet : public AirVehicle {
public:
    MagicCarpet();
    virtual ~MagicCarpet() override;
    double getDistanceReduction(double distance) const override;
};