// solved_2648kb_92ms_916b
// Floyd-Warshall

#include <bits/stdc++.h>
#define INF 1E9
using namespace std;

int dt[401][401];

int main (){
    int n, m, k;
    scanf("%d %d", &n, &m);

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            dt[i][j] = INF;
        }
    }

    while(m--){
        int a, b;
        scanf("%d %d", &a, &b);
        dt[a][b] = 1;
    }

    for(int t = 1; t <= n; t++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(j != i)  dt[i][j] = min(dt[i][t] + dt[t][j], dt[i][j]);
            }
        }
    }

    scanf("%d", &k);
    while(k--){
        int f, g;
        scanf("%d %d", &f, &g);
        if(dt[f][g] < INF){
            if(dt[g][f] >= INF) printf("-1\n");
            else printf("0\n");  
        }
        else{
            if(dt[g][f] >= INF) printf("0\n");
            else printf("1\n");  
        }
    }
}