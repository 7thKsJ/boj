#include <bits/stdc++.h>
using namespace std;

int n, arr[1000010], ans, index_arr[1000010];
vector<int> vec, ansv;

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
            index_arr[i] = ans;
        }
        else if(i != 0){
            int ptr = lower_bound(vec.begin(),vec.end(),arr[i]) - vec.begin();
            vec[ptr] = arr[i];
            index_arr[i] = ptr+1;
        }
        else{
            ans++;
            vec.push_back(arr[i]);
            index_arr[i] = ans;
        }
    }
    cout << ans << endl;
//     for(int i = 0; i < n; i++){
//         cout << index_arr[i] << ", ";
//     }

    for(int i = n-1; i >= 0; i--){
        if(index_arr[i] == ans){
            ans--;
            ansv.push_back(arr[i]);
        }
    }
    for(int i = ansv.size()-1; i >= 0; i--){
        cout << ansv[i] << ' ';
    }
}