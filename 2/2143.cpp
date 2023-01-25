#include <bits/stdc++.h>
using namespace std;

vector<long long int> v,w;
long long int a[1010], b[1010];
long long int t,m,n,ans;

int main(){
    scanf("%lld", &t);
    scanf("%lld", &n);
    for(long long int i = 0; i < n; i++){
        scanf("%lld", a+i);
    }
    scanf("%lld", &m);
    for(long long int i = 0; i < m; i++){
        scanf("%lld", b+i);
    }

    for(long long int i = 0; i < n; i++){
        long long int tmp = a[i];
        w.push_back(tmp);
        for(long long int j = i+1; j < n; j++){
            tmp += a[j];
            w.push_back(tmp);
        }
    }

    for(long long int i = 0; i < m; i++){
        long long int tmp = b[i];
        v.push_back(tmp);
        for(long long int j = i+1; j < m; j++){
            tmp += b[j];
            v.push_back(tmp);
        }
    }

    sort(v.begin(), v.end());

    for(long long int i = 0; i < w.size(); i++){
        long long int rem = t - w[i];
        long long int ub_ind = upper_bound(v.begin(), v.end(), rem) - v.begin();
        long long int lo_ind = lower_bound(v.begin(), v.end(), rem) - v.begin();
        ans += ub_ind - lo_ind;
    }
    printf("%lld", ans);
}