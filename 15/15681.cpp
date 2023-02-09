#include <bits/stdc++.h>
using namespace std;

vector<int> vec[100010];
queue<int> qu;
int visited[100010], n, d[100010], r, q, u, v, f[100010], dt[100010];

void visit_clear(){
    for(int i = 0; i <= n; i++){
        visited[i] = 0;
    }
}

int solve(int x){
    //printf("--%d\n", x);
    visited[x] = 1;
    int retval = d[x];
    if(dt[x] != 0)  return dt[x];
    for(int i = 0; i < vec[x].size();i++){
        int next = vec[x][i];
        if(!visited[next] && f[x] < f[next]){
            retval += solve(next);
        }
    }
    return dt[x] = retval;
}
///tree dp 

int main (){
    scanf("%d %d %d", &n, &r, &q);
    for(int i = 0; i < n-1; i++){
        scanf("%d %d", &u, &v);
        vec[u].push_back(v);
        vec[v].push_back(u);  
    }
    qu.push(r);
    f[r] = 0;
    while(!qu.empty()){
        int t = qu.front();
        qu.pop();
        visited[t] = 1;
        for(int i = 0; i < vec[t].size(); i++){
            int next = vec[t][i];
            if(!visited[next]){
                qu.push(next);
                d[t]++;
                f[next] = f[t]+1;
            }
        }
    }
    // for(int i = 1; i <= n; i++){
    //     printf("%d, ",d[i]);
    // }
    
    visit_clear();
    solve(r);
    for(int i = 0; i < q; i++){
        scanf("%d", &u);
        printf("%d\n",dt[u]+1);
    }
}