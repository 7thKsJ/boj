// solved_1260kb_8ms_52369015_1114b
// Bellman-Ford

#include <stdio.h>
 
const long long INF = 1e18;
 
long long d[510];
long long g[6010][3];
 
int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
 
    for (int i=0; i<=n; i++)
        d[i] = INF;
 
    for (int i=0; i<m; i++)
        for (int j=0; j<3; j++)
            scanf("%lld", &g[i][j]);
   
    d[1] = 0;
 
    for (int i=1; i<=n-1; i++)
    {
        for (int j=0; j<m; j++)
        {
            long long u = g[j][0], v = g[j][1], w = g[j][2];
 
            if (d[u] == INF)    continue;
 
            if (d[u] + w < d[v])
                d[v] = d[u] + w;
        }
    }
 
    int hasNegative = 0;
 
    for (int i=0; i<m; i++)
    {
        long long u = g[i][0], v = g[i][1], w = g[i][2];
 
        if (d[u] == INF)    continue;
       
        if (d[u] + w < d[v])
        {
            hasNegative = 1;
            break;
        }
    }
 
    if (hasNegative == 1)
    {
        printf("-1");
    }
    else
    {
        for (int i=2; i<=n; i++)
        {
            if (d[i] == INF)    printf("-1\n");
            else                printf("%lld\n", d[i]);
        }
    }
 
    return 0;
}