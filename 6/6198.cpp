#include <bits/stdc++.h>
using namespace std;

long long int n, k, ans;
stack<long long int> st;

int main(){
    scanf("%lld", &n);
    for(int i = 0; i < n; i++){
        scanf("%lld", &k);
        while(!st.empty() && k >= st.top()){
            printf("%lld popped\n", st.top());
            st.pop();
        }
        st.push(k);
        ans += st.size()-1;
        printf("%lld : %d add %lld\n", k, st.size()-1, ans);
    }
    printf("%lld", ans);
}
