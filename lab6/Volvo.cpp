#include "Volvo.h"
int Volvo::FuelCap()
{
	return fuel_capacity;
}
double Volvo::FuelCons()
{
	return fuel_consumption;
}
int Volvo::Speed(Weather weather)
{
	switch (weather)
	{
	case Rain:
		return 60;
		break;
	case Sunny:
		return 80;
		break;
	case Snowy:
		return 50;
		break;
	default:
		return 0;
	}
}
const char* Volvo::Name()
{
	return "Volvo";
}