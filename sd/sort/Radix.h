#ifndef _RADIX_H_
#define _RADIX_H_

#include <vector>
#include <queue>

class Radix
{
public:
    Radix() :bucket(1000000){};
    virtual ~Radix() {};
    void operator()(vector<int>& array)
        {
            for (int pow=10; true; pow*=10)
            {
                for (int i=0; i < array.size(); i++)
                {
                    bucket[(array[i]%pow)/(pow / 10)].push(array[i]);
                }
                if (bucket[0].size() == array.size())
                {
                    return;
                }
                array.clear();
                int k = 0;
                for (int i=0; i < 10; i++)
                {
                    while (!bucket[i].empty())
                    {
                        array.push_back(bucket[i].front());
                        bucket[i].pop();
                    }
                }
            }
        }
private:
    vector<queue<int> > bucket;
};

#endif /* _RADIX_H_ */
