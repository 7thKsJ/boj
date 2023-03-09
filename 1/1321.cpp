#include <bits/stdc++.h>
using namespace std;

int op, n, cnt = 1, tree[2000000], m, x, y;

void printTree(){
    for(int i = 1; i < 2*cnt; i++){
        cout << tree[i] << ',';
    }
    cout << endl;
}

void renewal(int t, int k){
    tree[t] += k;
    t = t/2;
    while(t > 0){
        tree[t] = tree[t*2] + tree[t*2+1];
        t = t/2;
    }
    //printTree();

}

int find (int node, int val, int l, int r){
    //cout << node << ' ' << val << ' ' << tree[node*2] << ' ' << l << ' ' << r << endl;
    if(l == r){
        return l;
    }
    int cmp = tree[node*2];
    int m = (l+r)/2;
    if(cmp < val){
        find(node*2+1, val-cmp, m+1, r);
    }
    else{
        find(node*2, val, l, m);
    }
}

int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    while(n > cnt){
        cnt *= 2;
    }
    for(int i = cnt; i < 2*cnt; i++){
        tree[i] = 0;
    }
    for(int i = 0; i < n; i++){
        cin >> tree[i+cnt];
    }
    for(int i = cnt-1; i > 0; i--){
        tree[i] = tree[i*2] + tree[i*2+1];
    }
    //printTree();
    cin >> m;
    while(m--){
        cin >> op;
        if(op == 1){
            cin >> x >> y;
            renewal(cnt + x - 1, y);
        }
        else{
            cin >> x;
            cout << find(1, x, 1, cnt) << endl;
        }
    }
}