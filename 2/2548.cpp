// solved_2100kb_4ms_53924421_212b

#include <bits/stdc++.h>
using namespace std;

int n, k[20010];

int main (){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", k+i);
    }
    sort(k, k+n);
    printf("%d", k[(n-1)/2]);
}