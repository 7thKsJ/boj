// solved_5224kb_4ms_47958910_1815b

#include <stdio.h>
#include <queue>
using namespace std;

queue<int> qu;
int arr[1010][1010];
int to_do[1010];
int visited[1010];
int n,m;

int check(){
    printf("_______________\n");
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            printf("%d ", arr[i][j]);
        }
        puts("");
    }
    puts("");
    for(int i = 1; i <= n; i++){
        printf("%d ", to_do[i]);
    }
    puts("");
    for(int i = 1; i <= n; i++){
        printf("%d ", visited[i]);
    }
    printf("\n_______________\n");
}

int solve(){
    int temp = 0;
    for(int i = 1; i <= n; i++){
        if(to_do[i] == 0){
            qu.push(i);
        }
    }
    while(!qu.empty()){
        int fr = qu.front();
        visited[fr] = ++temp;
        qu.pop();
        for(int i = 1; i <= n; i++){
            if(arr[fr][i] && visited[i] == 0){
                to_do[i]--;
                if(to_do[i] == 0){
                    qu.push(i);
                }
            }
        }
    }
    for(int i = 1; i <= n; i++){
        if(to_do[i] > 0){
            return 0;
        }
    }
    return 1;
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
    int flag = solve();
    if(flag){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(visited[j] == i){
                    printf("%d\n", j);
                    break;
                }
            }
        }
    }
    else{
        printf("0");
    }
}