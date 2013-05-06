#ifndef _SELECT_H_
#define _SELECT_H_

class Select
{
public:
    Select() :chg(0), com(0){};
    virtual ~Select() {};
    void operator()(vector<int>& array)
        {
            com=chg=0;
            for (int i = 0; i < array.size(); ++i)
            {
                int m = 0x7fffffff;
                int k = -1;
                for (int j = i; j < array.size(); ++j)
                {
                    ++com;
                    if (m > array[j])
                    {
                        m = array[j];
                        k = j;
                    }
                }
                if (k != -1)
                {
                    ++chg;
                    array[k] = array[i];
                    array[i] = m;
                }
            }
        }
    
    int chg;
    int com;
};

#endif /* _SELECT_H_ */
