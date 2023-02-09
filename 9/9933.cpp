#include <bits/stdc++.h>
using namespace std;

map<string, bool> d;
int n, ans;
string s;


int main(){
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> s;
        string tmp = s;
        reverse(tmp.begin(),tmp.end());
        if(s==tmp || d[tmp]){
            cout << s.length() << " " << s[s.length()/2];
            break;
        }
        else{
            d[s] = true;
        }
    }
    return 0;
}