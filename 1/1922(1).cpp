#include <stdio.h>
#include <algorithm>
 
using namespace std;
 
int graph[1010][1010];
long long d[1010];
int visited[1010], tree[1010];
 
const long long INF = 10e12;
 
int deleteMin(int n)
{
    int target = 0;
 
    for (int i=1; i<=n; i++)
        if (visited[i] == 0 && d[i] < d[target])
            target = i;
   
    visited[target] = 1;
    return target;
}
 
int main()
{
    int n, e, answer = 0;
    scanf("%d %d", &n, &e);
 
    for (int i=0; i<=n; i++)
    {
        d[i] = INF;
        visited[i] = 0;
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
        int u = deleteMin(n);
   
        answer += graph[u][tree[u]];
 
        for (int i=1; i<=n; i++)
        {
            if (graph[u][i] != 0)
            {
                if (visited[i] == 0 && d[i] > graph[u][i])
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
