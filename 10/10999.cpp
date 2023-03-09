#include <bits/stdc++.h>
using namespace std;

long long int n, m, x, me, s,e,v , cnt = 1;
long long int tree[4000040], lazy[4000040];

void printTree(){
    for(int i = 1; i < 2*cnt; i++){
        printf("%d, ", tree[i]);
    }
    puts("");
    for(int i = 1; i < 2*cnt; i++){
        printf("%d, ", lazy[i]);
    }
    puts("");
}

void pro(int l,int r,int node){
	tree[node] += lazy[node]*(r-l+1);
	if(l != r){	
        lazy[node*2] += lazy[node];
	    lazy[node*2+1] += lazy[node];
    }	
    lazy[node] = 0;
}

void renewal(long long int s, long long e,long long int v, long long int l, long long int r, long long int node){
    if(lazy[node]!=0) pro(l,r,node);  
    if(r < s || l > e || s > e)
        return;
    if(l >= s && r <= e){
	    tree[node] += v*(r-l+1);
	    if(l != r){	
	        lazy[node*2] += v;
	        lazy[node*2+1] += v;
        }	
        return;
    }

    renewal(s,e,v, l, (l+r)/2, node*2);
    renewal(s,e,v, (l+r)/2+1, r, node*2+1);
    tree[node] = tree[node*2] + tree[node*2+1];
    return;
}


long long int f(long long int s, long long int e, long long int l, long long int r, long long int node){
   // printf("(%d %d), ", l, r);
    if(lazy[node] != 0) pro(l,r,node);

    if(s <= l && r <= e){
        return tree[node];
    }
    else if(r < s || l > e || s > e){
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
        //printTree();
        scanf("%lld", &x);
        if(x == 1){
            scanf("%lld %lld %lld", &s, &e, &v);
            renewal(s,e,v,1,cnt,1);
        }  
        else{
            scanf("%lld %lld", &s, &e);
            printf("%lld\n",f(s,e,1,cnt,1));
        }
    }
}