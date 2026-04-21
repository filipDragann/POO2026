#pragma once
class Math
{
public:
    static int Add(int v1, int v2);
    static int Add(int v1, int v2, int v3);
    static int Add(double v1, double v2);
    static int Add(double v1, double v2, double v3);
    static int Mul(int v1, int v2);
    static int Mul(int v1, int v2, int v3);
    static int Mul(double v1, double v2);
    static int Mul(double v1, double v2, double v3);
    static int Add(int count, ...); // sums up a list of integers
    static char* Add(const char* v1, const char* v2);
};