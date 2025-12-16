#include<iostream>
using namespace std;

void selection(int arr[],int n){
    for(int i=0;i<n-1;i++){
        int min = i;
        for(int j = i+1;j<n;j++){
            if(arr[j]<arr[min]){
                min = j;
            }
        }
        if(min != i){
            swap(arr[min],arr[i]);
        }
    }
}

int main(){
    int arr[] = {4,5,8,12,2,3};
    selection(arr,6);
    for(int s : arr){
        cout<<s<<" ";
    }
}