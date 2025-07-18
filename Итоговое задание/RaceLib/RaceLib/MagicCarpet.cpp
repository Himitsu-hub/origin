#include "MagicCarpet.h"

namespace {
    constexpr double SHORT_DISTANCE = 1000.0;
    constexpr double MEDIUM_DISTANCE = 5000.0;
    constexpr double LONG_DISTANCE = 10000.0;

    constexpr double NO_REDUCTION = 0.0;
    constexpr double SHORT_REDUCTION = 0.03;
    constexpr double MEDIUM_REDUCTION = 0.10;
    constexpr double LONG_REDUCTION = 0.05;
}

MagicCarpet::MagicCarpet() : AirVehicle("Ковёр-самолёт", 10) {}

MagicCarpet::~MagicCarpet() = default;

double MagicCarpet::getDistanceReduction(double distance) const {
    if (distance < SHORT_DISTANCE) return NO_REDUCTION;
    if (distance < MEDIUM_DISTANCE) return SHORT_REDUCTION;
    if (distance < LONG_DISTANCE) return MEDIUM_REDUCTION;
    return LONG_REDUCTION;
}