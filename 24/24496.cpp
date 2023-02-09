#include <bits/stdc++.h>
using namespace std;

long long int a[101], b[101], t, n, m = 1000000001, flag = -1;

int main (){
    scanf("%lld", &t);
    while(t--){
        scanf("%lld", &n);
        flag = -1;
        for(int i = 0; i < n; i++){
            scanf("%lld", a+i);
            m = min(m,a[i]);
        }
        for(int j = 0; j < n; j++){
            a[j] -= m+1;
        }
        for(int i = m; i >= 0; i--){
            for(int j = 0; j < n; j++){
                b[j] = ++a[j];
            }
            int cnt = 0;
            for(int j = 0; j < n-1; j++){
                if(b[j] > b[j+1]){
                    cnt = -1;
                    break;
                }
                cnt += 2*b[j];
                b[j+1] -= b[j];
                b[j] -= b[j];
            }
            if(b[n-1] == 0){
                flag = cnt;
                break;
            }
        }
        printf("%d\n", flag);
    }
}