// solved_2020kb_0ms_481b

#include <bits/stdc++.h>
using namespace std;

long long int a, b, c, aa;

long long int f(long long int a, long long int b, long long int c){
    aa = 0;
    //printf("%lld %lld %lld\n", a, b, c);
    if(b == 1)   return a%c;
    else if(b % 2 == 0){
        aa = f(a, b/2, c);
        return (aa%c*aa%c)%c;
    }
    else{
        aa = f(a, b/2, c);
        return (aa%c*aa%c*a%c)%c;
    }
}

int main(){
    scanf("%lld %lld %lld", &a, &b, &c);
    printf("%lld", f(a, b, c));
}