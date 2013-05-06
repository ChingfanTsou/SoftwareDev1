#ifndef _BUBBLE_H_
#define _BUBBLE_H_

#include <vector>

using std::vector;

class Bubble
{
public:
    Bubble() :com(0),chg(0) {};
    ~Bubble() {};

    void operator () (vector<int>& array)
        {
            int k;
            chg=com=0;
            for (int i = 0; i < array.size() - 1; ++i)
                for (int j = array.size() - 1; j > i; --j)
                {
                    ++com;
                    if (array[j] < array[j-1])
                    {
                        ++chg;
                        k = array[j];
                        array[j] = array[j-1];
                        array[j-1] = k;
                    }
                }
        }
    int com;
    int chg;
};

#endif /* _BUBBLE_H_ */
