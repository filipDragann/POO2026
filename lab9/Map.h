#pragma once
#include <stdexcept>

template <class Key, class Val>
class Map
{
private:
    struct pair
    {
        Key key;
        Val value;
        int index;
    };

    int count;      
    int map_size;
    pair* map;

    void map_expand()
    {
        map_size *= 2;
        pair* temp = new pair[map_size];
        for (int i = 0; i <= count; i++)
            temp[i] = map[i];
        delete[] map;
        map = temp;
    }

public:
    Map()
    {
        count    = -1;
        map_size = 2;         
        map      = new pair[map_size];
    }

    ~Map()
    {
        delete[] map;
    }
    pair* begin() { return &map[0]; }
    pair* end()   { return &map[count + 1]; }   

    const pair* begin() const { return &map[0]; }
    const pair* end()   const { return &map[count + 1]; }

    Val& operator[](const Key& keyy)
    {
        for (int i = 0; i <= count; i++)
            if (map[i].key == keyy)
                return map[i].value;

        if (count + 1 >= map_size)
            map_expand();

        ++count;
        map[count].key   = keyy;
        map[count].index = count;
        map[count].value = Val{};  
        return map[count].value;
    }

    void Set(const Key& key_set, const Val& value_set)
    {
        for (int i = 0; i <= count; i++)
            if (map[i].key == key_set)
            {
                map[i].value = value_set;
                return;
            }

        if (count + 1 >= map_size)
            map_expand();

        ++count;
        map[count].key   = key_set;
        map[count].value = value_set;
        map[count].index = count;
    }

    
    bool Get(const Key& key, Val& value) const
    {
        for (int i = 0; i <= count; i++)
            if (map[i].key == key)
            {
                value = map[i].value;   
                return true;
            }
        return false;
    }

    
    int Count() const { return count + 1; }

  
    void Clear()
    {
        delete[] map;
        count    = -1;
        map_size = 2;
        map      = new pair[map_size];
    }

    bool Delete(const Key& key)
    {
        for (int i = 0; i <= count; i++)
            if (map[i].key == key)
            {
                for (int j = i; j < count; j++)
                {
                    map[j]       = map[j + 1];
                    map[j].index = j;   
                }
                count--;
                return true;
            }
        return false;
    }

    bool Includes(const Map<Key, Val>& map_compare) const
    {
        for (const auto& p : map_compare)
        {
            Val found{};
            if (!this->Get(p.key, found))
                return false;
            if (!(found == p.value))
                return false;
        }
        return true;
    }
};