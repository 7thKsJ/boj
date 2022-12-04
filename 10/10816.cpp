//solved_40176kb_432ms_47727256_1153b

#include <stdio.h>
#include <algorithm>
int arr[10000001];
int n,m;

int UpperBound(int key, int lo, int hi);
int LowerBound(int key, int lo, int hi);

int main (){
    scanf("%d", &m);
    for(int i = 0; i < m; i++){
        scanf("%d", &arr[i]);
    }
    std::sort(arr, arr+m);
    // for(int i = 0; i < m; i++){
    //     printf("%d ", arr[i]);
    // }
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        int a;
        scanf("%d", &a);
        printf("%d ", UpperBound(a, 0, m) - LowerBound(a, 0, m));
    }
}

int UpperBound(int key, int lo, int hi){
    while(lo < hi){
        int mid = (lo + hi) / 2;
        if(arr[mid] <= key) lo = mid + 1;
        else hi = mid;
    }
    return hi + 1;
}

int LowerBound(int key, int lo, int hi){
    while(lo < hi){
        int mid = (lo + hi)/2;
        if(arr[mid] < key)  lo = mid + 1;
        else hi = mid;
    }
    return hi + 1;
} 
/*
Lower Bound와 Upper Bound에 대해서 알아보아야 할 것이다.

Lower Bound : key 이상인 값이 처음 나오는 위치 찾기. 
즉 값이 작아질때까지 간 다음에 체킹하면 된다.

반대로 Upper Bound를 진행하면 됨.
*/