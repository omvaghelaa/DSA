#include<iostream>
#include<vector>
using namespace std;

void merge(int arr[],int lb,int mid,int up){
    int i = lb;
    int j = mid+1;
    vector<int> temp;

    while(i<=mid && j<=up){
        if(arr[i]<=arr[j]){
            temp.push_back(arr[i]);
            i++;
        }else{
            temp.push_back(arr[j]);
            j++;
        }
    }
    while(i<=mid){
        temp.push_back(arr[i]);
        i++;
    }
    while(j<=up){
        temp.push_back(arr[j]);

        j++;
    }
    for(int i=lb,k = 0; i<=up ;i++,k++){
        arr[i] = temp[k];
    }
}

void mergeSort(int arr[],int lb,int up){
    if(lb<up){
        int mid = (lb+up)/2;
        mergeSort(arr,lb,mid);
        mergeSort(arr,mid+1,up);
        merge(arr,lb,mid,up);
    }
}
int main(){
    int arr[] = {2,4,3,2,5,4};
    int size = sizeof(arr)/sizeof(arr[0]);

    mergeSort(arr,0,size-1);
    for(int s:arr){
        cout<<s<<" ";
    }
    return 0;
}