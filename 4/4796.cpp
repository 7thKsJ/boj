// solved_2020kb_0ms_53924537_306b

#include <bits/stdc++.h>
using namespace std;

long long int l = 1, v = 1, p = 1, cnt;

int main (){
    while(l != 0 || v != 0 || p != 0){
        scanf("%lld %lld %lld", &l, &p, &v);
        cnt++;
        if(l+p+v == 0)  break;
        printf("Case %lld: %lld\n",cnt,(v/p)*l + min(v%p, l));
    }
}