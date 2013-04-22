#ifndef OPENHASH_H
#define OPENHASH_H

#include "HashExp.h"

template<typename Hf, int mod>
class OpenHash
{
public:
    OpenHash(int cap)
        :maxvol(cap),hash(mod)
    {
        hash_table = new Node*[cap];
        for (int i = 0; i < cap; ++i)
        {
            hash_table[i] = 0;
        }
    }
    ~OpenHash()
    {
        Node* p;
        for (int i = 0; i < maxvol; ++i)
        {
            p = hash_table[i];
            while (p)
            {
                hash_table[i] = hash_table[i]->next;
                delete p;
                p = hash_table[i];
            }
        }
    }

    void insert(int newkey)
    {
        int pos = search(newkey);

        Node* p;
        for (p = hash_table[pos]; p; p = p -> next)
        {
            if (p->key == newkey)
                throw DuplicateExp();
        }

        p = new Node;
        p->key = newkey;
        p->next = hash_table[pos];
        hash_table[pos]=p;
    }
    
    int search(int key)
    {
        int pos;
        q_time = 1;
        pos = hash(key, 0);
        if (hash_table[pos] == 0)
            return pos;
            
        for (Node* p = hash_table[pos]; p; p = p->next)
        {
            ++q_time;
            if (p->key == key)
                return pos;
        }
        
        return pos;
    }
    
    int get_q_time()
    {
        return q_time;
    }
private:
    Hf hash;
    int maxvol;
    int q_time;
    struct Node
    {
        int key;
        Node* next;
    } **hash_table;
};

#endif /* OPENHASH_H */
