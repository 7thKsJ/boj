// solved_2804kb_788ms_623b

#include <bits/stdc++.h>
using namespace std;

struct parti{
    int a, b;
};

parti x[100010];
int n, ans, t;

bool cmp(parti a_, parti b_){
    if(a_.a == b_.a)    return a_.b > b_.b;
    return a_.a < b_.a;
}

int main (){
    scanf("%d", &t);
    while(t--){
        ans = 0;
        scanf("%d", &n);
        for(int i = 0; i < n; i++){
            scanf("%d %d", &x[i].a, &x[i].b);
        }

        sort(x, x+n, cmp);

        int k = n+1;
        for(int i = 0; i < n; i++){
            if(x[i].b < k){
                k = x[i].b;
                ans++;
            }
        }
        printf("%d\n", ans);
    }
}