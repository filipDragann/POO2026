#include "Math.h"
#include <cstring>
#include <cstdarg>
#include <iostream>
using namespace std;
int main() {
	Math A;
	
	cout << A.Add(1, 2) << '\n';
	cout << A.Add(2.5, 3.5) << '\n';
	cout << A.Mul(3, 123, 23) << '\n';
	cout << A.Mul(4, -2) << '\n';
	cout << A.Add("1", "234") << '\n';
	return 0;

}