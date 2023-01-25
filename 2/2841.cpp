#include <bits/stdc++.h>
using namespace std;

stack<int> st[7];
int n, p, a, b, ans;

int main(){
    scanf("%d %d", &n, &p);
    
    for (int i = 0; i < n; i++){
        scanf("%d %d", &a, &b);
        if(st[a].empty()) {
            st[a].push(b);
            ans++;
        }
        else if(st[a].top() < b) {
            st[a].push(b);
            ans++;
        }
        else if(st[a].top() > b) { 
            while(st[a].top()>b){
                st[a].pop();
                ans++;
                if(st[a].empty()) { 
                    st[a].push(b);
                    ans++;
                }
            }

            if(st[a].top() < b){ 
                st[a].push(b);
                ans++;
            }
        }
    }

    printf("%d", ans);
    return 0;
}
