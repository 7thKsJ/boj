//pq

#include <bits/stdc++.h>
using namespace std;

priority_queue<pair<int, int>> pq;
int n, l, cnt, x;
stack<int> ans;
stack<pair<int,int>> st;

int main (){
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);

    cin >> n >> l;
    for(int i = 0; i < n; i++){
        cin >> x;
        st.push({-x,-i});
    }

    for(int i = n-l; i < n; i++){
        pq.push(st.top());
        st.pop();
    }

    for(int i = n-l; i > 0; i--){
        int lim = i+l-1;
        while(-pq.top().second > lim){
            pq.pop();
        }
        ans.push(-pq.top().first);
        pq.push(st.top());
        st.pop();
    }
    for(int i = l-1; i >= 0; i--){
        while(-pq.top().second > i){
            pq.pop();
        }
        ans.push(-pq.top().first);
    }
    while(!ans.empty()){
        cout << ans.top() << ' ';
        ans.pop();
    }

}
