#include <iostream>
#include <fstream>
#include <cstring>

#include "QueueList.hpp"

using namespace std;

const int MAXN=10000;

int n,m;
int tot;
bool f[MAXN][MAXN];
bool vis[MAXN];

struct Node
{
    int v;
    Node* next;
}*graph[MAXN];

void newedge(int a, int b)
{
    Node* p = new Node();
    p -> v = b;
    p -> next = graph[a];
    graph[a] = p;
}

void input()
{
    ifstream infile("data.in",ios::in);
    infile >> n >> m;

    int a,b;
    for (int i=1; i<=m; i++)
    {
        infile >> a >> b;
        newedge(a, b);
        newedge(b, a);
        f[a][b]=true;
        f[b][a]=true;
    }
}

void bfs1()
{
    QueueList<int> queue;
    queue.enQueue(1);
    cout << 1 << endl;
    vis[1]=true;
    int x;
    while (!queue.isEmpty())
    {
        x = queue.deQueue();
        for (int i=1;i<=n;i++)
        {
            if (!vis[i] && f[x][i])
            {
                cout << i << endl;
                vis[i]=true;
                queue.enQueue(i);
            }
        }
    }
}

void dfs1(int x)
{
    if (!vis[x])
    {
        cout << x << endl;
        vis[x]=true;
    }
    else
    {
        return;
    }
    
    for (int i=1;i<=n;i++)
    {
        if (f[x][i])
        {
            dfs1(i);
        }
    }
}

void dfs2(int x)
{
    if (!vis[x])
    {
        cout << x << endl;
        vis[x]=true;
    }
    else
    {
        return;
    }
    
    for (Node* p = graph[x];p;p=p->next)
    {
        dfs2(p->v);
    }
}

int main()
{
    input();
    memset(vis,0,sizeof(vis));
    bfs1();
    cout << endl;
    memset(vis,0,sizeof(vis));
    dfs1(1);
    cout << endl;
    memset(vis,0,sizeof(vis));
    dfs2(1);
    return 0;
}
