#include <bits/stdc++.h>
using namespace std;

int c, n, arr[200020], l[200020], s, e, m, ans = -1;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> c;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr, arr+n);
    for(int i = 1; i < n; i++){
        l[i] = arr[i] - arr[i-1];
    }

    s = 1;
    e = arr[n-1] - arr[0];
    while(s <= e){
        //cout << s << ' ' << e << '\n';
        int cnt = 0;
        m = (s+e)/2;
        int st = arr[0];
        for(int i = 0; i < n; i++){
            if(arr[i] - st >= m){
                cnt++;
                st = arr[i];
            }
        }
        //cout << cnt << endl;
        if(cnt >= c - 1){
            ans = max(ans, m);
            s = m+1;
        }
        else{
            e = m-1;
        }
    }
    cout << ans;
}