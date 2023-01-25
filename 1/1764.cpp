#include <bits/stdc++.h>
using namespace std;

map<string, int> mp;
list<string> ls;
string x;
int ans, n, m;

int main(){
    cin >> n >> m;
    
    for(int i = 0; i < n; i++){
        cin >> x;
        mp[x] = 1;
    }

    for(int i = 0; i < m; i++){
        cin >> x;
        if(mp[x] == 1){
            ans++;
            ls.push_back(x);
        }
    }
    ls.sort();
    cout << ans << '\n';
    int si = ls.size();
    for(int i = 0; i < si; i++){
        cout << ls.front() << '\n';
        ls.pop_front();
    }
}