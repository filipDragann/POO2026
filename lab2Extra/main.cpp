#include "Movie.h"
#include "MovieSeries.h"
#include "Movie2.h"
#include <iostream>
using namespace std;

int main() {
    Movie ep5;
    ep5.SetName("Star Wars: Episode V - The Empire Strikes Back");
    ep5.SetScore(8.7);
    ep5.SetYear(1980);
    ep5.SetMinutes(124);

    Movie ep4;
    ep4.SetName("Star Wars: Episode IV - A New Hope");
    ep4.SetScore(8.6);
    ep4.SetYear(1977);
    ep4.SetMinutes(121);

    Movie ep6;
    ep6.SetName("Star Wars: Episode VI - Return of the Jedi");
    ep6.SetScore(8.3);
    ep6.SetYear(1983);
    ep6.SetMinutes(131);

    printf(
        R"(
ep4, ep5 comparisons:
name        : %d
year        : %d
score       : %d
length      : %d

)",
NameCompare(ep4, ep5),
ReleaseCompare(ep4, ep5),
ScoreCompare(ep4, ep5),
LengthCompare(ep4, ep5),
PassedYearsCompare(ep4, ep5));

    MovieSeries series;
    series.Init();
    series.Add(&ep5);
    series.Add(&ep4);
    series.Add(&ep6);

    series.Sort();
    series.Print();

    return 0;
}