// solved_1896kb_64ms_53551237_417b

#include <stdio.h>
#include <algorithm>

struct st{
    int a, b;
};

int n;
st arr[100000];

bool cmp(st x, st y){
    if(x.a == y.a)  return x.b < y.b;
    return x.a < y.a;
}

int main (){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d %d", &arr[i].a, &arr[i].b);
    }

    std::sort(arr, arr+n, cmp);

    for(int i = 0; i < n; i++){
        printf("%d %d\n", arr[i].a, arr[i].b);
    }
}