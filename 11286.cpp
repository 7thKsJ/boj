// solved_1552kb_20ms_47729650_1156b

#include <cstdio>
#include <queue>
using namespace std;

priority_queue <int, vector <int>, less <int>> mi;
priority_queue <int, vector<int>, greater<int>> pl;

int main (){
    int n, a;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &a);
        if(a > 0){
            pl.push(a);
        }
        else if (a < 0){
            mi.push(a);
        }
        else{
            if(!mi.empty()){
                if(!pl.empty()){
                    int a = -1 * mi.top();
                    int b = pl.top();
                    if(a <= b){
                        printf("%d\n", -1*a);
                        mi.pop();
                    }
                    else{
                        printf("%d\n", b);
                        pl.pop();
                    }
                }
                else{
                    printf("%d\n", mi.top());
                    mi.pop();
                }
            }
            else{
                if(!pl.empty()){
                    printf("%d\n", pl.top());
                    pl.pop();
                }
                else printf("0\n");
            }
        }
    }
}