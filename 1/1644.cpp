#include <bits/stdc++.h>
using namespace std;

int ls[4000040], n, s, ans;
vector<int> vec;

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);
    
    vec.push_back(0);
    cin >> n;
    for(int i = 2; i <= n; i++){
        if(ls[i] == 0){
            for(int j = 2*i; j <= n; j += i){
                ls[j] = 1;
            }
            //cout << i << '\n';
            s += i;
            //cout << s << '\n';
            vec.push_back(s);
        }
    }

    int l = 0, r = 1;
    while(r < vec.size()){
        //cout << l << ". " << r << endl;
        if(vec[r]-vec[l] > n){
            l = l+1;
        }
        else if(vec[r]-vec[l] < n){
            r = r+1;
        }
        else{
            l = l+1;
            ans++;
        }
    }
    cout << ans;
}