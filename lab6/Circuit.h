#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
#include "Car.h"
#include "Weather.h"
#include "Volvo.h"
#include "Fiat.h"
#include "RangeRover.h"
#include "Seat.h"
#include "BMW.h"
struct ceva{
	int index;
	double time;
};
class Circuit {
protected:
	int length;
	Weather current_Weather;
	std::vector<Car*> cars;
	
	std::vector<ceva> finished_cars;
	std::vector<int> unfinished_cars;
	

public:
	void SetLength(int clength);
	void SetWeather(Weather weather);
	void AddCar(Car* car);
	void Race();
	void ShowFinalRanks();
	void ShowWhoDidntFinish();

};