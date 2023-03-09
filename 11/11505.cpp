#include <bits/stdc++.h>
#define DEG 1000000007
using namespace std;

int n, m, x, me, a, b, cnt = 1, op;
long long int tree[4000040];

void printTree(){
    for(int i = 1; i < 2*cnt; i++){
        printf("%d, ", tree[i]);
    }
    puts("");
}

void renewal(int t, int k){
    tree[t] = k;
    t = t/2;
    while(t > 0){
        //printf("%d, ",t);
        tree[t] = (tree[t*2] % DEG) * (tree[t*2+1] % DEG) % DEG;
        t = t/2;
    }
}

long long int f(int s, int e, int l, int r, int node){
    if(s <= l && r <= e){
        return tree[node] % DEG;
    }
    else if(r < s || l > e){
        return 1;
    }
    else{
        return (f(s,e,l,(l+r)/2,node*2) % DEG) * (f(s,e,(l+r)/2+1, r, node*2+1) % DEG) % DEG;
    }
}

int main (){
    scanf("%d", &n);
    scanf("%d %d", &m, &me);
    m += me;

    while(cnt < n){
        cnt *= 2;
    }
    for(int i = cnt; i < 2*cnt; i++){
        tree[i] = 1;
    }
    for(int i = 0; i < n; i++){
        scanf("%lld", tree+cnt+i);
    }
    
    for(int i = cnt-1; i > 0; i--){
        tree[i] = (tree[i*2] % DEG) * (tree[i*2+1] % DEG) % DEG;
    }

    while(m--){
        //printTree();

        scanf("%d", &op);
        scanf("%d %d", &a, &b);
        if(op == 2)
            printf("%lld\n",f(a,b,1,cnt,1));
        else
            renewal(cnt + a - 1,b);
    }
}

