#include <bits/stdc++.h>
using namespace std;

vector<int> v[100010];
int n, visited[100010], a, b;

void dfs(int x, int parent){
    visited[x] = parent;
    for(int i = 0; i < v[x].size(); i++){
        int ne = v[x][i];
        if(!visited[ne]){
            dfs(ne, x);
        }
    }
}

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n-1; i++){
        scanf("%d %d", &a, &b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1, 1);
    for(int i = 2; i <= n; i++){
        printf("%d\n", visited[i]);
    }
}