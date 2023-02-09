#include <bits/stdc++.h>
using namespace std;

map<string, int> mp;
int g[200020], cnt, t, m;
int size_[200020];
string s1, s2;

int find(int v){
    if(g[v] == v)   return v;
    return g[v] = find(g[v]);
}

bool Same(int a, int b){
    return find(a) == find(b);
}

void unite(int l, int r){
    if(Same(l,r)){
        cout << size_[g[l]] << "\n";
        return;
    }
    int ll = find(l);
    int rr = find(r);
    
    if(ll > rr){
        g[ll] = rr;
        size_[rr] += size_[ll];
        cout << size_[rr] << "\n";
    }
    else{
        g[rr] = ll;
        size_[ll] += size_[rr];
        cout << size_[ll] << "\n";
    }
    
}


int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    cin >> t;
    while(t--){
        cin >> m;
        for(int i = 0; i < 2*m; i++){
            g[i] = i;
            size_[i] = 1;
        }
        cnt = 0;
        while(m--){
            cin >> s1 >> s2;
            if(mp.count(s1) == 0){
                mp[s1] = cnt;
                cnt++;
            }
            if(mp.count(s2) == 0){
                mp[s2] = cnt;
                cnt++;
            }
            unite(mp[s1], mp[s2]);
        }
        mp.erase(mp.begin(), mp.end());
    }
}