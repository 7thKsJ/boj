// solved_3004kb_260ms_47788820_573b

#include <bits/stdc++.h>
using namespace std;

int arr[502][2];
int dt[501][501], n;

int rMatrixChain(int i, int j){
    if (dt[i][j])   return dt[i][j];
    if (i == j) return dt[i][j] = 0;
    int min = 1E9;
    for(int k = i; k < j; k++){
        int q = rMatrixChain(i,k) + rMatrixChain(k+1, j) + arr[i][0] * arr[k][1] * arr[j][1]; 
        if (q < min)    min = q;
    }
    return dt[i][j] = min;
}

int main (){
    scanf("%d", &n);
    int i = 0;
    while(i++ != n){
        scanf("%d %d", &arr[i][0], &arr[i][1]);
    }
    printf("%d",rMatrixChain(1,n));
    
}