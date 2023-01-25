#include <bits/stdc++.h>
using namespace std;

map<string, int> mp;
string x;
int ans;

int main(){
    cin >> x;
    
    for(int i = 0; i < x.length(); i++){
        for(int j = i; j < x.length(); j++){
            string y = x.substr(i, j-i+1);
            if(mp[y] == 0){
                mp[y] = 1;
                ans++;
            }
        }
    }
    
    cout << ans;
}