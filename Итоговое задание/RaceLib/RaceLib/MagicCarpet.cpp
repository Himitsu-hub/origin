#include "MagicCarpet.h"

MagicCarpet::MagicCarpet() : AirVehicle("Ковёр-самолёт", 10) {}

MagicCarpet::~MagicCarpet() = default;

double MagicCarpet::getDistanceReduction(double distance) const {
    if (distance < 1000) return 0;
    if (distance < 5000) return 0.03;
    if (distance < 10000) return 0.10;
    return 0.05;
}