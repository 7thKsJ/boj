// solved_2996kb_0ms_375b

#include <bits/stdc++.h>
using namespace std;

int zer, one;
char a[1000001];

int main (){
    scanf("%s", a);

    char bef = a[0];
    int i;

    for(i = 0; a[i]; i++){
        if(bef != a[i]){
            if(a[i] == '0') one++;
            else zer++;
        }
        bef = a[i];
    }
    if(a[i-1] == '0') zer++;
    else    one++;
    printf("%d", min(zer, one));
}