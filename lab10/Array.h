#pragma once
#include <iostream>
#include <algorithm>


class exceptie1 : public std::exception
{
public:
    virtual const char* what() const throw()
    {
        return "Indexul este inafara domeniului!";
    }
};

class Compare
{
public:
    virtual int CompareElements(void* e1, void* e2) = 0;
};

template <class T>
class compareelements : public Compare
{
public:
    int CompareElements(void* e1, void* e2) override
    {
        if (*(T*)e1 < *(T*)e2)  return -1;
        if (*(T*)e1 > *(T*)e2)  return  1;
        return 0;
    }
};

template<class T>
class ArrayIterator
{
private:
    int  Current;
    T**  List;

public:
    ArrayIterator() : List(nullptr), Current(0) {}
    ArrayIterator(T** list, int current) : List(list), Current(current) {}

    
    ArrayIterator& operator++()
    {
        Current++;
        return *this;
    }

    ArrayIterator& operator--()
    {
        if (Current == 0)
            throw exceptie1();
        Current--;
        return *this;
    }

   
    bool operator==(const ArrayIterator<T>& ref) const { return Current == ref.Current; }
    bool operator!=(const ArrayIterator<T>& ref) const { return Current != ref.Current; }

    T* GetElement()      { return List[Current]; }
    T* operator*()       { return GetElement(); }
};


template<class T>
class Array
{
private:
    T**  List;
    int  Capacity;
    int  Size;

    void list_expand(int size)
    {
        int newCapacity = 1;
        while (newCapacity < size)
            newCapacity *= 2;

        T** temp = new T*[newCapacity];
        for (int i = 0; i < Size; i++)
            temp[i] = List[i];
        
        for (int i = Size; i < newCapacity; i++)
            temp[i] = nullptr;

        delete[] List;
        List     = temp;
        Capacity = newCapacity;
    }

public:
   
    Array() : List(nullptr), Capacity(0), Size(0) {}

   
    Array(int capacity) : Size(0), Capacity(capacity)
    {
        List = new T*[capacity];
        for (int i = 0; i < capacity; i++)
            List[i] = nullptr;
    }

   
    Array(const Array<T>& otherArray)
        : List(nullptr), Capacity(0), Size(0)
    {
        list_expand(otherArray.Size > 0 ? otherArray.Size : 1);
        for (int i = 0; i < otherArray.Size; i++)
            List[i] = new T(*otherArray.List[i]);
        Size = otherArray.Size;
    }

  
    ~Array()
    {
        for (int i = 0; i < Size; i++)
            delete List[i];
        delete[] List;
    }
]
    T& operator[](int index)
    {
        try
        {
            if (index < 0 || index >= Size)
                throw exceptie1();
        }
        catch (exceptie1& e)
        {
            std::cout << "Exceptie: " << e.what() << std::endl;
        }
        return *(List[index]);
    }

    
    const Array<T>& operator+=(const T& newElem)
    {
        if (Size + 1 > Capacity)
            list_expand(Size + 1);
        List[Size++] = new T(newElem);
        return *this;
    }

    
    const Array<T>& Insert(int index, const T& newElem)
    {
        try
        {
            if (index < 0 || index >= Size)
                throw exceptie1();
            if (Size + 1 > Capacity)
                list_expand(Size + 1);
            for (int i = Size - 1; i >= index; i--)
                List[i + 1] = List[i];
            List[index] = new T(newElem);
            Size++;
        }
        catch (exceptie1& e)
        {
            std::cout << "Exceptie: " << e.what() << std::endl;
        }
        return *this;
    }

   
    const Array<T>& Insert(int index, const Array<T>& otherArray)
    {
        try
        {
            if (index < 0 || index >= Size)
                throw exceptie1();
            if (Size + otherArray.Size > Capacity)
                list_expand(Size + otherArray.Size);
            for (int i = Size - 1; i >= index; i--)
                List[i + otherArray.Size] = List[i];
            for (int i = 0; i < otherArray.Size; i++)
                List[index + i] = new T(*otherArray.List[i]);
            Size += otherArray.Size;
        }
        catch (exceptie1& e)
        {
            std::cout << "Exceptie: " << e.what() << std::endl;
        }
        return *this;
    }

    const Array<T>& Delete(int index)
    {
        try
        {
            if (index < 0 || index >= Size)
                throw exceptie1();
            delete List[index];
            for (int i = index; i < Size - 1; i++)
                List[i] = List[i + 1];
            List[--Size] = nullptr;
        }
        catch (exceptie1& e)
        {
            std::cout << "Exceptie: " << e.what() << std::endl;
        }
        return *this;
    }

   
    bool operator==(const Array<T>& otherArray) const
    {
        if (Size != otherArray.Size)
            return false;
        for (int i = 0; i < Size; i++)
            if (*List[i] != *otherArray.List[i])
                return false;
        return true;
    }

    
    void Sort()
    {
        for (int i = 0; i < Size - 1; i++)
            for (int j = i + 1; j < Size; j++)
                if (*List[i] > *List[j])
                    std::swap(List[i], List[j]);
    }

    void Sort(int(*compare)(const T&, const T&))
    {
        for (int i = 0; i < Size - 1; i++)
            for (int j = i + 1; j < Size; j++)
                if (compare(*List[i], *List[j]) > 0)
                    std::swap(List[i], List[j]);
    }

    void Sort(Compare* comparator)
    {
        for (int i = 0; i < Size - 1; i++)
            for (int j = i + 1; j < Size; j++)
                if (comparator->CompareElements(List[i], List[j]) > 0)
                    std::swap(List[i], List[j]);
    }

    int BinarySearch(const T& elem)
    {
        int i = 0, j = Size - 1;
        while (i <= j)
        {
            int m = (i + j) / 2;
            if (*List[m] == elem)  return m;
            if (*List[m] < elem)   i = m + 1;
            else                   j = m - 1;
        }
        return -1;
    }

    int BinarySearch(const T& elem, int(*compare)(const T&, const T&))
    {
        int i = 0, j = Size - 1;
        while (i <= j)
        {
            int m = (i + j) / 2;
            int c = compare(*List[m], elem);
            if (c == 0)  return m;
            if (c < 0)   i = m + 1;
            else         j = m - 1;
        }
        return -1;
    }

    int BinarySearch(const T& elem, Compare* comparator)
    {
        int i = 0, j = Size - 1;
        while (i <= j)
        {
            int m = (i + j) / 2;
            int c = comparator->CompareElements(List[m], const_cast<T*>(&elem));
            if (c == 0)  return m;
            if (c < 0)   i = m + 1;
            else         j = m - 1;
        }
        return -1;
    }

    // Linear search
    int Find(const T& elem)
    {
        for (int i = 0; i < Size; i++)
            if (*List[i] == elem) return i;
        return -1;
    }

    int Find(const T& elem, int(*compare)(const T&, const T&))
    {
        for (int i = 0; i < Size; i++)
            if (compare(*List[i], elem) == 0) return i;
        return -1;
    }

    int Find(const T& elem, Compare* comparator)
    {
        for (int i = 0; i < Size; i++)
            if (comparator->CompareElements(List[i], const_cast<T*>(&elem)) == 0)
                return i;
        return -1;
    }

    // Accessors
    int GetSize()     const { return Size; }
    int GetCapacity() const { return Capacity; }

    // Iterator support
    ArrayIterator<T> begin() { return ArrayIterator<T>(List, 0);    }
    ArrayIterator<T> end()   { return ArrayIterator<T>(List, Size); }
};