#include<iostream>
using namespace std;


int linearsearch(int arr[],int key,int n,int i){
    if(n == i){
        return -1;
    }
    if(arr[i] == key){
        return i;
    }
    linearsearch(arr,key,n,i+1);
}

int main(){
    int arr[5] = {1,27,3,5,7};
    cout<<linearsearch(arr,3,5,0);
    return 0;
}