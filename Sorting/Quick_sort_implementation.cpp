#include<iostream>
using namespace std;

int partition(int arr[],int lb,int up){
    int pivot = arr[lb];
    int start = lb;
    int end = up;

    while(start<end){
    while(arr[start]<=pivot && up>start){
        start++;
    }
    while(arr[end] > pivot){
        end--;
    }
    if(start<end){
        swap(arr[end],arr[start]);
    }
}
    swap(arr[lb],arr[end]);
    return end;
}

void quick(int arr[],int lb,int up){
    if(lb<up){
        int loc = partition(arr,lb,up);
        quick(arr,lb,loc-1);
        quick(arr,loc+1,up);
    }
}

int main(){
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    quick(arr, 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}