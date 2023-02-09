#include <bits/stdc++.h>
using namespace std;
#define INF 987654321

int n, m, st, u, v, w, d[20020], visited[20020];
vector<pair<int, int>> vec[20020];
priority_queue<pair<int, int>> pq;

int main (){
    scanf("%d %d", &n, &m);
    scanf("%d", &st);

    while(m--){
        scanf("%d %d %d", &u, &v, &w);
        vec[u].push_back({v,w});
    }

    for(int i = 1; i <= n; i++){
        d[i] = INF;
        visited[i] = 0;
    }
    d[st] = 0;
    pq.push({0,st});

    while(!pq.empty()){
        int curr = pq.top().second;
        int val = -pq.top().first;
        //printf("{%d %d}, ",curr, val);
       if(visited[curr] == 1) continue;
        pq.pop();
       // visited[curr] = 1;
        for(int i = 0; i < vec[curr].size(); i++){
            int nex = vec[curr][i].first; ///정점 
            int nexval = vec[curr][i].second; ///가중치 
            ///visited[nex] == 0 &&
            if( visited[nex] == 0 && d[nex] > d[curr]+nexval){
                d[nex] = d[curr]+nexval;
                pq.push({-d[nex],nex});
            }
        }
    }

    for(int i = 1; i <= n; i++){
        if(d[i] == INF) printf("INF\n");
        else            printf("%d\n",d[i]);
    }
}