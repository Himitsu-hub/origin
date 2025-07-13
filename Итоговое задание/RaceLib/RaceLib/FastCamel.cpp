#include "FastCamel.h"

FastCamel::FastCamel() : GroundVehicle("Верблюд-быстроход", 40, 10) {}

FastCamel::~FastCamel() = default;

double FastCamel::getRestTime(int restCount) const {
    if (restCount == 1) return 5;
    if (restCount == 2) return 6.5;
    return 8;
}