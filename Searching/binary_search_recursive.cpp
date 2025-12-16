#include<iostream>
using namespace std;

int binay(int arr[],int start,int end,int n,int key){
    if(start>end){
        return -1;
    }
    int mid = (start+end)/2;
    if(arr[mid]==key){
        return mid;
    }
    if(arr[mid]>key){
        binay(arr,start,mid-1,n,key);
    }else{
        binay(arr,mid+1,end,n,key);
    }
}

int main(){
    int arr[4] = {1,2,5,8};
    cout<<binay(arr,0,4,4,8);
    return 0;
}