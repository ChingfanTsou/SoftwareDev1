#include <iostream>

using std::cout;
using std::endl;

class BinTreeVec
{
public:
    BinTreeVec(int n)
        :tot(n)
        {
            for (int i = 1; i <= n; ++i)
            {
                t[i].key = i;
                t[i].l = i + i;
                t[i].r = i + i + 1;
            }
        }
    virtual ~BinTreeVec()
        {
        }
    void pretrav(int k)
        {
            if (k > tot)
            {
                return;
            }
            cout << t[k].key << endl;
            pretrav(t[k].l);
            pretrav(t[k].r);
        }
private:
    class Node
    {
    public:
        int key;
        int l,r;
    } t[100];
    int tot;
};

int main()
{
    BinTreeVec T(10);
    T.pretrav(1);
    return 0;
}
