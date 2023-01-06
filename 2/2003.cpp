// solved_2060kb_40ms_53617678_507b

#include <bits/stdc++.h>
using namespace std;

int n, k, temp, cnt;
int su[10010];

int main (){
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; i++){
        scanf("%d", &temp);
        su[i] = su[i-1] + temp;
    }

    for(int i = 1; i <= n; i++){
        for(int j = i; j >= 1; j--){
            int x = su[i] - su[j-1];
            if(x > k)   break;
            if(x == k){
                //printf("%d %d\n", j, i);
                cnt++;
            }
        }
    }
    printf("%d", cnt);
}