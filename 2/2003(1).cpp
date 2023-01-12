// solved_2060kb_0ms_53943552_414b
// two-pointer

#include <bits/stdc++.h>
using namespace std;

int n, m, a[10010], cnt;

int main (){
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++){
        scanf("%d", a+i);
    }

    int l = -1, r = -1, s = 0;

    while(r < n){
        if(s < m)       s += a[++r];
        else if (s > m) s -= a[++l];
        else if (s == m){
            cnt++;
            s -= a[++l];
        }
    }

    printf("%d", cnt);
}