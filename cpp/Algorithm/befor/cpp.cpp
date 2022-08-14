#include <stdio.h>
#include <algorithm>

int arr[1005], j;
void heapify(int k, int n);
void buildHeap(int n);
void heapSort(int n);

int main (){
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d", &arr[i]);
    }
    heapSort(n);
    for(int i = n; i >= 1; i--){
        printf("%d\n", arr[i]);
    }
}

void heapSort(int n){
    buildHeap(n);
    for(int i = n; i >= 2; i--){
        int temp = arr[i];
        arr[i] = arr[1];
        arr[1] = temp;
        heapify(1,i-1);
    }
}

void buildHeap(int n){
    for(int i = (n+1)/2; i >= 1; i--){
        heapify(i,n);
    }
}

void heapify(int k, int n){
    int left = 2*k;
    int right = 2*k+1;
    int smaller = 0;
    if(right <= n){
        if(arr[left] <= arr[right]) smaller = left;
        else smaller = right;
    }
    else if (left <= n) smaller = left;
    else return;

    if(arr[smaller] < arr[k]){
        int temp = arr[k];
        arr[k] = arr[smaller];
        arr[smaller] = temp;
        heapify(smaller, n);
    }
}