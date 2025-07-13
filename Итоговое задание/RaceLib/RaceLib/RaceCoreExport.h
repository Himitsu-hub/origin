#pragma once

#ifdef RACECORE_EXPORTS
#define RACECORE_API __declspec(dllexport)
#else
#define RACECORE_API __declspec(dllimport)
#endif