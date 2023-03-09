#include <bits/stdc++.h>
using namespace std;

int n, yz = -1, nz = -1;
string w, arr, y;

int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> w >> arr;
    y = w;
    int cnt = 0;
    for(int i = 0; i < n-1; i++){
        if(w[i] != arr[i]){
            cnt++;
            w[i] = arr[i];
            w[i+1] = (w[i+1] == '0') ? '1' : '0';
            if(i != n-2){
                w[i+2] = (w[i+2] == '0') ? '1' : '0';
            }
        }
    }
    if(arr[n-1] ==  w[n-1])  nz = cnt;

    cnt = 1;
    w = y;
    w[0] = w[0] == '0' ? '1' : '0';
    w[1] = w[1] == '0' ? '1' : '0';
    for(int i = 0; i < n-1; i++){
        if(w[i] != arr[i]){
            cnt++;
            w[i] = arr[i];
            w[i+1] = w[i+1] == '0' ? '1' : '0';
            if(i != n-2){
                w[i+2] = w[i+2] == '0' ? '1' : '0';
            }
        }
    }
    if(arr[n-1] == w[n-1])  yz = cnt;

    if(nz == -1 && yz == -1)        cout << "-1";
    else if (nz == -1 || yz == -1)  cout << max(nz, yz);
    else                            cout << min(nz, yz);
}
