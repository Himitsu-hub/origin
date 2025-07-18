#pragma once
#include "GroundVehicle.h"

class RACECORE_API Camel : public GroundVehicle {
public:
    Camel();
    ~Camel() override;
    double getRestTime(int restCount) const override;
};