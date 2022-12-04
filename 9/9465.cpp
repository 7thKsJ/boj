//solved_3972kb_132ms_47785722_669b;

#include <bits/stdc++.h>
using namespace std;

int arr[100001][2];
int dt[100001][3];
int n, m;

int main (){
    scanf("%d", &n);
    while(n--){
        scanf("%d", &m);
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < m; j++){
                scanf("%d", &arr[j][i]);
            }
        }
        dt[0][0] = 0; dt[0][1] = arr[0][0]; dt[0][2] = arr[0][1];
        for(int i = 1; i < m; i++){
            dt[i][1] = max(dt[i-1][0], dt[i-1][2]) + arr[i][0];
            dt[i][2] = max(dt[i-1][1], dt[i-1][0]) + arr[i][1];
            dt[i][0] = max(dt[i-1][1], dt[i-1][2]);
        }
        printf("%d\n", max(dt[m-1][1], dt[m-1][2]));
    }    
}

/*
3줄 조약돌
*/
// #include <bits/stdc++.h>
// using namespace std;

// int arr[301][4];
// int dt[301][5]; //(0,0,0)(1,0,0)(0,1,0)(0,0,1)(1,0,1)
// int n, m;

// int main (){
//     n = 1;
//     while(n--){
//         scanf("%d", &m);
//         for(int i = 0; i < 3; i++){
//             for(int j = 0; j < m; j++){
//                 scanf("%d", &arr[j][i]);
//             }
//         }
//         dt[0][0] = -60000; dt[0][1] = arr[0][0]; dt[0][2] = arr[0][1]; dt[0][3] = arr[0][2]; dt[0][4] = arr[0][0] + arr[0][2];
//         for(int i = 1; i < m; i++){
//             dt[i][0] = -60000;
//             dt[i][1] = max(dt[i-1][0], max(dt[i-1][2], dt[i-1][3])) + arr[i][0];
//             dt[i][2] = max(dt[i-1][0], max(dt[i-1][1], max(dt[i-1][3], dt[i-1][4]))) + arr[i][1];
//             dt[i][3] = max(dt[i-1][0], max(dt[i-1][2], dt[i-1][1])) + arr[i][2];
//             dt[i][4] = max(dt[i-1][0], dt[i-1][2]) + arr[i][0] + arr[i][2];
//         }
//         printf("%d\n", max(dt[m-1][1], max(dt[m-1][2], max(dt[m-1][3], dt[m-1][4]))));
//     }    
// }