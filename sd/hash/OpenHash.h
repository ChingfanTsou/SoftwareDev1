#ifndef OPENHASH_H
#define OPENHASH_H

#include "HashExp.h"

template<typename Hf>
class OpenHash
{
public:
    OpenHash(int cap)
        :maxvol(cap)
    {
        hash_table = new Node*[cap];
        for (int i = 0; i < cap; ++i)
        {
            hash_table[i].next = 0;
        }
    }
    ~OpenHash()
    {
        Node* p;
        for (int i = 0; i < cap; ++i)
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
        pos = search(newkey);

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
        for (int i = 0; i < maxvol; ++i)
        {
            pos = hash(key, i);
            if (hash_table[pos] == 0)
                return pos;
            
            for (Node* p = hash_table[pos]; p; p = p->next)
            {
                if (p->key == key)
                    return pos;
            }
        }
        return -1;
    }
private:
    Hf hash;
    int maxvol;
    struct Node
    {
        int key;
        Node* next;
    } **hash_table;
}

#endif /* OPENHASH_H */
