// unsolved

#include <stdio.h>
#include <algorithm>

struct e{
    int val, ind;
};

int t, arr[100000]; // G : 1, H : 2;
int n, k, gcnt, hcnt, ans;
int g[100000], h[100000], visited[100000];
char giv[100001];

int retmax(int *gi, int n){
    int maxind = 0, maxval = -1;
    for(int i = 0; i < n; i++){
        if(maxval < gi[i] && visited[i] == 0){
            maxval = gi[i];
            maxind = i;
        }
    }
    return maxind;
}

void refreshArr(int *g, int op, int n, int k, int ty){
    for(int i = op-k; i <= op+k; i++){
        if(i >= 0 && i < n){
            if(arr[i] == ty){
                arr[i] = 0;
                for(int j = i-k; j <= i+k; j++){
                    if(j >= 0 && j < n) {
                        g[j] -= 1;
                    }
                }
            }
        }
    }
}

void reset(int n){
    for(int i = 0; i < n; i++){
        arr[i] = 0;
        g[i] = 0;
        h[i] = 0;
        visited[i] = 0;
    }
    gcnt = hcnt = ans = 0;
}

int main (){
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &n, &k);
        reset(n);
        scanf("%s", giv);
        for(int i = 0; i < n; i++){
            char a = giv[i];
            if(a == 'G'){
                arr[i] = 1;
                gcnt++;
            }
            else{
                arr[i] = 2;
                hcnt++;
            }

            for(int j = i-k; j <= i+k; j++){
                if (j >= 0 && j < n){
                    if(arr[i] == 1) g[j]++;
                    else h[j]++;
                }
            }
        }
        // printf("\nH: (%d)",hcnt);
        // for(int i = 0; i < n; i++){
        //     printf("%d, ",h[i]);
        // }
        // printf("\nG: (%d)",gcnt);
        // for(int i = 0; i < n; i++){
        //     printf("%d, ",g[i]);
        // }
        // puts("");

        while(gcnt != 0 || hcnt != 0){
            if (gcnt > hcnt){
                int op = retmax(g,n);
                visited[op] = 1;
                gcnt -= g[op];
                refreshArr(g,op,n,k,1);
                // printf("\nG: (%d)",gcnt);
                // for(int i = 0; i < n; i++){
                //     printf("%d, ",g[i]);
                // }
                // puts("");
                ans++;
            }
            else if (gcnt <= hcnt){
                int op = retmax(h,n);
                visited[op] = 2;
                hcnt -= h[op];
                //printf("op : %d", op);
                refreshArr(h,op,n,k,2);
                // printf("\nH: (%d)",hcnt);
                // for(int i = 0; i < n; i++){
                //     printf("%d, ",h[i]);
                // }
                // puts("");
                ans++;
            }
        }
        printf("%d\n",ans);
        for(int i = 0; i < n; i++){
            if(visited[i] == 0) printf(".");
            else if (visited[i] == 1)   printf("G");
            else printf("H");
        }
        puts("");
        
        reset(n);
    }
}