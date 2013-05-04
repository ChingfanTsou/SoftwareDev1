#ifndef _SHELL_H_
#define _SHELL_H_

class Shell
{
public:
    Shell() {};
    virtual ~Shell() {};
    void operator()(vector<int>& array)
        {
            for (int gap = array.size() / 2; gap > 0; gap /= 2)
                for (int i = gap; i < array.size(); ++i)
                {
                    int key = array[i];
                    int j = 0;
                    for( j = i - gap; j >= 0 && array[j] > key; j -= gap)
                    {
                        array[j+gap] = array[j];
                    }  
                    array[j+gap] = key;
                }
        }
};

#endif /* _SHELL_H_ */
