#include <iostream>
using namespace std;

class Sort
{
    // add data members
public:

    Sort(int elements_count, int minimum, int maximum);
    Sort(std::initializer_list<int> list);
    void InsertSort(bool ascendent=false);
    void QuickSort(bool ascendent=false);
    void BubbleSort(bool ascendent=false);
    void Print();
    int  GetElementsCount();
    int  GetElementFromIndex(int index);
};
