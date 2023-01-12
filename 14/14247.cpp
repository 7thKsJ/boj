// solved_9836kb_24ms_530b

#include <bits/stdc++.h>
using namespace std;

struct tree{
    int h, g;
};

int n, k;
tree d[1000100];

bool cmp(tree a, tree b){
    if(a.g == b.g){
        return a.h < b.h;
    }
    return a.g < b.g;
}

int main (){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &d[i].h);
    }
    for(int i = 0; i < n; i++){
        scanf("%d", &d[i].g);
    }

    sort(d, d+n, cmp);
    long long int ans = 0;

    for(int i = 0; i < n; i++){
        ans += d[i].h + d[i].g*i;
    }

    printf("%lld", ans);
}