#include <bits/stdc++.h>
using namespace std;

int a[100010], b[100010], n, cnt;

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", a+i);
    }
    for(int i = 0; i < n; i++){
        scanf("%d", b+i);
    }

    for(int i = 0; i < n; i++){
        if(a[i] != b[i]){
            int x;
            for(x = i; x < n; x++){
                if(a[x] == b[i])    break;
            }
            int temp = a[x];
            for(int j = x-1; j >= i; j--){
                a[j+1] = a[j];
            }
            a[i] = temp;
            //printf("%d %d %d\n",i,x,a[i]);
            cnt++;
        }
    }
    printf("%d",cnt);
}