#include "Boots.h"

Boots::Boots() : GroundVehicle("Ботинки-вездеходы", 6, 60) {}

Boots::~Boots() = default;

double Boots::getRestTime(int restCount) const {
    return (restCount == 1) ? 10 : 5;
}