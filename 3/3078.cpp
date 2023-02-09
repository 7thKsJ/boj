#include <bits/stdc++.h>
using namespace std;

string S;
queue<long long int> q[21];
long long int n, k, ans;

int main (){
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> S;
        long long int len = S.length();
        while(!q[len].empty() && i-q[len].front() > k){
            q[len].pop();
        }
        ans += q[len].size();
        q[len].push(i);
    }
    cout << ans;
}