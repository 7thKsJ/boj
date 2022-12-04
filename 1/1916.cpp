// solved_5036kb_40ms_47045803_1595b
// Prim

#include <stdio.h>
#include <algorithm>
#define INF 1E9
using namespace std;

int s[1001], d[1001], m[1001][1001],n,a,b;

void update_dist(int k){
    for(int i = 1; i <= n; i++){
        d[i] = min(d[i], d[k]+m[k][i]);
    }
}

int extract_min(){
    int ret = INF+1, retNum = 0;
    for(int i = 1; i <= n; i++){
        if(s[i] == 0){
            if(ret > d[i]){
                retNum = i;
                ret = d[i];
            }
        }
    }
    return retNum;
}

int main (){
    int e, r;
    scanf("%d %d", &n, &e);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i == j)  continue;
            m[i][j] = INF ;
        }
    }
    for(int i = 0; i < e; i++){
        scanf("%d %d %d", &a, &b, &r);
        m[a][b] = min(m[a][b], r);
    }

    for(int i = 1; i <= n; i++){
        d[i] = INF;
    }
    scanf("%d %d", &a, &b);
    d[a] = 0;
    s[a] = 1;
    update_dist(a);

    int left = n-1;
    while(left--){
        int u = extract_min();
        s[u] = 1;
        update_dist(u);
    }
    printf("%d", d[b]);
    
}