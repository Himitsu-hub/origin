#pragma once
#include "GroundVehicle.h"

class RACECORE_API Boots : public GroundVehicle {
public:
    Boots();
    virtual ~Boots() override;
    double getRestTime(int restCount) const override;
};