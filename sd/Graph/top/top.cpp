#include <iostream>
#include <fstream>
#include "QueueList.hpp"

using namespace std;

const int MAXN=10000;

int n,m;
int fa[MAXN];
int dis[MAXN];
int ind[MAXN];
int tot;

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
    ++ind[b];
}

void input()
{
    ifstream infile("data.in",ios::in);
    infile >> n >> m;

    int a,b;
    for (int i=1; i<=m; i++)
    {
        infile >> a >> b;
        newedge(a,b);
    }
}

void topsort()
{
    QueueList<int> queue;
    queue.enQueue(1);
    cout << 1 << endl;

    while (!queue.isEmpty())
    {
        for (Node* p=graph[queue.deQueue()]; p; p = p->next)
        {
            --ind[p->v];
            if (!ind[p->v])
            {
                queue.enQueue(p->v);
                cout << p->v << endl;
            }
        }
    }
}

int main()
{
    input();
    topsort();
    return 0;
}
