#include "NumberList.h"
#include <iostream>
using namespace std;
void NumberList::Init() {
	count = 0;
}

bool NumberList::Add(int x) {
	if (count > 10)
		return false;
	numbers[count++] = x;
	return true;
}

void NumberList::Sort() {
	bool ok;
	for (int i = 0; i < count - 1; i++) {
		ok = false;
		for (int j = 0; j < count - i - 1; j++) {
			if (numbers[j] > numbers[j + 1]) {
				int aux = numbers[j];
				numbers[j] = numbers[j+1];
				numbers[j+1] = aux;
				ok = true;
			}
		}
		if (!ok) {
			break;
		}
	}
}

void NumberList::Print() {
	for (int i = 0; i < count; i++)
		std::cout << numbers[i] << " ";
}