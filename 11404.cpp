// solved_1156kb_36ms_52173999_896b

#include <stdio.h>
#include <algorithm>
using namespace std;
#define MAXL 1E9

int arr[101][101];
int n,m,a,b,c;

int main (){
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            arr[i][j] = MAXL;
        }
    }

    for(int i = 0; i < m; i++){
        scanf("%d %d %d", &a, &b, &c);
        if(arr[a][b] == MAXL)   arr[a][b] = c;
        else    arr[a][b] = min(arr[a][b], c);
    }
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            for(int k = 1; k <= n; k++){
                if(j != k)  arr[j][k] = min(arr[j][i] + arr[i][k], arr[j][k]);
            }
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(arr[i][j] == MAXL){
                printf("0 ");
            }
            else printf("%d ", arr[i][j]);
        }
        puts("");
    }
}