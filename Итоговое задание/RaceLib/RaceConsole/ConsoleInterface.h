#pragma once
#include <memory>
#include "RaceCore.h"

class ConsoleInterface {
private:
    std::unique_ptr<Race> currentRace;

    void showMainMenu();
    void setupRace();
    void registerVehicles();
    void runRace();
    void showResults(const std::vector<std::pair<std::string, double>>& results);

public:
    void start();
};