#include <stdio.h>
#include <algorithm>

#define int long long

int n, m, max_c = 1000001, max_val = 0, min_tu;
int arr[100000];

bool cmp(int a, int b){ return a > b;   }

main (){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%lld", arr+i);
    }
    std::sort(arr,arr+n, cmp);

    int t, mem_t, val;

    for(int i = 0; i < n; i++){
        t = arr[i];        
        val = (i+1)*t;
        if (val >= max_val){
            max_val = val;
            min_tu = t;
        }
    }

    printf("%lld %lld", max_val, min_tu);
}