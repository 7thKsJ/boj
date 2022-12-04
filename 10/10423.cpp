//solved_2680kb_44ms_47042391_1145b;
//kruskal

#include <stdio.h>
#include <algorithm>
 
using namespace std;
 
int g[1010];
int graph[100010][2];
pair<int, int> edge[100010];
 
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
 
 
int main()
{
    int m, n, e, answer = 0, a = -1, b;
    scanf("%d %d %d", &n, &e, &m);
 
    for (int i=0; i<=n; i++)
        g[i] = i;

    for (int i=0; i<m; i++){
        scanf("%d", &b);
        if(a == -1) a = b;
        g[b] = a;
    } 

    for (int i=0; i<e; i++)
    {
        scanf("%d %d %d", &graph[i][0], &graph[i][1], &edge[i].first);
        edge[i].second = i;    
    }
 
    sort(edge, edge+e);
 
    int rest = n-m;
 
    for (int i=0; rest != 0; i++)
    {
        int l = graph[edge[i].second][0], r = graph[edge[i].second][1];
        if (Find(l) != Find(r))
        {
            rest--;
            answer += edge[i].first;
            Union(l, r);
        }
    }
 
    printf("%d", answer);
 
    return 0;
}
