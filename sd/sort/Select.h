#ifndef _SELECT_H_
#define _SELECT_H_

class Select
{
public:
    Select() {};
    virtual ~Select() {};
    void operator()(vector<int>& array)
        {
            for (int i = 0; i < array.size(); ++i)
            {
                int m = 0x7fffffff;
                int k = -1;
                for (int j = i; j < array.size(); ++j)
                {
                    if (m > array[j])
                    {
                        m = array[j];
                        k = j;
                    }
                }
                if (k != -1)
                {
                    array[k] = array[i];
                    array[i] = m;
                }
            }
        }
};

#endif /* _SELECT_H_ */
