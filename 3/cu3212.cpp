#include <bits/stdc++.h>
using namespace std;

vector<int> vec[201];
priority_queue<int> qu;
int v, n, a, b, connect[201], wh, visited[201], ans, printarr[201], fl;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> v >> n;
    for(int i = 0; i < n; i++){
        cin >> a >> b;
        vec[a].push_back(b);
        connect[b]++;
    }

    for(int i = 1; i <= v; i++){
        sort(vec[a].begin(), vec[a].end());
    }

    for(int i = 1; i <= v; i++){
        if(!connect[i]){
            qu.push(-i);
            visited[i] = 1;
        }
    }
    
    while(!qu.empty()){
        wh = -1 * qu.top();
        printarr[++ans] = wh;
        qu.pop();
        for(int i = 0; i < vec[wh].size(); i++){
            if(!visited[vec[wh][i]]){
                connect[vec[wh][i]]--;
                if(connect[vec[wh][i]] == 0){
                    qu.push(-1 * vec[wh][i]);
                    visited[vec[wh][i]] = visited[wh] + 1;
                }
            }
        }
    }
    for(int i = 1; i <= v; i++){
        if(connect[i]){
            fl = 1;
            break;
        }
    }

    if(fl) cout << "-1\n";
    else{
        for(int i = 1; i <= v; i++){
            cout << printarr[i] << '\n';
        }
    }
}