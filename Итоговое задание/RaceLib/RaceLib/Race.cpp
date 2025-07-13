#include "Race.h"
#include <algorithm>

Race::Race(RaceType type, double distance) : type(type), distance(distance) {}
Race::~Race() = default;

bool Race::registerVehicle(std::shared_ptr<Vehicle> vehicle) {
    if ((type == RaceType::GROUND && vehicle->getType() != VehicleType::GROUND) ||
        (type == RaceType::AIR && vehicle->getType() != VehicleType::AIR)) {
        return false;
    }

    for (const auto& v : vehicles) {
        if (v->getName() == vehicle->getName()) {
            return false;
        }
    }

    vehicles.push_back(vehicle);
    return true;
}

std::vector<std::pair<std::string, double>> Race::runRace() const {
    std::vector<std::pair<std::string, double>> results;

    for (const auto& vehicle : vehicles) {
        double time = vehicle->calculateTime(distance);
        results.emplace_back(vehicle->getName(), time);
    }

    std::sort(results.begin(), results.end(),
        [](const auto& a, const auto& b) { return a.second < b.second; });

    return results;
}

RaceType Race::getType() const { return type; }
double Race::getDistance() const { return distance; }
int Race::getRegisteredCount() const { return vehicles.size(); }