#include <bits/stdc++.h>
using namespace std;

map<string, int> mp;
int n, k, a;
string x;

int main (){
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> x >> a;
        mp[x] += a;
    }
    for(int i = 0; i < k; i++){
        cin >> x;
        cout << mp[x] << '\n';
    }
}