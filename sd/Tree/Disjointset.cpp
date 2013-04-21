#include <iostream>
#include <cstdio>

using std::cin;
using std::cout;
using std::endl;

const int MAXN=1000;
int father[1000];

int getFat(int x)
{
    if (father[x]==x)
        return x;
    else
    {
        father[x]=getFat(father[x]);
        return father[x];
    }
}

void join(int x, int y)
{
    if (getFat(x)!=getFat(y))
    {
        father[x]=father[y];
    }
}

int main()
{
    freopen("set.in","r",stdin);

    int n,x,y;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        father[i]=i;
    }
    for (int i = 0; i < n; ++i)
    {
        cin >> x >> y;
        father[x]=y;
    }
    
    while (!cin.eof())
    {
        cin >> x >> y;
        if (getFat(x)==getFat(y))
        {
            cout << "true" << endl;
        }
        else
        {
            cout << "false" << endl;
        }
    }
    return 0;
}
