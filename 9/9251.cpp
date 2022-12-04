// solved_6008kb_12ms_47789803_670b

#include <bits/stdc++.h>

char a[1002], b[1002];
int len[1010][1010];
int len_a, len_b;

int Lcs(int m, int n);

int main (){
    scanf("%s", a+1);
    scanf("%s", b+1);
    for(len_a = 1; a[len_a] !='\0'; len_a++);
    for(len_b = 1; b[len_b] !='\0'; len_b++);
    for(int i = 0; i < len_a; i++){
        for(int j = 0; j < len_b; j++){
            len[i][j] = -1;
        }
    }
    printf("%d",Lcs(len_a-1, len_b-1));
}

int Lcs(int m, int n){
    if(len[m][n] != -1)   return len[m][n];
    if(m == 0 || n == 0)    return len[m][n] = 0;
    else if(a[m] == b[n])   return len[m][n] = Lcs(m-1,n-1)+1;
    else return len[m][n] = std::max(Lcs(m-1, n), Lcs(m, n-1));
}