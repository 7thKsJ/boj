#include <bits/stdc++.h>
using namespace std;

struct cl{
    int s,t;
};

bool operator<(cl a, cl b){
    if(a.s == b.s)   return a.t < b.t;
    return a.s < b.s;
}

void print(cl a){
    printf("(%d, %d)\n", a.s, a.t);
}

int n, s, t;
priority_queue<cl> pq1;
priority_queue<cl> pq2;


int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d %d", &s, &t);
        pq1.push({s,t});
    }

    for(int i = 0; i < n; i++){
        cl x = pq1.top();
        pq1.pop();
        if(pq2.empty()){
            pq2.push(x);
        }
        else{
            cl y = pq2.top();
            if(x.s >= y.t){
                pq2.pop();
                pq2.push(x);
            }
            else{
                pq2.push(x);
            }
        }
    }
    printf("%d", pq2.size());
}