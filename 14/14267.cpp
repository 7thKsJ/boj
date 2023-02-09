#include <bits/stdc++.h>
using namespace std;

int n, m, i, w, tmp, ans[100010];
vector<int> vec[100010];

void dfs(int v){
    //cout << v << ' ' << w << endl;
    for(int i = 0; i < vec[v].size(); i++){
        int nex = vec[v][i];
        ans[nex] += ans[v];
        dfs(nex);
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> tmp;
        if(tmp == -1)   continue;
        vec[tmp].push_back(i);
    }
    for(int j = 0; j < m; j++){
        cin >> tmp >> w;
        ans[tmp] += w;
    }
    dfs(1);
    for(int i = 1; i <= n; i++){
        cout << ans[i] << ' ';
    }
}