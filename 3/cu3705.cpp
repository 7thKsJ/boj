#include <bits/stdc++.h>
using namespace std;

int x[100010], n;

int f(int l, int r){
    if(l == r)  return x[l];
    int m = (l+r)/2;
    int psl = 0, psr = 0, mal = -100000001, mar = 100000001;
    for(int i = m+1; i <= r; i++){
        psr += x[i];
        mar = max(mar, psr);
    }
    for(int i = m; i >= l; i--){
        psl += x[i];
        mal = max(mal, psl);
    }
    //printf("%d %d %d\n", l, r, max(f(l,m), max(f(m+1, r), mal+mar)));
    return max(f(l,m), max(f(m+1, r), mal+mar));
}

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", x+i);
    }
    printf("%d", f(0,n-1));
}