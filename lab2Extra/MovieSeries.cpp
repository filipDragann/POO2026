#include "MovieSeries.h"


void MovieSeries::Print() const {
	for (const auto& movie : movies) {
		std::cout << "name: " << movie->GetName() << "\n";
		std::cout << "year: " << movie->GetYear() << "\n";
		std::cout << "score: " << movie->GetScore() << "\n";
		std::cout << "lenght: " << movie->GetMinutes() << "\n";
		std::cout << "passed years: " << (2023 - movie->GetYear()) << "\n";
	}
}
void MovieSeries::Sort() {
	std::sort(movies.begin(), movies.end(), [](Movie* a, Movie* b) {
		return (2023 - a->GetYear()) > (2023 - b->GetYear());
		});
}