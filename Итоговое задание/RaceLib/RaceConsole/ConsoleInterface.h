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

    std::string RaceTypeToString(RaceType type) const {
        switch (type) {
        case RaceType::GROUND: return "Гонка для наземного транспорта";
        case RaceType::AIR: return "Гонка для воздушного транспорта";
        case RaceType::MIXED: return "Гонка для наземного и воздушного транспорта";
        default: return "Неизвестный тип гонки";
        }
    }

public:
    void start();
};