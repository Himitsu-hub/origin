#pragma once

#ifdef RACECORE_EXPORTS
#define RACECORE_API __declspec(dllexport)
#else
#define RACECORE_API __declspec(dllimport)
#endif

#pragma warning(push)
#pragma warning(disable: 4251)
#pragma warning(pop)