//Sparse table(희소테이블)
#include <bits/stdc++.h>
using namespace std;

int m, dt[22][300020], q, n, x;

int f(int n, int x){
    //cout << n << ' ' << x << '\n';
    int cnt = 0, tmp = 1;
    while(n >= tmp){
        tmp *= 2;
        cnt++;
    }
    tmp /= 2;
    cnt--;
    if(n == 0)  return x;
    return f(n-tmp,dt[cnt][x]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> m;
    for(int i = 1; i <= m; i++){
        cin >> dt[0][i];
    }

    cin >> q;
    for(int i = 1; i <= 20; i++){
        for(int j = 1; j <= m; j++){
            dt[i][j] = dt[i-1][dt[i-1][j]];
        }
    }
    for(int i = 0; i < q; i++){
        cin >> n >> x;
        cout << f(n,x) << '\n';
    }
}