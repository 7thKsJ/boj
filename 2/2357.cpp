#include <bits/stdc++.h>
using namespace std;

int n, m, x, me, a, b, cnt = 1;
int tree1[400040], tree2[400040];

// void printTree(){
//     for(int i = 1; i < 2*cnt; i++){
//         printf("%d, ", tree[i]);
//     }
//     puts("");
// }

void renewal1(int t, int k){
    tree1[t] = k;
    t = t/2;
    while(t > 0){
        //printf("%d, ",t);
        tree1[t] = min(tree1[t*2], tree1[t*2+1]);
        t = t/2;
    }
}

void renewal2(int t, int k){
    tree2[t] = k;
    t = t/2;
    while(t > 0){
        //printf("%d, ",t);
        tree2[t] = max(tree2[t*2], tree2[t*2+1]);
        t = t/2;
    }
}

int f1(int s, int e, int l, int r, int node){
    //printf("(%d %d), ", l, r);
    if(s <= l && r <= e){
        return tree1[node];
    }
    else if(r < s || l > e){
        return 1234567890;
    }
    else{
        return min(f1(s,e,l,(l+r)/2,node*2), f1(s,e,(l+r)/2+1, r, node*2+1));
    }
}

int f2(int s, int e, int l, int r, int node){
    //printf("(%d %d), ", l, r);
    if(s <= l && r <= e){
        return tree2[node];
    }
    else if(r < s || l > e){
        return -1;
    }
    else{
        return max(f2(s,e,l,(l+r)/2,node*2), f2(s,e,(l+r)/2+1, r, node*2+1));
    }
}

int main (){
    scanf("%d", &n);
    scanf("%d", &m);

    while(cnt < n){
        cnt *= 2;
    }
    for(int i = cnt; i < 2*cnt; i++){
        tree1[i] = 1234567890;
        tree2[i] = -1;
    }
    for(int i = 0; i < n; i++){
        scanf("%d", tree1+cnt+i);
        tree2[cnt+i] = tree1[cnt+i];
    }
    
    for(int i = cnt-1; i > 0; i--){
        tree1[i] = min(tree1[i*2], tree1[i*2+1]);
        tree2[i] = max(tree2[i*2], tree2[i*2+1]);
    }
    while(m--){
        scanf("%d %d", &a, &b);
        printf("%d %d\n",f1(a,b,1,cnt,1), f2(a,b,1,cnt,1));
    }
}

