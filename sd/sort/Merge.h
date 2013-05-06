#ifndef _MERGE_H_
#define _MERGE_H_

#include <vector>
class Merge
{
public:
    Merge() : tmp(1000000), chg(0), com(0){};
    virtual ~Merge() {};
    void operator()(vector<int>& array)
        {
            chg=com=0;
            mergesort(array, 0, array.size()-1);
        }
    
    int chg;
    int com;

private:
    void mergesort(vector<int>& array, int l, int r)
        {
            if (l == r)
            {
                return;
            }
            mergesort(array, l, (l+r)>>1);
            mergesort(array, ((l+r)>>1)+1, r);
            mergearray(array, l, (l+r)>>1, r);
        }

    void mergearray(vector<int>& array, int l, int m, int r)
        {
            int i = l;
            int j = m+1;
            int k=0;
            while (i<=m && j<=r)
            {
                ++com;
                if (array[i]<=array[j])
                {
                    tmp[++k] = array[i++];
                }
                else tmp[++k] = array[j++];
            }

            while (i<=m) tmp[++k]=array[i++];
            while (j<=m) tmp[++k]=array[j++];
            
            chg += k;
            for (int i = 0; i < k; ++i)
            {
                array[l+i]=tmp[i+1];
            }
        }
    vector<int> tmp;
};

#endif /* _MERGE_H_ */
