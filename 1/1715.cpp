#include <bits/stdc++.h>
using namespace std;

priority_queue<int> pq;
int n, k, ans;

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &k);
        pq.push(-k);
    }

    while(pq.size() > 1){
        int a = -pq.top();
        pq.pop();
        int b = -pq.top();
        pq.pop();

        ans += a+b;
        pq.push(-a-b);
    }
    printf("%d", ans);
}