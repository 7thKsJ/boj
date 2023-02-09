#include <bits/stdc++.h>
using namespace std;

int n;
long long ans[3], arr[5001];

int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr, arr+n);

    long long minv = 3987654321;
    for(int i = 0; i < n-2; i ++){
        int l = i+1, r = n-1;
        while(l<r){
            long long sumv = arr[i] + arr[l] + arr[r];
            if(abs(minv) > abs(sumv)){
                ans[0] = arr[i];
                ans[1] = arr[l];
                ans[2] = arr[r];
                minv = sumv;
            }
            if(sumv > 0) r--;
            else if (sumv < 0)  l++;
            else{
                for(int i = 0; i < 3; i++){
                    cout << ans[i] << ' ';
                }
                return 0;
            }
        }
    }
    for(int i = 0; i < 3; i++){
        cout << ans[i] << ' ';
    }
    return 0;
}