#include <iostream>
using namespace std;

int linearsearch(int arr[], int size, int key) {
    for (int i = 0; i < size; i++) {  
        if (arr[i] == key) {
            return i;  
        }
    }
    return -1;  
}

int main() {
    int arr[] = {2, 4, 5, 6, 8, 9, 10};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 6;

    int index = linearsearch(arr, size, key);
    if (index != -1)
        cout << "Found at index: " << index;
    else
        cout << "Not found";

    return 0;
}
