// Segment tree
#include <bits/stdc++.h>
using namespace std;

long long int n, m, x, me, a, b, cnt = 1, c;
long long int tree[4000040];

// void printTree(){
//     for(int i = 1; i < 2*cnt; i++){
//         printf("%d, ", tree[i]);
//     }
//     puts("");
// }

void renewal(long long int s, long long int v, long long int l, long long int r, long long int node){
    if(r < s || l > s)
        return;
    if(l == r){
        tree[node] += v;    
        return;
    }

    renewal(s, v, l, (l+r)/2, node*2);
    renewal(s, v, (l+r)/2+1, r, node*2+1);
    tree[node] = tree[node*2] + tree[node*2+1];
}


long long int f(long long int s, long long int e, long long int l, long long int r, long long int node){
   // printf("(%d %d), ", l, r);
    if(s <= l && r <= e){
        return tree[node];
    }
    else if(r < s || l > e){
        return 0;
    }
    else{
        return f(s,e,l,(l+r)/2,node*2) + f(s,e,(l+r)/2+1, r, node*2+1);
    }
}

int main (){
    scanf("%lld", &n);
    scanf("%lld %lld", &m, &me);

    while(cnt < n){
        cnt *= 2;
    }
    for(int i = cnt; i < 2*cnt; i++){
        tree[i] = 0;
    }
    for(int i = 0; i < n; i++){
        scanf("%lld", tree+cnt+i);
    }
    
    for(int i = cnt-1; i > 0; i--){
        tree[i] = tree[i*2] + tree[i*2+1];
    }
    m += me;
    while(m--){
        scanf("%lld %lld %lld", &x, &a, &b);
        if(x == 1){
            scanf("%lld", &c);
            renewal(a,b,1,cnt,1);

        }
        else        printf("%lld\n",f(a,b,1,cnt,1));
    }
}