#include <bits/stdc++.h>
using namespace std;

int n, a[110], visited[110];
vector<int> v;

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    int i = 0;
    for(i = 1; i <= n; i++){
        if(visited[i]) continue;
        if(a[i] == i){
            visited[i] = 2;
        }
        else{
            int ptr = i;
            while(!visited[ptr]){
                visited[ptr] = 1;
                ptr = a[ptr];
            }
            if(ptr != i || ptr == a[ptr]) visited[ptr] = 2;
        }
    }

    
    for(int i = 1; i <= n; i++){
        if(visited[i] == 2){
            int ptr = a[i];
            v.push_back(i);
            while(ptr != i){
                v.push_back(ptr);
                ptr = a[ptr];
            }
        }
    }
    
    sort(v.begin(), v.end());
    cout << v.size() << "\n";
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << "\n";
    }

}