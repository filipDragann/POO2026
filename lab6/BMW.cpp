#include "BMW.h"
int BMW::FuelCap()
{
	return fuel_capacity;
}
double BMW::FuelCons()
{
	return fuel_consumption;
}
int BMW::Speed(Weather weather)
{
	switch (weather)
	{
	case Rain:
		return 60;
		break;
	case Sunny:
		return 90;
		break;
	case Snowy:
		return 45;
		break;
	default:
		return 0;
	}
}
const char* BMW::Name()
{
	return "BMW";
}