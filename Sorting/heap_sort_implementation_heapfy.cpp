#include<iostream>
using namespace std;

void heapfy(int arr[],int n,int i){
    int largest = i;  
    int left = i*2+1;  
    int right = i*2 + 2;

    if(left<n && arr[largest] < arr[left]){
        largest = left;
    }
    if(right<n && arr[largest] < arr[right]){
        largest = right;
    }

    if(largest != i){
        swap(arr[largest],arr[i]);
        heapfy(arr,n,largest);
    }
}

void buildHeap(int arr[],int n){
    for(int i=(n/2)-1;i>=0;i--){
        heapfy(arr,n,i);
    }
}

void printheap(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

void heapsort(int arr[],int n){
    buildHeap(arr,n);
    for(int i=n-1;i>0;i--){
        swap(arr[0],arr[i]);
        heapfy(arr,i,0);
    }
}

int main(){
    int arr[] = {9,4,10,12,13};
    buildHeap(arr,5);

    cout<<"Print : ";
    printheap(arr,5);

    cout<<endl<<"After Heapsort : ";
    heapsort(arr,5);
    printheap(arr,5);
    return 0;
}