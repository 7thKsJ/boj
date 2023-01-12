// solved_5928kb_64ms_336b

#include <bits/stdc++.h>
using namespace std;

int n, m, temp, a, b;
int sum_[1000001];

int main (){
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++){
        scanf("%d", &temp);
        sum_[i] = sum_[i-1] + temp;
    }
    
    while(m--){
        scanf("%d %d", &a, &b);
        printf("%d\n", sum_[b]-sum_[a-1]);
    }
}