// solved_5220kb_4ms_47961737_1740b

#include <stdio.h>
#include <stack>
#include <queue>
using namespace std;

stack<int> st_temp;
stack<int> st;
int arr[1010][1010];
int to_do[1010];
int visited[1010];
int n,m;
int printZeroIm_Token = 1;

int printVisited(){
    for(int i = 1; i <= n; i++){
        printf("%d ", visited[i]);
    }
    printf("\n");
}

int printZeroIm(){
    return printZeroIm_Token;
}

void solve(int x, int flag){
    visited[x] = flag;
    // printf("%d %d : ", x, flag);
    // printVisited();
    for(int i = 1; i <= n; i++){
        if(visited[i] == 2){
            continue;
        }
        if(arr[x][i] && visited[i] == flag-1){
            solve(i, flag);
        }
        else if (arr[x][i] && visited[i] == flag && flag == 1){
            printZeroIm_Token = 0;
        }
    }
    st.push(x);
    visited[x] = 2;
}

int findFirst(){
    for(int i = 1; i <= n; i++){
        if(visited[i] == 0){
            solve(i, 1);
            // while(!st_temp.empty()){
            //     st.push(st_temp.top());
            //     st_temp.pop();
            // }
            return 1;
        }
    }
    return 0;
}

int main (){
    scanf("%d %d", &n, &m);
    while(m--){
        int a, k, p;
        bool fi = false;
        scanf("%d", &a);
        while(a--){
            scanf("%d", &k);
            if(!fi) fi = true;
            else {
                if(arr[p][k] == 0){
                    arr[p][k] = 1;
                    to_do[k]++;
                }
            }
            p = k;
        }
    }
    while(findFirst()){
        if(!printZeroIm()){
            printf("0");
            return 0;
        }
    }
    while(!st.empty()){
        printf("%d\n", st.top());
        st.pop();
    }
}

/*
visited의 1,2 활용과 stack에 집어넣는 동작을 유심하게 살펴보면 될 것이다.
*/