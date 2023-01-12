// solved_1840kb_8ms_580b

#include <stdio.h>
#include <algorithm>

int len[305][305];
int arr[305][305], n, m;

int navi(int x, int y);

int main (){
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            scanf("%d", &arr[i][j]);
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            len[i][j] = -1;
        }
    }
    navi(n,m);

    printf("%d", len[n][m]);
}

int navi(int x, int y){

    if(len[x][y] != -1)   return len[x][y];
    return len[x][y] = std::max(navi(x, y-1), navi(x-1, y)) + arr[x][y];
}