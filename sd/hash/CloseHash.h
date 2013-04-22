#ifndef CLOSEHASH_H
#define CLOSEHASH_H

#include "HashExp.h"

template<typename Hf, int mod>
class CloseHash
{
public:
    CloseHash(int cap)
        :maxvol(cap), hash(mod)
    {
        hash_table = new int[cap];
        for (int i = 0; i < cap; ++i)
        {
            hash_table[i] = -1;
        }
    }

    ~CloseHash()
    {
        delete [] hash_table;
    }
    
    void insert(int newkey)
    {
        int pos = search(newkey);
        
        if (pos == -1)
            throw TableFull();

        if (hash_table[pos] == newkey)
            //throw DuplicateExp();
            return;

        hash_table[pos] = newkey;
    }
    
    int search(int key)
    {
        int pos;
        q_t = 0;
        for (int i = 0; i < maxvol; ++i)
        {
            ++q_t;
            pos = hash(key, i);
            if (hash_table[pos] == key || hash_table[pos] == -1)
                return pos;
        }
        return -1;
    }
    
    int get_q_time()
    {
        return q_t;
    }

private:
    Hf hash;
    int maxvol;
    int q_t;
    int* hash_table;
};

#endif /* CLOSEHASH_H */
