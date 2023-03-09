#include <bits/stdc++.h>
using namespace std;

long long int n, m, x, me, s,e,v, cnt = 1;
char op;
long long int tree[2000040], lazy[2000040], sal[2000020], re[2000020], fr[2000020];
vector<int> vec[500050];

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
	    lazy[node] += v;
        pro(l,r,node);
        return;
    }

    renewal(s,e,v, l, (l+r)/2, node*2);
    renewal(s,e,v, (l+r)/2+1, r, node*2+1);
    tree[node] = tree[node*2] + tree[node*2+1];
    return;
}


long long int f(long long int s, long long int e, long long int l, long long int r, long long int node){
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

void dfs(int n){
    fr[n] = ++e;
    for(int i = 0; i < vec[n].size(); i++){
        dfs(vec[n][i]);
    }
    re[n] = e;
}

int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    while(cnt < n){
        cnt *= 2;
    }
    for(int i = 1; i <= n; i++){
        cin >> sal[i];
        if(i != 1){
            cin >> me;
            vec[me].push_back(i);
        }
    }
    dfs(1);
    for(int i = 1; i <= n; i++){
        tree[cnt+fr[i]-1] = sal[i]; 
    }
    for(int i = cnt-1; i > 0; i--){
        tree[i] = tree[i*2] + tree[i*2+1];
    }
    for(int i = 0; i < m; i++){
        cin >> op;
        if(op == 'p'){
            cin >> s >> v;
            renewal(fr[s]+1, re[s], v, 1, cnt, 1);
        }
        else{
            cin >> s;
            cout << f(fr[s],fr[s],1,cnt,1) << '\n';
        }
    }
}