#include <iostream>
#include "NumberList.h"
using namespace std;


int main() {
	NumberList lista;
	lista.Init();
	lista.Add(3);
	lista.Add(1);
	lista.Add(0);
	lista.Add(7);
	lista.Add(23);
	lista.Print();
	cout << "\n";
	lista.Sort();
	cout << "\n";
	lista.Print();
	cout<< "\n";
	return 0;
}