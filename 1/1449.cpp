// solved_2024kb_0ms_387b


#include <bits/stdc++.h>
using namespace std;

int n, k, d[1010];

int main (){
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i++){
        scanf("%d", d+i);
    }
    
    sort(d, d+n);

    int cnt = 0, ans = 0;
    while(cnt != n){
        ans++;
        int x = d[cnt];
        while(d[cnt] - x <= k-1 && cnt != n){
            cnt++;
        }
    }
    printf("%d", ans);
}