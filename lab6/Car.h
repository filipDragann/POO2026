#pragma once
#include "Weather.h";

class Car {
protected:
	int fuel_capacity;
	double fuel_consumption;
	int avg_speed;
public:
	Car(int fuel_ca, double fuel_co) : fuel_capacity(fuel_ca), fuel_consumption(fuel_co), avg_speed(0) {};

	virtual double FuelCons() = 0;
	virtual int FuelCap() = 0;
	virtual int Speed(Weather condition) = 0;
	virtual const char* Name() = 0;

	
};