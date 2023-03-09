#include <bits/stdc++.h>
using namespace std;

int n, arr[1010], s = 1;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr, arr+n);
    
    for(int i = 0; i < n; i++){
        if(s < arr[i]){
            break;
        }
        if(i == 0){
            s = 1;
        }
        s += arr[i];
    }
    cout << s << '\n';
}