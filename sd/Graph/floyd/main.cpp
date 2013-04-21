#include <iostream>
#include <fstream>

using namespace std;

const int MAXN=10000;

int n,m;
int fa[MAXN];
int dis[MAXN];
int graph[MAXN][MAXN];

void input()
{
    ifstream infile("data.in",ios::in);
    infile >> n >> m;

    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            if (i!=j)
                graph[i][j]=MAXN;


    int a,b,c;
    for (int i=1; i<=m; i++)
    {
        infile >> a >> b >> c;
        graph[a][b]=graph[b][a]=c;
    }
}

void floyd()
{
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (graph[i][k]+graph[k][j] < graph[i][j])
                    graph[i][j]=graph[i][k]+graph[k][j];
    }
}

void output()
{
    ofstream outfile("data.out",ios::out);

    for (int i=1;i<=n;i++)
    {
        for (int j = i+1;j<=n;j++)
            outfile<<i<<" "<<j<<" "<<graph[i][j]<< endl;
    }
}

int main()
{
    input();
    floyd();
    output();
    return 0;
}
