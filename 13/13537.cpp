#include <bits/stdc++.h>
using namespace std;

int n, arr[100010], k, cnt = 1, s,e,v;
vector<int> tree[400040];

void makeTree(int s, int e, int node, int u, int v){
    if(u < s || e < u)  return;
    //cout << s << ' ' << e << ' ' << node << ' ' << u << '\n';

    tree[node].push_back(v);
    if(s != e){
        makeTree(s, (s+e)/2, node*2, u, v);
        makeTree((s+e)/2+1, e, node*2+1, u, v);
    }
}

int f(int s, int e, int v, int l, int r, int node){
    //cout << s << ' ' << e << ' ' << v << ' ' << l << ' '  << r << ' ' << node << '\n';
    if(s <= l && r <= e){
        //cout << lower_bound(tree[node].begin(),tree[node].end(),v) - tree[node].begin() << '\n';
        return tree[node].end()-upper_bound(tree[node].begin(),tree[node].end(),v);
    }
    else if (r < s || l > e){
        return 0;
    }
    else{
        return f(s,e,v,l,(l+r)/2,node*2) + f(s,e,v,(l+r)/2+1,r,node*2+1);
    }
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    while(cnt < n){
        cnt *= 2;
    }
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        makeTree(1,cnt,1,i,arr[i]);
    }

    for(int i = 1; i < 400040; i++)
        sort(tree[i].begin(), tree[i].end());


    cin >> k;
    while(k--){
        cin >> s >> e >> v;
        cout << f(s, e, v, 1, cnt, 1) << '\n';
    }
}