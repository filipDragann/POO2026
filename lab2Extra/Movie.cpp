#include "Movie.h"
#include <cstring>
#include <iostream>
#define _CRT_SECURE_NO_WARNINGS
void Movie::SetName(const char* name) {
	
		strncpy(this->movie, name, sizeof(this->movie) - 1);
        this->movie[sizeof(this->movie) - 1] = '\0';

}

void Movie::SetReleaseYear(int releaseyear) {
	this->releaseyear = releaseyear;
}
void Movie::SetYear(int year) {
	this->year = year - releaseyear;
}
void Movie::SetMinutes(int minutes) {
	this->minutes = minutes;
}
void Movie::SetScore(double score) {
	this->score = score;
}

int Movie::GetReleaseYear() {
	return this->releaseyear;
}
const char* Movie::GetName() {
	return this->movie;
}
int Movie::GetYear() {
	return this->year;
}
int Movie::GetMinutes() {
	return this->minutes;
}
double Movie::GetScore() {
	if (score > 1 && score < 10)
		return this->score;
	return -1;
}