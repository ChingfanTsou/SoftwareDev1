#ifndef _INSERT_H_
#define _INSERT_H_

#include <vector>

class Insert
{
public:
    Insert() :chg(0), com(0){};
    virtual ~Insert() {};
    void operator()(vector<int>& array)
        {
            for (int i = 1; i < array.size(); ++i)
            {
                int k = array[i];
                int j = i - 1;
                for (; j >= 0 && k <= array[j]; --j)
                {
                    array[j+1] = array[j];
                    ++chg;
                    ++com;
                }
                array[j+1]=k;
                ++chg;
            }
        }
    int chg;
    int com;
};

#endif /* _INSERT_H_ */
