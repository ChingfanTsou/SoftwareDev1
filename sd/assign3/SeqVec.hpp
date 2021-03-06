#ifndef SEQVEC_H
#define SEQVEC_H

#include <string>
#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

template <class EleType>
class SeqVec
{
public:
    SeqVec();
    SeqVec(int);
    virtual ~SeqVec();
    void insert(const EleType&, int);
    int findByVal(const EleType&) const;
    EleType findByPos(int) const;
    void delByPos(int);
    int prePos(int) const;
    int nextPos(int) const;
    void clear();
    int first() const;
    int last() const;

protected:
    void resize(int);
    bool out(int) const;
    EleType* data;
    int length;
    int lastEle;
};

template <typename EleType>
SeqVec<EleType>::SeqVec()
    :length(16),lastEle(-1)
{
    data = new EleType[16];
}

template <typename EleType>
SeqVec<EleType>::~SeqVec()
{
    delete [] data;
}

template <typename EleType>
void SeqVec<EleType>::resize(int nLen)
{
    EleType* p = new EleType[nLen];
    memcpy(p, data, length*sizeof(EleType));
    delete [] data;
    data = p;
    length = nLen;
}

template <typename EleType>
SeqVec<EleType>::SeqVec(int len)
    :length(len),lastEle(-1)
{
    data = new EleType[len];
}

template <typename EleType>
void SeqVec<EleType>::insert(const EleType& nwEl, int pos)
{
    if (out(pos))
    {
        return;
    }
    
    if (lastEle == length - 1)
    {
        resize(length + 1);
    }
    
    ++lastEle;
    for (int i = lastEle; i > pos; --i)
    {
        data[i] = data[i - 1];
    }
    data[pos] = nwEl;
}

template <typename EleType>
int SeqVec<EleType>::findByVal(const EleType& mEle) const
{
    for (int i = 0; i < length; i++)
    {
        if (data[i] == mEle)
        {
            return i;
        }
    }
    return -1;
}

template <typename EleType>
EleType SeqVec<EleType>::findByPos(int pos) const
{
    if (out(pos))
    {
        return data[0];
    }
    else
    {
        return data[pos];
    }
}

template <typename EleType>
void SeqVec<EleType>::delByPos(int pos)
{
    if (out(pos))
    {
        return;
    }
    else
    {
        --lastEle;
        for(int i = pos; i <= lastEle; i++)
        {
            data[i] = data[i + 1];
        }
    }
}

template <typename EleType>
int SeqVec<EleType>::prePos(int pos) const
{
    return pos - 1;
}

template <typename EleType>
int SeqVec<EleType>::nextPos(int pos) const
{
    return pos + 1;
}

template <typename EleType>
void SeqVec<EleType>::clear()
{
    lastEle = -1;
}

template <typename EleType>
int SeqVec<EleType>::first() const
{
    if (lastEle < 0)
    {
        return lastEle;
    }
    return 0;
}

template <typename EleType>
int SeqVec<EleType>::last() const
{
    return lastEle + 1;
}

template <typename EleType>
bool SeqVec<EleType>::out(int pos) const
{
    if (pos < 0 || pos > lastEle + 1)
    {
        cout << "Position doesn't exist" << endl;
        return true;
    }
    return false;
}

#endif /* SEQVEC_H */
