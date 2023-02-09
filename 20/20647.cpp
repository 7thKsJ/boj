#include <bits/stdc++.h>
using namespace std;

vector<int> v[100010];
queue<int> qu;
int n, visited[100010], a, b, par[100010], child[100010], ans;

void dfs(int x){
    visited[x] = 1;
    if(child[x] == 0)   return;
    int i = 0, c = 1;
    while(c <= child[x]){
        i++;
        c *= 2;
    }
    ans += i+child[x];
    for(int i = 0; i < v[x].size(); i++){
        int t = v[x][i];
        if(!visited[t]) dfs(t);
    }
    return;
}

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n-1; i++){
        scanf("%d %d", &a, &b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    qu.push(1);
    par[1] = 1;
    while(!qu.empty()){
        int x = qu.front();
        qu.pop();
        visited[x] = 1;
        for(int i = 0; i < v[x].size(); i++){
            int o = v[x][i];
            if(!visited[o]){
                qu.push(o);
                par[o] = x;
                child[x]++;
            }
        }
    }
    for(int i = 0; i <= n; i++){
        visited[i] = 0;
    }
    dfs(1);
    printf("%d", ans);
}