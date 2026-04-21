#include "RangeRover.h"
int RangeRover::FuelCap()
{
	return fuel_capacity;
}
double RangeRover::FuelCons()
{
	return fuel_consumption;
}
int RangeRover::Speed(Weather weather)
{
	switch (weather)
	{
	case Rain:
		return 50;
		break;
	case Sunny:
		return 60;
		break;
	case Snowy:
		return 55;
		break;
	default:
		return 0;
	}
}
const char* RangeRover::Name()
{
	return "RangeRover";
}