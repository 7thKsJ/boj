#include <bits/stdc++.h>
using namespace std;

int n, m, x, me, a, b, cnt = 1;
int tree[400040];

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
        tree[t] = min(tree[t*2], tree[t*2+1]);
        t = t/2;
    }
}

int f(int s, int e, int l, int r, int node){
    //printf("(%d %d), ", l, r);
    if(s <= l && r <= e){
        return tree[node];
    }
    else if(r < s || l > e){
        return 1234567890;
    }
    else{
        return min(f(s,e,l,(l+r)/2,node*2), f(s,e,(l+r)/2+1, r, node*2+1));
    }
}

int main (){
    scanf("%d", &n);
    scanf("%d", &m);

    while(cnt < n){
        cnt *= 2;
    }
    for(int i = cnt; i < 2*cnt; i++){
        tree[i] = 1234567890;
    }
    for(int i = 0; i < n; i++){
        scanf("%d", tree+cnt+i);
    }
    
    for(int i = cnt-1; i > 0; i--){
        tree[i] = min(tree[i*2], tree[i*2+1]);
    }
    while(m--){
        scanf("%d %d", &a, &b);
        printf("%d ",f(a,b,1,cnt,1));
    }
}

