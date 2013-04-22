#ifndef OVERFLOWHASH_H
#define OVERFLOWHASH_H

template <typename Hf, int mod>
class OverFlowHash
{
public:
    OverFlowHash(int cap)
        :maxvol(cap),tot(-1),hash(mod)
    {
        hash_table = new int[cap];
        of_table = new int[cap];
        for (int i = 0; i < cap; ++i)
        {
            hash_table[i] = -1;
        }
    }

    ~OverFlowHash()
    {
        delete [] hash_table;
        delete [] of_table;
    }
    
    void insert(int newkey)
    {
        int* pos = search(newkey);
        
        
        if (pos == of_table+tot+1)
        {
            if (tot == maxvol - 1)
                throw TableFull();

            of_table[++tot] = newkey;
        }
        
        //if (*pos == newkey)
            //throw DuplicateExp();

        *pos = newkey;
    }
    
    int* search(int key)
    {
        int pos;
        q_t = 1;
        pos = hash(key, 0);
        if (hash_table[pos] == -1 || hash_table[pos] == key)
            return hash_table + pos;
        else
        {
            for (int i=0;i<=tot;i++)
            {
                ++q_t;
                if (of_table[pos]==key)
                {
                    return of_table+pos;
                }
            }
        }
        return of_table+tot+1;
    }

    int get_q_time()
    {
        return q_t;
    }
private:
    Hf hash;
    int tot;
    int q_t;
    int maxvol;
    int *hash_table;
    int *of_table;
};

#endif /* OVERFLOWHASH_H */
