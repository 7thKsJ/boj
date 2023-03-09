#include <bits/stdc++.h>
using namespace std;
#define ll long long int

#define md1 902611
#define md2 904861
#define pr1 17
#define pr2 11

ll hv1, hv2, t2int[1000010], p2int[1000010];
ll hk1, hk2, pow1[1000010], pow2[1000010];
string t, p;
vector<int> ans;
int cnt;

int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    getline(cin,t);
    for(int i = 0; i < t.size(); i++){
        t2int[i] = t[i];
        //cout << t2int[i] << ' ';
    }
    //cout << endl;
    getline(cin,p);
    for(int i = 0; i < p.size(); i++){
        p2int[i] = p[i];
        //cout << p2int[i] << ' ';
    }
    //cout << endl;
    pow1[0] = 1;
    pow2[0] = 1;
    for(int i = 1; i <= t.size(); i++){
        pow1[i] = (pow1[i-1]*pr1) %md1;
        pow2[i] = (pow2[i-1]*pr2) %md2;
        //cout << i << " : " << pow1[i] << ' '<< pow2[i] << '\n';
    }
    for(int i = p.size()-1; i >= 0; i--){
        hk1 += p2int[i]* pow1[p.size()-1-i];
        hk1 %= md1;
        hk2 += p2int[i]* pow2[p.size()-1-i];
        hk2 %= md2;
        //cout << i << " : "<<  hk1 << ' ' << hk2 << '\n';
    }
    cout << hk1 << ' ' << hk2 << '\n';

    for(int i = 0; i <= t.size()-p.size(); i++){
        if(i == 0){
            for(int j = 0; j < p.size(); j++){
                hv1 = hv1 + t2int[j]* pow1[p.size()-j-1];
                hv1 %= md1;
                hv2 = hv2 + t2int[j]* pow2[p.size()-j-1];
                hv2 %= md2;
            }
        }
        else{
            hv1 = hv1 - t2int[i-1]* pow1[p.size()-1] + md1* 1000;
            hv1 = (hv1) % md1;
            hv1 *= pr1;
            hv1 = (hv1) % md1;
            hv1 += t2int[i+p.size()];
            hv1 = (hv1+md1) % md1;
            hv2 -= t2int[i-1]* pow2[p.size()-1] + md2 * 1000;
            hv2 = (hv2) % md2;
            hv2 *= pr2;
            hv2 = (hv2) % md2;
            hv2 += t2int[i+p.size()];
            hv2 = (hv2+md2) % md2;
        }
        cout << i << " : " << hv1 << ' ' << hv2 << '\n';
        if(hv1 == hk1 && hk2 == hv2){
            cnt++;
            ans.push_back(i);
        }
    }
    cout << cnt << '\n';
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i]+1 << ' ';
    }
}