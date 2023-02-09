#include <bits/stdc++.h>
using namespace std;

int n, m, a[25], ans;

void f(int x, int sum){
    if(x == n){
        if(sum == m) ans++;
    }  
    if(x <= n){
        f(x+1, sum);
        f(x+1, sum+a[x]);
    }
}

int main (){
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++){
        scanf("%d", a+i);
    }
    f(0,0);
    if(m == 0)  ans--;
    printf("%d\n", ans);
}
