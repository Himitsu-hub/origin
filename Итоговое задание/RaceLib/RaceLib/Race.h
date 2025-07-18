#pragma once
#include "RaceCoreExport.h"
#include <vector>
#include <memory>
#include "Vehicle.h"

class RACECORE_API Race {
private:
    RaceType type;
    double distance;
    std::vector<std::shared_ptr<Vehicle>> vehicles;

public:

    Race(RaceType type, double distance);
    ~Race();

    bool registerVehicle(std::shared_ptr<Vehicle> vehicle);
    std::vector<std::pair<std::string, double>> runRace() const;

    std::vector<std::shared_ptr<Vehicle>> getRegisteredVehicles() const;

    RaceType getType() const;
    double getDistance() const;
    int getRegisteredCount() const;

};