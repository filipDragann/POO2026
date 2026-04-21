#include "Sort.h"
#include <iostream>
using namespace std;

Sort::Sort(int elements_count, int minimum, int maximum)
{
	// rand() -> functie ce returneaza o valoare random
	// pentru a putea avea un numar random intr-un anumit interval se poate folosi modulo (%)
	// formula generala este: minimum + (rand() % (maximum - minimum + 1))
	// https://www.geeksforgeeks.org/cpp/rand-and-srand-in-ccpp/
}

Sort(std::initializer_list<int> list)
{
	// list.size() -> returneaza nr de elemente din lista;
	// list.begin() -> returneaza un pointer catre primul element din lista
	// list.begin()[i] -> acceseaza elementul de pe pozitia i
	// https://www.geeksforgeeks.org/cpp/std-initializer_list-in-cpp-11/
}

Sort::Sort(std::string list)
{
	// std::count 
	//	-> functie ce returneaza numarul de aparitii ale unei valori intr-un range
	//	-> primeste 3 parametri: iterator catre primul, catre ultimul element din range si valoarea cautata
	//	ex: count(list.begin(), list.end(), ',')
	// https://www.geeksforgeeks.org/cpp/std-count-cpp-stl/
	//
	// container_type::iterator it -> obiect ce acceseaza elementele unui container.
	// https://www.geeksforgeeks.org/cpp/iterators-c-stl/
	for (std::string::iterator ch = list.begin(); ch < list.end(); ch++)
	{

	}
}