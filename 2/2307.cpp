#include <bits/stdc++.h>
using namespace std;
#define INF 987654321

int n, m, a, b, t, bc1, bc2, first = true;
vector<pair<int,int>> vec[1001];
int pre[1001], d[1001], visited[1001];

bool unlinked(int a, int b){
    if(bc1 == a && bc2 == b)    return true;
    else if (bc1 == b && bc2 == a)  return true;
    return false;
}

int dijkstra(int st){
    priority_queue<pair<int,int>> pq;

    for(int i = 1; i <= n; i++){
        d[i] = INF;
        visited[i] = 0;
    }
    d[st] = 0;
    pq.push({0,st});

    while(!pq.empty()){
        int curr = pq.top().second;
        int val = -pq.top().first;
        pq.pop();
        if(visited[curr] == 1) continue;
        
        visited[curr] = 1;
        for(int i = 0; i < vec[curr].size(); i++){
            int nex = vec[curr][i].first;
            if(unlinked(curr,nex))   continue;
            int nexval = vec[curr][i].second;
            if(visited[nex] == 0 && d[nex] > d[curr]+nexval){
                if(first)   pre[nex] = curr;
                d[nex] = d[curr]+nexval;
                pq.push({-d[nex],nex});
            }
        }
    }
    return d[n];
}

int main (){
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++){
        scanf("%d %d %d", &a, &b, &t);
        vec[a].push_back({b,t});
        vec[b].push_back({a,t});
    }

    pre[1] = 1;
    int time = dijkstra(1);
    first = false;

    int maxt = 0;
    for(int p = n; p != pre[p]; p = pre[p]){
        bc1 = p;
        bc2 = pre[p];
        maxt = max(maxt, dijkstra(1));
        if(maxt == INF) break;
    }
    if(maxt == INF) printf("-1");
    else printf("%d", maxt - time);
}