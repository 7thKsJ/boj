#include <bits/stdc++.h>
using namespace std;

int n, k, b, arr[100100], pr[100100], fl;

int main (){
    scanf("%d %d %d", &n, &k, &b);
    for(int i = 0; i < n; i++){
        scanf("%d", arr+i);
    }

    for(int i = 0; i < n-1; i++){
        if(arr[i])  fl = 1;
        pr[i+1] = pr[i] + fl;
        fl = 0;
    }

    for(int i = 0; i <= n-k+1; i++){
        int x = pr[i+k}
    }

    
}