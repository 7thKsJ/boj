#include <bits/stdc++.h>
using namespace std;

int v, maxDist, maxNode, a, b, c;
vector<pair<int,int>> vec[10010];
bool visited[10010];

void dfs(int k, int dist){
    visited[k] = true;
    if(maxDist < dist){
        maxDist = dist;
        maxNode = k;
    }
    for(int i = 0; i < vec[k].size(); i++){
        int nex = vec[k][i].first;
        int nexv = vec[k][i].second;
        if(!visited[nex])   dfs(nex, nexv+dist);
    }
}

int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> v;
    for(int i = 0; i < v-1; i++){
        cin >> a >> b >> c;
        vec[a].push_back({b,c});
        vec[b].push_back({a,c});
    }

    dfs(1,0);
    for(int i = 0; i <= v; i++){
        visited[i] = 0;
    }
    maxDist = 0;
    dfs(maxNode, 0);
    cout << maxDist << '\n';
    return 0;
}