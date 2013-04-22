#ifndef HASHFUN_H
#define HASHFUN_H

#include <cstdlib>
class KMod
{
public:
    KMod(int cap) :m(cap) {}

    int operator() (int k, int i)
    {
        return (hash(k)+Increment(i))%m;
    }

private:
    int hash(int k)
    {
        return k % m;
    }
    int Increment(int i)
    {
        return i;
    }
    int m;
};

class Rand
{
public:
    Rand(int cap)
        :m(cap)
    {
    }

    int operator() (int k, int i)
    {
        return (hash(k)+Increment(i));
    }

private:
    int hash(int k)
    {
        srand(k);
        return rand() % m;
    }
    int Increment(int i)
    {
        return i;
    }    
    int m;
};

#endif /* HASHFUN_H */
