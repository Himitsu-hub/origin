#include "ConsoleInterface.h"
#include "VehicleFactory.h"
#include <iostream>
#include <limits>

void ConsoleInterface::start() {
    while (true) {
        showMainMenu();
    }
}

void ConsoleInterface::showMainMenu() {
    std::cout << "\n=== Симулятор гонок ===" << std::endl;
    std::cout << "1. Создать новую гонку" << std::endl;
    std::cout << "2. Выйти" << std::endl;

    int choice;
    std::cin >> choice;

    if (choice == 1) {
        setupRace();
    }
    else if (choice == 2) {
        exit(0);
    }
}

void ConsoleInterface::setupRace() {
    std::cout << "\nВыберите тип гонки:" << std::endl;
    std::cout << "1. Гонка для наземного транспорта" << std::endl;
    std::cout << "2. Гонка для воздушного транспорта" << std::endl;
    std::cout << "3. Гонка для наземного и воздушного транспорта" << std::endl;

    int typeChoice;
    std::cin >> typeChoice;

    RaceType type;
    switch (typeChoice) {
    case 1: type = RaceType::GROUND; break;
    case 2: type = RaceType::AIR; break;
    case 3: type = RaceType::MIXED; break;
    default: return;
    }

    std::cout << "Укажите длину дистанции (должна быть положительна): ";
    double distance;
    std::cin >> distance;

    currentRace = std::make_unique<Race>(type, distance);
    registerVehicles();
}

void ConsoleInterface::registerVehicles() {
    VehicleFactory factory;

    while (true) {
        std::cout << "\n" << RaceTypeToString(currentRace->getType())
            << ". Дистанция: " << currentRace->getDistance() << std::endl;

        auto registeredVehicles = currentRace->getRegisteredVehicles();
        if (!registeredVehicles.empty()) {
            std::cout << "Зарегистрированные транспортные средства: ";
            for (size_t i = 0; i < registeredVehicles.size(); ++i) {
                if (i > 0) std::cout << ", ";
                std::cout << registeredVehicles[i]->getName();
            }
            std::cout << std::endl;
        }

        factory.showAvailableVehicles(currentRace->getType());

        std::cout << "0. Закончить регистрацию" << std::endl;
        std::cout << "Выберите транспорт или 0 для окончания процесса регистрации: ";

        int choice;
        std::cin >> choice;

        if (choice == 0) {
            if (currentRace->getRegisteredCount() >= 2) {
                runRace();
                return;
            }
            else {
                std::cout << "Для гонки нужно как минимум 2 транспортных средства!" << std::endl;
                continue;
            }
        }

        auto vehicle = factory.createVehicle(choice);
        if (vehicle) {
            if (currentRace->registerVehicle(vehicle)) {
                std::cout << vehicle->getName() << " успешно зарегистрирован!" << std::endl;
            }
            else {
                std::cout << "Этот транспорт уже зарегистрирован или не подходит для данной гонки!" << std::endl;
            }
        }
        else {
            std::cout << "Неверный выбор транспорта!" << std::endl;
        }
    }
}

void ConsoleInterface::runRace() {
    auto results = currentRace->runRace();
    showResults(results);

    while (true) {
        std::cout << "\n1. Провести ещё одну гонку" << std::endl;
        std::cout << "2. Выйти" << std::endl;

        int choice;
        std::cin >> choice;

        if (choice == 1) {
            return;
        }
        else if (choice == 2) {
            exit(0);
        }
        else {
            std::cout << "Неверный выбор, попробуйте снова" << std::endl;
        }
    }
}

void ConsoleInterface::showResults(const std::vector<std::pair<std::string, double>>& results) {
    std::cout << "\n=== Результаты гонки ===" << std::endl;
    std::cout << "Дистанция: " << currentRace->getDistance() << std::endl;

    int position = 1;
    for (const auto& result : results) {
        std::cout << position++ << ". " << result.first << ": " << result.second << " ч" << std::endl;
    }

    std::cout << "\nГонка завершена!" << std::endl;
}

