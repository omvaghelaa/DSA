#include <iostream>
using namespace std;

int binarySearch(int arr[], int size, int key) {
    int start = 0;
    int end = size - 1;

    while (start <= end) {
        int mid = (start+end)/2;  

        if (arr[mid] == key)
            return mid;  

        if (arr[mid] < key)
            start = mid + 1; 
        else
            end = mid - 1;  
    }

    return -1;  
}

int main() {
    int arr[] = {2, 4, 5, 6, 8, 9, 10};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 6;

    int result = binarySearch(arr, size, key);

    if (result != -1)
        cout << "Found at index: " << result;
    else
        cout << "Not found";

    return 0;
}
