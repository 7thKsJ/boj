#include <bits/stdc++.h>
using namespace std;

int n,k,s[10010], d[10010], ans;

int main(){
    scanf("%d %d", &n, &k);

    for(int i = 0; i < n; i++){
        scanf("%d", s+i);
    }

    if(k >= n){
        printf("0");
        return 0;
    }

    sort(s,s+n);
    for(int i = 0; i < n-1; i++){
        d[i] = s[i+1]- s[i];
    }

    sort(d, d+n-1);
    for(int i = 0; i < n-k; i++){
        ans += d[i];
    }

    printf("%d", ans);
}