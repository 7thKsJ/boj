// solved_25476kb_356ms_29862759_873b

#include <bits/stdc++.h>
using namespace std;

int n, d, k, c, cnt;
int arr[3000030], l[3030], ca[3000030];

int main(){
    scanf("%d %d %d %d", &n, &d, &k, &c);
    for(int i = 0; i < n; i++){
        scanf("%d", arr+i);
    }
    
    l[c] = 1; cnt = 1;

    for(int i = 0; i < k; i++){
        if(l[arr[i]] == 0){
            cnt++;
        }
        l[arr[i]]++;

    }
    ca[0] = cnt;

    for(int i = 1; i < n; i++){
        ca[i] = ca[i-1];
        if(l[arr[(i-1)%n]] == 1){
            l[arr[(i-1)%n]]--;
            ca[i]--;
        }
        else l[arr[(i-1)%n]]--;

        if(l[arr[(i+k-1)%n]] == 0){
            l[arr[(i+k-1)%n]]++;
            ca[i]++;
        }
        else l[arr[(i+k-1)%n]]++;
    }

    int ans = 0;
    for(int i = 0; i < n; i++){
        ans = max(ans, ca[i]);
    }
    printf("%d", ans);
}