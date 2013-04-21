#ifndef CLOSEHASH_H
#define CLOSEHASH_H

#include "HashExp.h"

template<typename Hf>
class CloseHash
{
public:
    CloseHash(int cap)
        :maxvol(cap)
    {
        hash_table = new int[cap];
        for (int i = 0; i < cap; ++i)
        {
            hash_table = -1;
        }
    }

    ~CloseHash()
    {
        delete [] hash_table;
    }
    
    void insert(int newkey)
    {
        pos = search(newkey);
        
        if (pos == -1)
            throw TableFull();
        if (hash_table[pos] == newkey)
            throw DuplicateExp();

        hash_table[pos] = newkey;
    }
    
    int search(int key)
    {
        int pos;
        for (int i = 0; i < maxvol; ++i)
        {
            pos = hash(key, i);
            if (hash_table[pos] == key || hash_table[pos] == -1)
                return pos;
        }
        return -1;
    }

private:
    Hf hash;
    int maxvol;
    int* hash_table;
}

#endif /* CLOSEHASH_H */
