#pragma once
#include "GroundVehicle.h"

class RACECORE_API FastCamel : public GroundVehicle {
public:
    FastCamel();
    ~FastCamel() override;
    double getRestTime(int restCount) const override;
};