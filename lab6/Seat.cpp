#include "Seat.h"
int Seat::FuelCap()
{
	return fuel_capacity;
}
double Seat::FuelCons()
{
	return fuel_consumption;
}
int Seat::Speed(Weather weather)
{
	switch (weather)
	{
	case Rain:
		return 70;
		break;
	case Sunny:
		return 100;
		break;
	case Snowy:
		return 55;
		break;
	default:
		return 0;
	}
}
const char* Seat::Name()
{
	return "Seat";
}