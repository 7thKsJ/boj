#include <bits/stdc++.h>
using namespace std;

long long int arr[10010], ms1 = 90987654321, ms2 = 90987654321, v1, v2;
int n, x;

int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x;
        arr[x]++;
    }

    for(long long int i = 0; i <= 10000; i++){
        long long int tmps1 = 0;
        long long int tmps2 = 0;
        for(long long int j = 0; j <= 10000; j++){
            tmps1 += arr[j]*abs(i-j);
            tmps2 += arr[j]*(i-j)*(i-j);
        }
        if(ms1 > tmps1){
            ms1 = tmps1;
            v1 = i;
        }
        if(ms2 > tmps2){
            ms2 = tmps2;
            v2 = i;
        }
        cout << i << ' ' << tmps1 << ' ' << tmps2 <<'\n';
    }

    cout << v1 << ' ' << v2;
}