// solved_48908kb_204ms_53557181_601b

#include <bits/stdc++.h>
using namespace std;

struct st{
    string name;
    int k, e, m;
};

int n;
st stu[1000000];

bool cmp(st x, st y){
    if(x.k == y.k){
        if(x.e == y.e){
            if(x.m == y.m){
                return x.name < y.name;
            }
            return x.m > y.m;
        }
        return x.e < y.e;
    }
    return x.k > y.k;
}

int main (){

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> stu[i].name >> stu[i].k >> stu[i].e >> stu[i].m;
    }

    sort(stu, stu+n, cmp);

    for(int i = 0; i < n; i++){
        cout << stu[i].name << '\n';
    }
}