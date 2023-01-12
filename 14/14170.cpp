#include <bits/stdc++.h>
using namespace std;

int n, d[101000], k, a, b;

int lower_bound(int k){
    int l = 1;
    int r = n;
    while(l <= r){
        int m = (l+r)/2;
        if(d[m] >= k)    r = m-1;
        else             l = m+1;
    }
    return r+1;
}

int upper_bound(int k){
    int l = 1;
    int r = n;
    while(l <= r){
        int m = (l+r)/2;
        if(d[m] > k)    r = m-1;
        else            l = m+1;
    }
    return r+1;
}

int main(){
    scanf("%d", &n);
    scanf("%d", &k);

    for(int i = 0; i < n; i++){
        scanf("%d", &d[i]);
    }

    sort(d, d+n);

    while(k--){
        scanf("%d %d", &a, &b);
        printf("%d\n", upper_bound(b)-lower_bound(a));
    }
}