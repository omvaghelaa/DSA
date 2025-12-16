#include <iostream>
using namespace std;

void insertHeap(int arr[], int &n, int key) {
   
    n = n + 1;
    arr[n] = key; 

 
    int i = n;
    while (i > 1) {
        int parent = i / 2;
        if (arr[parent] < arr[i]) {
            swap(arr[parent], arr[i]);
            i = parent;
        } else {
            break;
        }
    }
}

void deleteHeap(int arr[], int &n) {
    if (n == 0) {
        cout << "Heap is empty!\n";
        return;
    }

    cout << "Deleted element: " << arr[1] << endl;

    arr[1] = arr[n];
    n = n - 1;

    int i = 1;
    while (true) {
        int left = 2 * i;
        int right = 2 * i + 1;
        int largest = i;

        if (left <= n && arr[left] > arr[largest])
            largest = left;
        if (right <= n && arr[right] > arr[largest])
            largest = right;

        if (largest == i)
            break;

        swap(arr[i], arr[largest]);
        i = largest; 
    }
}

void printHeap(int arr[], int n) {
    for (int i = 1; i <= n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[100];
    int n = 0;

    insertHeap(arr, n, 50);
    insertHeap(arr, n, 30);
    insertHeap(arr, n, 40);
    insertHeap(arr, n, 10);
    insertHeap(arr, n, 60);
    insertHeap(arr, n, 55);

    cout << "Heap before deletion: ";
    printHeap(arr, n);

    deleteHeap(arr, n);
    cout << "Heap after deletion: ";
    printHeap(arr, n);

    return 0;
}
