#include <bits/stdc++.h>
using namespace std;

int n, arr[1000010], ans;
vector<int> vec;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        if(i != 0 && vec[vec.size()-1] < arr[i]){
            vec.push_back(arr[i]);
            ans++;
        }
        else if(i != 0){
            int ptr = lower_bound(vec.begin(),vec.end(),arr[i]) - vec.begin();
            vec[ptr] = arr[i];
        }
        else{
            ans++;
            vec.push_back(arr[i]);
        }
    }
    cout << ans;
}