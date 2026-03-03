#pragma once
#include "Movie.h"
#include <vector>
#include <iostream>
#include <algorithm>
class MovieSeries {
	std::vector<Movie*> movies;
	int count;
public:
	MovieSeries() : count(0) {}
	~MovieSeries() {}

	void Init() { count = 0;  }
	void Add(Movie* m) { movies.push_back(m); count++; }
	void Print() const;
	void Sort();
};