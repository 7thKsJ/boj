// 경로 한개를 찾고 거기에서 가장 긴 간선 한개를 빼면 된다.
#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> vec[1000010];
int visited[1000010], d[1000010], maxw[1000010], n, a, b, u, v, w;

void dfs(int v, int dist, int maxl){
    d[v] = dist;
    maxw[v] = maxl;
    visited[v] = 1;
    for(int i = 0; i < vec[v].size(); i++){
        int nex = vec[v][i].first;
        int nexv = vec[v][i].second;
        if(!visited[nex])   dfs(nex, nexv+dist, max(maxl,nexv));
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> a >> b;
    for(int i = 0; i < n-1; i++){
        cin >> u >> v >> w;
        vec[u].push_back({v,w});
        vec[v].push_back({u,w});
    }
    if(a == b){
        cout << "0";
        return 0;
    }

    dfs(a,0,0);
    cout << d[b] - maxw[b];
}

