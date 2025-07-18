#pragma once
#include "GroundVehicle.h"

class RACECORE_API Centaur : public GroundVehicle {
public:
    Centaur();
    ~Centaur() override;
    double getRestTime(int restCount) const override;
};