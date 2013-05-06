#ifndef _SHELL_H_
#define _SHELL_H_

class Shell
{
public:
    Shell() :chg(0), com(0){};
    virtual ~Shell() {};
    void operator()(vector<int>& array)
        {
            chg=com=0;
            for (int gap = array.size() / 2; gap > 0; gap /= 2)
                for (int i = gap; i < array.size(); ++i)
                {
                    int key = array[i];
                    int j = 0;
                    for( j = i - gap; j >= 0 && array[j] > key; j -= gap)
                    {
                        ++com;
                        ++chg;
                        array[j+gap] = array[j];
                    }  
                    array[j+gap] = key;
                    ++chg;
                }
        }
    int chg;
    int com;

};

#endif /* _SHELL_H_ */
