// solved_1884kb_44ms_845b

#include <stdio.h>
#include <queue>
using namespace std;

priority_queue<int, vector <int>, less <int> > pq_sm;
priority_queue<int, vector <int>, greater <int> > pq_la;

int main (){
    int n, pq_la_size = 0, pq_sm_size = 0, a;
    scanf("%d", &n);
    while(n--){
        scanf("%d", &a);
        if(pq_sm_size == 0){
            pq_sm_size++;
            pq_sm.push(a);
        }
        else if(pq_la_size == pq_sm_size){
            pq_sm_size++;
            pq_sm.push(a);
        }
        else{
            pq_la_size++;
            pq_la.push(a);
        }

        if(pq_la_size != 0 &&pq_la.top() < pq_sm.top()){
            int temp1 = pq_la.top();
            int temp2 = pq_sm.top();
            pq_sm.pop(), pq_la.pop();
            pq_sm.push(temp1), pq_la.push(temp2);
        }

        printf("%d\n", pq_sm.top());
    }
}

/*
less 이지만 최대 힙이고 
greater 이지만 최소 힙이다.
최대 힙에는 작은거, 최소 힙에는 큰거를 넣어서 가운데를 게속 찾으면 될 것이다.
*/