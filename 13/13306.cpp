#include <bits/stdc++.h>
using namespace std;

int n, q, a, b, x, c, d, cnt;
int g[200020], tree[200020], query[400020][3];
string ans[200020];

int Find(int v)
{
    if (g[v] == v)  return v;
    return g[v] = Find(g[v]);
}

void Union(int l, int r)
{
    int ll = Find(l);
    int rr = Find(r);

    if (ll > rr)    g[ll] = rr;
    else            g[rr] = ll;
}

void Same(int a,int b){
    if (Find(a) == Find(b)){    ans[cnt++] = "YES\n";  }
    else{   ans[cnt++] = "NO\n"; }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> q;
    for(int i = 2; i <= n; i++){
        cin >> tree[i];
    }
    for(int i = 1; i <= n; i++){
        g[i] = i;
    }
    for(int i = n+q-1; i > 0; i--){
        cin >> x;
        if(x == 0){
            cin >> b;
            a = 0;
        } 
        else {
            cin >> a >> b;
        }
        query[i][0] = x;
        query[i][1] = b;
        query[i][2] = a;
    }
    for(int i = 1; i <= n+q-1; i++){
        if(query[i][0] == 0){
            Union(tree[query[i][1]], query[i][1]);
        } 
        else{
            Same(query[i][1], query[i][2]);
        }
    }
    reverse(ans, ans+cnt);
    for(int i = 0; i < cnt; i++){
        cout << ans[i];
    }
}