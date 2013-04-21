#include <iostream>
#include <fstream>
#include "QueueList.hpp"

using namespace std;

const int MAXN=10000;

int n,m;
int fa[MAXN];
int dis[MAXN];
int ind[MAXN];
int oud[MAXN];
int ve[MAXN],vl[MAXN];
int tot;

struct Node
{
    int v;    
    int e;
    Node* next;
}*posgraph[MAXN],*vergraph[MAXN];

void newedge(Node** graph, int a, int b, int c)
{
    Node* p = new Node();
    p -> v = b;
    p -> e = c;
    p -> next = graph[a];
    graph[a] = p;
}

void input()
{
    ifstream infile("data.in",ios::in);
    infile >> n >> m;

    int a,b,c;
    for (int i=1; i<=m; i++)
    {
        infile >> a >> b >> c;
        newedge(posgraph, a,b,c);
        ++ind[b];
        newedge(vergraph, b,a,c);
        ++oud[a];
    }
}

void outputv(string x, int a, int b)
{
    cout << "The " << x << " beginning time of event " << a << " is " << b << endl;
}

void outpute(string x, int a, int b, int c)
{
    cout << "The " << x << " beginning time of activity " << a << " -> " << b << " is " << c << endl;
}

void topsortel()
{
    QueueList<int> queue;
    queue.enQueue(1);
    for (int i = 1; i <= n; ++i)
    {
        ve[i] = -1;
    }
    ve[1]=0;
    outputv("earliest", 1, 0);
    
    int x;
    while (!queue.isEmpty())
    {
        x = queue.deQueue();
        for (Node* p=posgraph[x]; p; p = p->next)
        {
            --ind[p->v];
            if (ve[x]+p->e>ve[p->v])
                ve[p->v]=ve[x]+p->e;
            if (!ind[p->v])
            {
                queue.enQueue(p->v);
                outputv("earliest", p->v, ve[p->v]);
                for (Node* q=posgraph[p->v]; q; q=q->next)
                {
                    outpute("earliest", p->v, q->v,ve[p->v]);
                }
            }
        }
    }
}

void topsortla()
{
    QueueList<int> queue;
    queue.enQueue(n);
    for (int i = 1; i <= n; ++i)
    {
        vl[i] = 0x7f7f7f7f;
    }
    vl[n]=ve[n];
    outputv("latest", n, vl[n]);
    
    int x;
    while (!queue.isEmpty())
    {
        x = queue.deQueue();
        for (Node* p=vergraph[x]; p; p = p->next)
        {
            --oud[p->v];
            if (vl[x]-p->e<vl[p->v])
                vl[p->v]=vl[x]-p->e;
            if (!oud[p->v])
            {
                queue.enQueue(p->v);
                outputv("latest", p->v, vl[p->v]);
                for (Node* q=vergraph[p->v]; q; q=q->next)
                {
                    outpute("latest", q->v, p->v, vl[p->v]-q->e);
                }
            }
        }
    }
}

int main()
{
    input();
    topsortel();
    topsortla();
    return 0;
}
