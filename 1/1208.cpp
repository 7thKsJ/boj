#include <bits/stdc++.h>
using namespace std;

int n, k, arr[41];
long long ans;
map<int, int> fr;

void front_dfs(int curr, int end, int sum){
    if(curr == end){
        fr[sum] += 1;
        return;
    }
    front_dfs(curr+1, end, sum);
    front_dfs(curr+1, end, sum + arr[curr]);
}

void end_dfs(int curr, int end, int sum){
    if(curr == end){
        if(fr[k-sum] > 0){
            ans += fr[k-sum];
        }
        else if (sum == k){
            ans += 1;
        }
        return;
    }
    end_dfs(curr+1, end, sum);
    end_dfs(curr+1, end, sum + arr[curr]);
}

int main (){
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i++){
        scanf("%d", arr+i);
    }
    int m = n/2;
    front_dfs(0,m,0); // m-1까지
    end_dfs(m,n,0);
    if(k == 0)  ans -= 1;
    
    printf("%d", ans);
}