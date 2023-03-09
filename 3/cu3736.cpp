// Segment Tree

#include <bits/stdc++.h>
using namespace std;

struct j{
    int a, b;
};

bool cmp(j x, j y){
    if(x.a == y.a){
        return x.b > y.b;
    }
    return x.a < y.a;
}

int n, m, x, me, a, b, cnt = 1;
int tree[400040];
j arr[100010];

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
        tree[t] = max(tree[t*2], tree[t*2+1]);
        t = t/2;
    }
}

int f(int s, int e, int l, int r, int node){
   // printf("(%d %d), ", l, r);
    if(s <= l && r <= e){
        return tree[node];
    }
    else if(r < s || l > e){
        return 0;
    }
    else{
        return max(f(s,e,l,(l+r)/2,node*2), f(s,e,(l+r)/2+1, r, node*2+1));
    }
}

int main (){
    scanf("%d", &n);
    while(cnt < n){
        cnt *= 2;
    }
   
    for(int i = 1; i <= n; i++){
        scanf("%d", &arr[i].a);
        arr[i].b = i;
    }
    sort(arr+1, arr+n+1, cmp);
    
    for(int i = 1; i <= n; i++){
        int val = f(1, arr[i].b-1, 1, cnt, 1)+1;
        renewal(arr[i].b+cnt-1, val);
    }
    printf("%d", tree[1]);
}
