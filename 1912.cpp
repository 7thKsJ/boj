// solved_1892kb_12ms_51219488_356b
#include <stdio.h>
#include <algorithm>

int n, ele[100001];
int dt[100001];

int main (){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", ele+i);
    }
    int ans = dt[0] = ele[0];
    for(int i = 0; i < n; i++){
        dt[i] = std::max(dt[i-1]+ele[i], ele[i]);
        ans = std::max(ans, dt[i]);
    }
    printf("%d", ans);
}