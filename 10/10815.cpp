// solved_40172kb_312ms_47726089_797b

#include <cstdio>
#include <stdlib.h>
using namespace std;

int arr[10000001];
int main (){
    int n, m;
    scanf("%d", &m);
    while(m--){
        int flag = 0;
        scanf("%d", &n);
        if(n < 0)   flag = 10;
        else        flag = 1;

        arr[abs(n)] += flag;
    }
    scanf("%d", &n);
    while(n--){
        int flag_p = 0;
        scanf("%d", &m);
        if(m > 0)   flag_p = 1;

        if(arr[abs(m)] == 1){
            if(flag_p){
                printf("1 ");
            }
            else printf("0 ");
        }
        else if (arr[abs(m)] == 11){
            printf("1 ");
        }
        else if(arr[abs(m)] == 10){
            if(flag_p){
                printf("0 ");
            }
            else printf("1 ");
        }
        else printf("0 ");
    }
}