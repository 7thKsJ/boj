// solved_9836kb_36ms_571b

#include <bits/stdc++.h>
using namespace std;

struct conf{
    int s, e; //start, end, length
};

int n, ans;
conf d[1000001];

bool conf_cmp(conf a, conf b){
    if(a.e == b.e){
        return a.s < b.s;
    }
    return a.e < b.e;
}

int main (){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d %d", &d[i].s, &d[i].e);
    }

    sort(d, d+n, conf_cmp);
    int last_end_time = 0;
    for(int i = 0; i < n; i++){
        if(d[i].s >= last_end_time){
            ans++;
            last_end_time = d[i].e;
        }
    }
    printf("%d", ans);
}