// solved_2100kb_4ms_53944367_434b

#include <bits/stdc++.h>
using namespace std;

int n, m, arr[20020], cnt;

int main (){
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++){
        scanf("%d", arr+i);
    }

    sort(arr, arr+n);

    int l = 0, r = n-1, s = 0;

    while(l != r){
        s = arr[l] + arr[r];
        if(m > s)       l++;
        else if (m < s) r--;
        else{
            cnt++;
            r--;
        }
    }
    printf("%d", cnt);
}