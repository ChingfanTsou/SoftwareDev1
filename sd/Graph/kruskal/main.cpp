#include <iostream>
#include <fstream>

using namespace std;

const int MAXN=10000;

int n,m;
int fa[MAXN];
int tot=0;

struct Edge
{
    int a;
    int b;
    int c;
}graph[MAXN];

bool cmp(Edge x, Edge y)
{
    return x.c < y.c;
}

void input()
{
    ifstream infile("data.in",ios::in);
    infile >> n >> m;

    for (int i=1; i<=n; i++)
    {
        fa[i]=i;
    }

    int a,b,c;
    for (int i=1; i<=m; i++)
    {
        infile >> a >> b >> c;
        graph[i].a=a;
        graph[i].b=b;
        graph[i].c=c;
    }
    sort(graph+1, graph+m+1, cmp);
}

int getf(int x)
{
    if (x==fa[x])
        return x;

    fa[x]=getf(fa[x]);
    return fa[x];
}

void kruskal()
{
    ofstream outfile("data.out",ios::out);
    for (int i=1; i<=m; i++)
    {
        if (getf(graph[i].a)!=getf(graph[i].b))
        {
            fa[fa[graph[i].a]]=fa[graph[i].b];
            outfile << graph[i].a << " " << graph[i].b << endl;
            tot += graph[i].c;
        }
    }
    outfile<<tot<<endl;
}

int main()
{
    input();
    kruskal();
    return 0;
}
