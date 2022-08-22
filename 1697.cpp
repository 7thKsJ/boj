// solved_1456kb_0ms_48126281_690b

#include <stdio.h>
#include <queue>
using namespace std;
bool arr[100010];

queue<pair<int, int>> qu;
int dep, ari, ans=0;

void push_to_queue(int x, int d){
    if(x >= 0 && x <= 100010 && !arr[x])  {
        qu.push(make_pair(x, d));
        arr[x] += 1;
    }
}

int solve(){
    qu.push(make_pair(dep, 0));
    while(!qu.empty()){
        int x = qu.front().first;
        int y = qu.front().second;
        qu.pop();

        if(x == ari){
            ans = y;
            break;
        }

        push_to_queue(x+1,y+1);
        push_to_queue(x-1,y+1);
        push_to_queue(2*x,y+1);
    }
    return ans;
}

int main (){
    scanf("%d %d", &dep, &ari);
    printf("%d", solve());
}