#include <bits/stdc++.h>
using namespace std;

struct g{
    int a, b;
};

int cmp(g x, g y){
    if(x.a == y.a)   return x.b < y.b;
    return x.a < y.a;
}

int cmp2(g x, g y){
    if(x.b == y.b)   return x.a < y.a;
    return x.b < y.b;
}

int n, cnt[1000010], x;
g arr[1000010];

int main (){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        int t ;
        scanf("%d", &t);
        arr[i] = {i, t};
    }
    sort(arr,arr+n,cmp2);
    for(int i = 0; i < n; i++){
        //printf("%d, ", x);
        if(arr[i].b == arr[i+1].b){
            arr[i].b = x;
        }
        else{
            arr[i].b = x;
            x++;
        }
    }
    sort(arr,arr+n,cmp);
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i].b);
    }

}