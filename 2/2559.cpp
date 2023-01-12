// solved_2800kb_12ms_53794545_407b

#include <bits/stdc++.h>
using namespace std;

long long int pr[100010], n, k, tmp, ans = -2147483640;

int main(){
    scanf("%lld %lld", &n, &k);
    for(long long int i = 1; i <= n; i++){
        scanf("%lld", &tmp);
        pr[i] = pr[i-1] + tmp;
    }

    for(long long int i = 0; i < n+1-k; i++){
        long long int x = pr[k+i] - pr[i];
        ans = max(ans, x);
    }

    printf("%lld", ans);
}