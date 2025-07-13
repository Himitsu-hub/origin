#pragma once
#include "GroundVehicle.h"

class RACECORE_API Camel : public GroundVehicle {
public:
    Camel();
    virtual ~Camel() override;
    double getRestTime(int restCount) const override;
};