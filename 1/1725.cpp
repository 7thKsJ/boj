#include <bits/stdc++.h>
using namespace std;

long long int n, ans, h[100010], cp;
stack<long long int> st;

int main(){
    scanf("%lld", &n);
    for(long long int i = 1; i <= n; i++){
        scanf("%d", h+i);
    }

    st.push(0);
    for(long long int i = 1; i <= n+1; i++){
        while(!st.empty() && h[st.top()] > h[i]){
            cp = st.top();
            st.pop();
            ans = max(ans, h[cp]*(i-st.top()-1));
        }
        st.push(i);
    }
    printf("%lld", ans);
}