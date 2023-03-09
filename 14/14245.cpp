#include <bits/stdc++.h>
using namespace std;

int arr[500050], tree[2000020], n, lazy[2000020], k, cnt;
int op, s, e, v, x;

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

void pro(int l, int r, int node){
    tree[node] = tree[node] ^ lazy[node];
    if(l != r){
        lazy[node*2] ^= lazy[node];
        lazy[node*2+1] ^= lazy[node];
    }
    lazy[node] = 0;
}

void renewal(int s, int e, int v, int l, int r, int node){
    cout << s << ' ' << e << ' ' << l << ' ' << r << endl;

    if(lazy[node])  pro(l,r,node);
    if(r < s || l > e)
        return;
    if(l >= s && r <= e){
        lazy[node] ^= v;
        pro(l,r,node);
        return;
    }
    renewal(s,e,v,l,(l+r)/2, node*2);
    renewal(s,e,v,(l+r)/2+1,r, node*2+1);
    tree[node] = tree[node*2] ^ tree[node*2+1];
}

int f(int s, int e, int l, int r, int node){
    if(lazy[node])  pro(l,r,node);
    if(s <= l && r <= e){
        return tree[node];
    }
    else if(r < s || l > e){
        return 0;
    }
    else{
        return f(s,e,l,(l+r)/2, node*2) ^ f(s,e,(l+r)/2+1, r, node*2+1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }
    cnt = 1;
    while(cnt < n){
        cnt *= 2;
    }

    cin >> k;
    while(k--){
        //printTree();
        cin >> op;
        if(op == 1){
            cin >> s >> e >> v;
            renewal(s+1,e+1,v,1,cnt,1);
        }
        else{
            cin >> x;
            x++;
            int k = f(x,x,1,cnt,1);
            cout << (arr[x] ^ k) << '\n';
        }
    }
}