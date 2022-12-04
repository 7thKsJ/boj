#include <bits/stdc++.h>
#define m 10007
int arr[1002];

int f(int k)
{
    if(arr[k]) return arr[k];
    if(k < 2)
    {
        return 1;
    }
    return arr[k] = (f(k-1) + 2 * f(k-2)) % m; 
}
int main ()
{
    int n;
    scanf("%d",&n);
    printf("%d",f(n));
}