//deque

#include <bits/stdc++.h>
using namespace std;

deque<pair<int, int>> dq;
int n, l, x;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> l;
    for(int i = 0; i < n; i++){
        cin >> x;
        while(!dq.empty() && dq.front().second < i-l+1){
            dq.pop_front();
        }
        while(!dq.empty() && dq.back().first > x){
            dq.pop_back();
        }
        dq.push_back({x,i});

        cout << dq.front().first << ' ';
    }
}