#ifndef _QUICK_H_
#define _QUICK_H_

#include <vector>
#include <cstdlib>

using std::vector;

class Quick
{
public:
    Quick() :chg(0), com(0){};
    virtual ~Quick() {};
    void operator()(vector<int>& array)
        {
            chg=com=0;
            quick_sort(array, 0, array.size()-1);
        }

    int chg;
    int com;
    
private:
    void quick_sort(vector<int>& array, int l, int r)
        {
            if (l >= r) return;

            int x = array[(l+r)>>1];
            int i = l - 1;
            int k;
            for (int j = l; j <= r-1; ++j)
            {
                ++com;
                if (array[j] <= x)
                {
                    ++i;
                    k = array[j];
                    array[j] = array[i];
                    array[i] = k;
                    ++chg;
                }
            }
           
            k = array[r];
            array[r] = array[i+1];
            array[i+1] = k;
            ++chg;

            quick_sort(array, l, i);
            quick_sort(array, i+1, r);
        }
};

#endif /* _QUICK_H_ */
