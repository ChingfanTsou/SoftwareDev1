#ifndef OVERFLOWHASH_H
#define OVERFLOWHASH_H

class OverFlowHash
{
    OverFlowHash(int cap)
        :maxvol(cap),tot(-1)
    {
        hash_table = new int[cap];
        of_table = new int[cap];
        for (int i = 0; i < cap; ++i)
        {
            hash_table = -1;
        }
    }

    ~OverFlowHash()
    {
        delete [] hash_table;
        delete [] of_table;
    }
    
    void insert(int newkey)
    {
        pos = search(newkey);
        
        
        if (pos == -1)
        {
            if (tot = maxvol - 1)
                throw TableFull();

            of_table[++tot] = newkey;
        }
        
        if (hash_table[pos] == newkey)
            throw DuplicateExp();

        hash_table[pos] = newkey;
    }
    
    int* search(int key)
    {
        int pos;
        for (int i = 0; i < maxvol; ++i)
        {
            pos = hash(key, i);
            if (hash_table[pos] == -1 || hash_table[pos] == key)
                return hash_table + pos;
        }
        return -1;
    }
private:
    Hf hash;
    int tot;
    int maxvol;
    int *hash_table;
    int *of_table;
}

#endif /* OVERFLOWHASH_H */
