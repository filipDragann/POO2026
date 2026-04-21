#include "Math.h"
#include <vector>
#include <iostream>
#include <cstdarg>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int Math::Add(int v1, int v2) {
	return v1 + v2;
}
int Math::Add(int v1, int v2, int v3) {
	return v1 + v2 + v3;
}
int Math::Add(double v1, double v2) {
	return v1 + v2;
}
int Math::Add(double v1, double v2, double v3) {
	return v1 + v2 + v3;
}
int Math::Mul(int v1, int v2) {
	return v1 * v2;
}
int Math::Mul(int v1, int v2, int v3) {
	return v1 * v2 * v3;
}
int Math::Mul(double v1, double v2) {
	return v1 * v2;
}
int Math::Mul(double v1, double v2, double v3) {
	return v1 * v2 * v3;
}
int Math::Add(int count, ...) {
	va_list args;
	va_start(args, count);
	int sum = 0;
	for (int i = 0; i < count; ++i) {
		sum += va_arg(args, int);
	}
	va_end(args);
	return sum;
}
char* Math::Add(const char* v1, const char* v2) {
    if (!v1 || !v2)
        return nullptr;

    size_t len = strlen(v1) + strlen(v2) + 1;
    char* final = new char[len];

    snprintf(final, len, "%s%s", v1, v2);

    return final;
}