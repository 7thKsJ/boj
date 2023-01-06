// solved_9832kb_244ms_53617034_637b

#include <bits/stdc++.h>
using namespace std;

long long int n, m;
long long int k[1000001];

long long int f(int x){
    long long int ret = 0;
    for(int i = 1; i <= n; i++){
        if(x <= k[i])
            ret += k[i]-x;
    }
    return ret;
}

long long int param_search(long long int x){
    int l = k[0];
    int r = k[n];
    while(l <= r){
        int m = (l+r)/2;
        if(f(m) < x)    r = m-1;
        else            l = m+1;
    }
    return r;
}

int main (){
    scanf("%lld %lld", &n, &m);
    for(int i = 1; i <= n; i++){
        scanf("%lld", k+i);
    }
    sort(k+1, k+1+n);
    printf("%lld",param_search(m));
}