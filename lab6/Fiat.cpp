#include "Fiat.h"
int Fiat::FuelCap()
{
	return fuel_capacity;
}
double Fiat::FuelCons()
{
	return fuel_consumption;
}
int Fiat::Speed(Weather weather)
{
	switch (weather)
	{
	case Rain:
		return 30;
		break;
	case Sunny:
		return 50;
		break;
	case Snowy:
		return 25;
		break;
	default:
		return 0;
	}
}
const char* Fiat::Name()
{
	return "Fiat";
}