// solved_1112kb_12ms_47896173_434b

#include <stdio.h>
#include <algorithm>

int n,m;

int getValue(int st, int fi){
    if(st > fi){
        return st;
    }
    int mid_num = (st + fi)/2, sum_arr = 0;
    for(int i = 1; i <= n; i++){
        sum_arr += std::min(n,mid_num/i);
    }
    if(sum_arr < m){
        return getValue(mid_num+1, fi);
    }
    else return getValue(st, mid_num-1);
}

int main (){
    scanf("%d %d", &n, &m);
    printf("%d",getValue(1,m));
}
/*
Lower Bound 하면 된다
*/