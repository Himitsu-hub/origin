#pragma once
#include <memory>
#include <vector>
#include "RaceCore.h"
#include <iostream>

class VehicleFactory {
public:
    void showAvailableVehicles(RaceType raceType) const {
        std::cout << "\nДоступные транспортные средства:\n";

        if (raceType == RaceType::GROUND || raceType == RaceType::MIXED) {
            std::cout << "Наземные:\n";
            std::cout << "1. Верблюд\n";
            std::cout << "2. Верблюд-быстроход\n";
            std::cout << "3. Кентавр\n";
            std::cout << "4. Ботинки-вездеходы\n";
        }

        if (raceType == RaceType::AIR || raceType == RaceType::MIXED) {
            std::cout << "Воздушные:\n";
            std::cout << "5. Ковёр-самолёт\n";
            std::cout << "6. Орёл\n";
            std::cout << "7. Метла\n";
        }

        std::cout << "Выберите транспорт: ";
    }

    std::shared_ptr<Vehicle> createVehicle(int choice) const {
        switch (choice) {
        case 1: return std::make_shared<Camel>();
        case 2: return std::make_shared<FastCamel>();
        case 3: return std::make_shared<Centaur>();
        case 4: return std::make_shared<Boots>();
        case 5: return std::make_shared<MagicCarpet>();
        case 6: return std::make_shared<Eagle>();
        case 7: return std::make_shared<Broom>();
        default: return nullptr;
        }
    }
};