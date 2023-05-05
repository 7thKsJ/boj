#include <bits/stdc++.h>
using namespace std;

int n,m,a,b;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    while(m--){
        cin >> a >> b;
        if(a > b){
            if(n - a + 1 + b >= a - 1)  printf("1\n");
            else printf("0\n");
        }
        else if(b > a){
            if(n - b + 1 + a >= b)  printf("1\n");
            else printf("0\n");
        }
        else{
            printf("1\n");
        }
    }
}