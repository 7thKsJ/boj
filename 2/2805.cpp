// solved_17644kb_220ms_53615368_559b

#include <bits/stdc++.h>
using namespace std;

long long int n, m;
long long int k[1000001], su[1000001];

int main (){
    scanf("%lld %lld", &n, &m);
    for(int i = 1; i <= n; i++){
        scanf("%lld", k+i);
    }

    sort(k+1, k+n+1);
    su[0] = k[0] = 0;
    for(int i = 1; i <= n; i++){
        su[i] = su[i-1] + k[i];
    }

    long long int x, y;
    for(int i = n; i >= 0; i--){
        x = su[n] - su[i] - k[i]*(n-i);
        if(x >= m){
            y = (x - m)/(n-i);
            printf("%lld", k[i]+y);
            return 0;
        }
    }
}