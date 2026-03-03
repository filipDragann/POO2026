#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "Movie.h"
#include <cstring>
int NameCompare(Movie a, Movie b) {
	if (!strcmp(a.GetName(), b.GetName()));
	return 0;
	if (strcmp(a.GetName(), b.GetName()) > 0)
		return 1;
	if (strcmp(a.GetName(), b.GetName()) < 0)
		return -1;
}
int ReleaseCompare(Movie a, Movie b) {
	if (a.GetReleaseYear() > b.GetReleaseYear())
		return 1;
	if (a.GetReleaseYear() < b.GetReleaseYear())
		return -1;
	return 0;
}
int ScoreCompare(Movie a, Movie b) {
	if (a.GetScore() > b.GetScore())
		return 1;
	if (a.GetScore() < b.GetScore())
		return -1;
	return 0;
}
int LengthCompare(Movie a, Movie b) {
	if (a.GetMinutes() > b.GetMinutes())
		return 1;
	if (a.GetMinutes() < b.GetMinutes())
		return -1;
	return 0;
}
int PassedYearsCompare(Movie a, Movie b) {
	if (a.GetYear() > b.GetYear())
		return 1;
	if (a.GetYear() < b.GetYear())
		return -1;
	return 0;
}	