#include <stdio.h>
#include <algorithm>
 
using namespace std;
 
int graph[1010][1010];
long long d[1010];
int g[1010], tree[1010];
 
const long long INF = 10e12;
 
int Find(int v)
{
    if (g[v] == v)
        return v;
    else
        return g[v] = Find(g[v]);
}
 
void Union(int l, int r)
{
    int ll = Find(l);
    int rr = Find(r);
 
    if (ll > rr)
        g[ll] = rr;
    else
        g[rr] = ll;
}
 
int extractMin(int n)
{
    int target = 0;
 
    for (int i=1; i<=n; i++)
        if (Find(i) != 0 && d[i] < d[target])
            target = i;
   
    return target;
}
 
int main()
{
    int n, e, answer = 0;
    scanf("%d %d", &n, &e);
 
    for (int i=0; i<=n; i++)
    {
        d[i] = INF;
        g[i] = i;
    }
 
    for (int i=0; i<e; i++)
    {
        int from, to, weight;
        scanf("%d %d %d", &from, &to, &weight);
        graph[from][to] = graph[to][from] = weight;
    }
 
    d[1] = 0;
 
    for (int t=0; t<n; t++)
    {
        int u = extractMin(n);
        Union(0, u);
   
        answer += graph[u][tree[u]];
       
        for (int i=1; i<=n; i++)
        {
            if (graph[u][i] != 0)
            {
                if (Find(u) != Find(i) && d[i] > graph[u][i])
                {
                    d[i] = graph[u][i];
                    tree[i] = u;
                }
            }
        }
    }
 
    printf("%d", answer);
 
    return 0;
}
