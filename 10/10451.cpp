#include <bits/stdc++.h>
using namespace std;

int t, n, a[1010], cnt, visited[1010], ans;

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    cin >> t;
    while(t--){
        cnt = 0, ans = 0;
        cin >> n;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }

        while(cnt != n){
            int i = 0;
            for(i = 1; i <= n; i++){
                if(!visited[i]) break;
            }
            int ptr = a[i];
            if(ptr == i){
                ans++;
                cnt++;
                visited[i] = 1;
            }
            else{
                visited[i] = 1;
                visited[ptr] = 1;
                cnt += 1;
                while(ptr != i){
                    ptr = a[ptr];
                    visited[ptr] = 1;
                    cnt++;
                }
                ans++;
            }
        }
        cout << ans << "\n";
        for(int i = 1; i <= n; i++){
            visited[i] = 0;
        }
    }
}