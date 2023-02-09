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

int n, x = 1, cnt = 1;
g arr[1000010];
int tree[4000020];

int query(int s, int e, int l, int r, int n){
    if(s > r || e < l){
        return 0;
    }
    if(s >= l && e <= r){
        return tree[n];
    }
    int m = (s+e)/2;
    return query(s,m,l,r,n*2) + query(m+1,e,l,r,n*2+1);
}

void renewal(int t, int k){
    tree[t] += k;
    t = t/2;
    while(t > 0){
        //printf("%d, ",t);
        tree[t] = tree[t*2] + tree[t*2+1];
        t = t/2;
    }
}

int main (){
    scanf("%d", &n);
    while(cnt < n){
        cnt *= 2;
    }
    //cout<<cnt;
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
        // printf("%d ", arr[i].b);
        int ind = arr[i].b;
        printf("%d\n", i - query(1,cnt,1,ind,1)+1);
        renewal(cnt+ind-1,1);
    }

}