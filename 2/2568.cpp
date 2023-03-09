#include <bits/stdc++.h>
using namespace std;

int n, arr[100010], ans;
pair<int,int> gr[100010];
map<int, int> mp;
vector<int> vec, ansv;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> gr[i].first >> gr[i].second;
        mp[gr[i].second] = gr[i].first;
    }
    sort(gr, gr+n);
    for(int i = 0; i < n; i++){
        if(i != 0 && vec[vec.size()-1] < gr[i].second){
            vec.push_back(gr[i].second);
        }
        else if(i != 0){
            int ptr = lower_bound(vec.begin(),vec.end(),gr[i].second) - vec.begin();
            ans++;
            ansv.push_back(vec[ptr]);
            vec[ptr] = gr[i].second;
        }
        else{
            vec.push_back(gr[i].second);
        }
    }
    cout << ans << '\n';
    // for(int i = 0; i < ansv.size(); i++){
    //     cout << mp[ansv[i]] << '\n';
    // }
}