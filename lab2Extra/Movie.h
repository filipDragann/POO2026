#pragma once
class Movie {
private:
	char movie[256];
	int releaseyear;
	int year;
	double score;
	int minutes;
public:
	void SetName(const char* name);
	void SetReleaseYear(int year);
	void SetScore(double score);
	void SetMinutes(int minutes);
	void SetYear(int year);
	const char* GetName();
	int GetReleaseYear();
	double GetScore();
	int GetMinutes();
	int GetYear();
};