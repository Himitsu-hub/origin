#pragma once
#ifdef RACECORE_EXPORTS
#define RACECORE_API __declspec(dllexport)
#else
#define RACECORE_API __declspec(dllimport)
#endif

#include "RaceType.h"

#include "Vehicle.h"
#include "GroundVehicle.h"
#include "AirVehicle.h"

#include "Race.h"

#include "Camel.h"
#include "FastCamel.h"
#include "Centaur.h"
#include "Boots.h"
#include "MagicCarpet.h"
#include "Eagle.h"
#include "Broom.h"