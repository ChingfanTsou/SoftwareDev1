#include <iostream>
#include <fstream>

using namespace std;

const int MAXN=10000;

int n,m;
int fa[MAXN];
int dis[MAXN];

struct Node
{
    int v;
    int e;
    Node* next;
}*graph[MAXN];

void newedge(int a, int b, int c)
{
    Node* p = new Node();
    p -> v = b;
    p -> e = c;
    p -> next = graph[a];
    graph[a] = p;
}

int find(int a, int b)
{
    for (Node* p = graph[a]; p; p = p->next)
    {
        if (p->v == b)
            return p->e;
    }
    return 0x7fffffff;
}

void input()
{
    ifstream infile("data.in",ios::in);
    infile >> n >> m;

    int a,b,c;
    for (int i=1; i<=m; i++)
    {
        infile >> a >> b >> c;
        newedge(a,b,c);
        newedge(b,a,c);
    }
}

void prim()
{
    bool in[MAXN];
    memset(in, 0, n+1);

    in[1]=true;
    fa[1]=1;
    dis[1]=0;

    for (int i = 2; i <= n; i++)
    {
        fa[i]=1;
        dis[i]=find(i,1);
        //cout << i << " " << dis[i] << endl;
    }

    int mine;
    int x;
    for (int i = 1; i < n; i++)
    {
        mine = 0x7fffffff;
        for (int j = 1; j<=n; j++)
            if (!in[j])
            {
                if (dis[j] < mine)
                {
                    mine = dis[j];
                    x = j;
                }
            }

        in[x] = true;

        for (int j=1; j<=n; j++)
            if (!in[j])
            {
                mine = find(j,x);
                if (mine < 0x7fffffff)
                    mine += dis[x];
                if (mine < dis[j])
                    {
                        dis[j] = mine;
                        fa[j] = x;
                    }
            }
    }
}

void output()
{
    ofstream outfile("data.out",ios::out);

    for (int i=2;i<=n;i++)
    {
        outfile << i << " " << dis[i] <<endl;
    }
}

int main()
{
    input();
    prim();
    output();
    return 0;
}
