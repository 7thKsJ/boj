//prim,pq+vec (advanced)
#include <bits/stdc++.h>
using namespace std;
#define INF 987654321

int n, m, u, v, w, d[100010], visited[100010], ans, max_node = 0, max_node_val = 0;
vector<pair<int, int>> vec[100010];
priority_queue<pair<int, int>> pq;

int main (){
    scanf("%d %d", &n, &m);
    while(m--){
        scanf("%d %d %d", &u, &v, &w);
        vec[u].push_back(make_pair(v,w));
        vec[v].push_back(make_pair(u,w));
    }

    for(int i  = 0; i <= n; i++){
     //   d[i] = INF;
        visited[i] = 0;
    }
    pq.push({0,1});
    while(!pq.empty()){
        int x = pq.top().second;
       // cout << x << "\n";
        int y = -pq.top().first;
        pq.pop();
        if(visited[x] == 1) continue;

        visited[x] = 1;
        ans += y;
    
        for(int i = 0; i < vec[x].size(); i++){
            int newNode = vec[x][i].first;
            int cost = vec[x][i].second;
            if(visited[newNode]==0)
            {
                pq.push({-cost,newNode});
            }
        }
    }

    printf("%d", ans);
    return 0;
}