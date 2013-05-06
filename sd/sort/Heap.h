#ifndef _HEAP_H_
#define _HEAP_H_

#include <vector>
class Heap
{
public:
    Heap() :com(0), chg(0){};
    virtual ~Heap() {};
    void operator()(vector<int>& array)
        {
            com=chg=0;
            for (int i = (array.size()>>1) - 1; i>=0; --i)
            {
                pushdown(array, i, array.size());
            }
            for (int i = array.size() - 1; i >= 0; --i)
            {
                ++chg;
                int k = array[0];
                array[0] = array[i];
                array[i] = k;
                pushdown(array, 0, i);
            }
        }
    void pushdown(vector<int>& array, int x, int n)
        {
            int j = 2*x+1;
            int k;
            while (j < n)
            {
                com +=3;
                if (array[x]<array[j] || j+1< n && array[x]<array[j+1])
                {
                    ++chg;
                    if (array[j] < array[j+1])
                        ++j;
                    k = array[x];
                    array[x] = array[j];
                    array[j] = k;
                }
                x = j;
                j = 2*x+1;
            }
        }

    int chg;
    int com;
};

#endif /* _HEAP_H_ */
