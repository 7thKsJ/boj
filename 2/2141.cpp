// solved_3588kb_52ms_53782457_557b

#include <bits/stdc++.h>
using namespace std;

struct town{
    long long int id, n;
};

bool cmp(town a, town b){
    return a.id == b.id ? a.n < b.n : a.id < b.id;
}

long long int ans, sum, cur;
int na;
town d[100010];

int main (){
    scanf("%lld", &na);
    for(int i = 0; i < na; i++){
        scanf("%lld %lld", &d[i].id, &d[i].n);
        sum += d[i].n;
    }

    sort(d, d+na, cmp);

    for(int i = 0; i < na; i++){
        cur += d[i].n;
        if(cur >= (sum+1)/2){
            printf("%lld", d[i].id);
            return 0;
        }
    }
}