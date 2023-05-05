#include <bits/stdc++.h>
using namespace std;

long long int d = 9223372036854733;
string sa, sb;
vector <long long int> va[1501];
vector <long long int> vb[1501];
long long int prime[26] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101};


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> sa >> sb;
    for(int i = 0; i < sa.length(); i++){
        long long int x = 1, cnt = 1;
        for(int j = i; j < sa.length(); j++){
            x = (x+d) % d;
            x *= prime[sa[j]-'a'];
            x %= d;
            va[cnt].push_back(x);
            cnt++;
            //cout << i << ' ' << j << ' ' << x << ' ' << cnt << '\n';
        }
    }
    for(int i = 0; i < sb.length(); i++){
        long long int x = 1, cnt = 1;
        for(int j = i; j < sb.length(); j++){
            x = (x+d) % d;
            x *= prime[sb[j]-'a'];
            x %= d;
            vb[cnt].push_back(x);
            cnt++;
            //cout << i << ' ' << j << ' ' << x << ' ' << cnt << '\n';
        }
    }

    for(int i = min(sb.length(), sa.length()); i > 0; i--){
        for(int j = 0; j < va[i].size(); j++){
            for(int k = 0; k < vb[i].size(); k++){
                //cout << i << ' '  << j << ' ' << k << ' ' << va[i][j] << ' ' << vb[i][k] << '\n';
                if(va[i][j] == vb[i][k]){
                    cout << i <<'\n';
                    return 0;
                }
            }
        }
    }
    cout << 0;
    return 0;
}