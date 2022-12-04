#include <stdio.h>
 
const int INF = 1e9;
int d[1010];
int visited[1010];
int g[1010][1010];
 
int extractMin(int n)
{
    int target = 0;
 
    for (int i=1; i<=n; i++)
        if (visited[i] == 0 && d[target] > d[i])
            target = i;
 
    return target;
}
 
int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
 
    d[0] = INF;
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=n; j++)
            g[i][j] = INF;
 
        d[i] = INF;
    }
 
    for (int i=1; i<=m; i++)
    {
        int from, to, weight;
 
        scanf("%d %d %d", &from, &to, &weight);
 
        if (g[from][to] > weight)
            g[from][to] = weight;
    }
 
    int start, end;
    scanf("%d %d", &start, &end);
 
    d[start] = 0;
 
    for (int i=0; i<n; i++)
    {
        int u = extractMin(n);
        visited[u] = 1;
       
        for (int i=1; i<=n; i++)
            if (g[u][i] != INF && visited[i] == 0 && d[u] + g[u][i] < d[i])
                d[i] = d[u] + g[u][i];
    }
 
    printf("%d", d[end]);
}
