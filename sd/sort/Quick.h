#ifndef _QUICK_H_
#define _QUICK_H_

#include <vector>

using std::vector;

class Quick
{
public:
    Quick() {};
    virtual ~Quick() {};
    void operator()(vector<int>& array)
        {
            quick_sort(array, 0, array.size()-1);
        }

private:
    void quick_sort(vector<int>& array, int l, int r)
        {
            if (l >= r) return;

            int x = (array[l] + array[r]) >> 1;
            int i = l - 1;
            int k;
            for (int j = l; j <= r; ++j)
            {
                if (array[j] <= x)
                {
                    ++i;
                    k = array[j];
                    array[j] = array[i];
                    array[i] = k;
                }
            }
            quick_sort(array, l, i);
            quick_sort(array, i+1, r);
        }
};

#endif /* _QUICK_H_ */
