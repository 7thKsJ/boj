// solved_5412kb_56ms_46667583_699b
// Union-Find

#include <stdio.h>

int g[1000001]; // 문제에서 주어지는 원소 크기에 따라 크기 조정
int Find(int v)
{
    if (g[v] == v)  return v;
    return g[v] = Find(g[v]);
}

void Union(int l, int r)
{
    int ll = Find(l);
    int rr = Find(r);

    if (ll > rr)    g[ll] = rr;
    else            g[rr] = ll;
}

void Same(int a,int b){
    if (Find(a) == Find(b)){    printf("YES\n");    }
    else{   printf("NO\n"); }
}

int main (){
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++){
        g[i] = i;
    }

    for(int i = 0; i < m; i++){
        int flag, a, b;
        scanf("%d %d %d", &flag, &a, &b);
        if(flag){
            Same(a,b);
        }
        else{
            Union(a,b);
        }
    }
}

