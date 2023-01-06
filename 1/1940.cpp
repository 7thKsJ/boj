#include <bits/stdc++.h>
using namespace std;

int n, k, d[20020], visited[20020], cnt;

int main(){
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i++){
        scanf("%d", d+i);
    }

    sort(d, d+n);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            if(visited[j])  continue;
            
            int x = d[i] + d[j];
            if(x > k)   break;
            if(x == k){
                visited[i] = visited[j] = 1;
                cnt++;
                break;
            }
        }
    }
    printf("%d", cnt);
}