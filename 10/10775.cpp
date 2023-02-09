#include <bits/stdc++.h>
using namespace std;

int g[100010], gn, pn, arr[100010], ans;
int Find(int v)
{
    if (g[v] == v)  return v;
    return g[v] = Find(g[v]);
}

void Union(int l, int r)
{
    int ll = Find(l);
    int rr = Find(r);

    if (ll > rr)    g[ll] = rr;
    else            g[rr] = ll;
}

int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> gn >> pn;
    for(int i = 0; i <= gn; i++) g[i] = i;
    for(int i = 0; i < pn; i++){
        cin >> arr[i];
    }

    for(int i = 0; i < pn; i++){
        int pt = Find(arr[i]);
        if(pt != 0){
            Union(pt, pt-1);
            //cout << pt << endl;
            ans++;
        }
        else{
            break;
        }
    }
    cout << ans;
}


// TLE code (Brute Force)
// #include <bits/stdc++.h>
// using namespace std;

// int g, p, arr[100010], cnt, visited[100010], limit = 0;

// int main (){
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);

//     cin >> g >> p;
//     for(int i = 0; i < p; i++){
//         cin >> arr[i];
//     }

//     for(int i = 0; i < p; i++){
//         int fl = 0;
//         if(visited[arr[i]] == 0){
//             visited[arr[i]] = 1;
//             fl = 1;
//             //cout << arr[i] << fl << '\n';
//         }
//         else{
//             int ptr = arr[i];
//             while(visited[ptr] == 1){
//                 ptr--;
//                 fl = 2;
//                 //cout << arr[i] << fl << '\n';
//             }
//             visited[ptr] = 1;
//             if(ptr == 0){
//                 fl = 3;
//                 //cout << arr[i] << fl << '\n';
//                 limit = i;
//                 break;
//             }
//         }
//         limit = i+1;
//     }
//     cout << limit << '\n';
// }